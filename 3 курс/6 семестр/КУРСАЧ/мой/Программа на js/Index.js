import Disk from "./Disk.js";
import {formatDate} from "./format.js";

let currentPath = "\\"

const disk = new Disk(131072, 512, 8)

disk.createDir({name: "My computer", pathToDir: currentPath})
disk.createFile({name: "Disk c", content: "Its disk c", size: 20480, type: 0x20, pathToDir: currentPath})
disk.createFile({name: "Disk d", content: "Its disk d", size: 36864, type: 0x20, pathToDir: currentPath})

updateTree()

function updateTree() {
  const {files, path} = disk.parseFiles(currentPath)
  renderList(files, path)
}

function renderInput(label, id, type = "text", value = "") {
  const lab = document.createElement("label")
  lab.setAttribute("for", id)
  lab.innerText = label
  const input = document.createElement("input")
  input.setAttribute("id", id)
  input.setAttribute("type", type)
  input.value = value
  return [lab, input]
}

function renderTextarea(label, id, className = "") {
  const lab = document.createElement("label")
  lab.setAttribute("for", id)
  lab.innerText = label
  const input = document.createElement("textarea")
  input.setAttribute("id", id)
  input.className = className
  return [lab, input]
}

function renderModal(path) {
  const modal = document.createElement("div")
  modal.className = "modal"
  const modalContent = document.createElement("modalContent")
  modalContent.className = "modal-content"
  modal.append(modalContent)
  const h = document.createElement("h3")
  h.innerText = "new file"
  modalContent.append(h)

  const form = document.createElement("div")
  form.className = "form"
  modalContent.append(form)

  form.append(...renderInput("Name file", "nameInput"))
  form.append(...renderInput("Size file (bites)", "sizeInput"))
  form.append(...renderTextarea("Content file", "contentInput", "file-content__text"))

  const actions = document.createElement("div")
  actions.className = "form__actions"
  form.append(actions)

  const back = document.createElement("button")
  back.innerText = "Cancel"
  back.addEventListener("click", (event) => {
    modals.innerHTML = ""
  })
  actions.append(back)

  const apply = document.createElement("button")
  apply.setAttribute("data-path", path)
  apply.innerText = "Create"
  apply.addEventListener("click", (event) => {
    const name = document.getElementById("nameInput").value
    const size = +document.getElementById("sizeInput").value
    const content = document.getElementById("contentInput").value
    if (name === "" || name === null) return
    if (size <= 0) return

    disk.createFile({name, content, size, type: 0x20, pathToDir: currentPath})
    modals.innerHTML = ""
    updateTree()
  })
  actions.append(apply)

  const modals = document.getElementById("modals")
  modals.innerHTML = ""
  modals.append(modal)
}

function renderDirectoryDialog(path) {
  const modal = document.createElement("div")
  modal.className = "modal"
  const modalContent = document.createElement("modalContent")
  modalContent.className = "modal-content"
  modal.append(modalContent)
  const h = document.createElement("h3")
  h.innerText = "New direction"
  modalContent.append(h)
  const form = document.createElement("div")
  form.className = "form"
  modalContent.append(form)

  form.append(...renderInput("Name direction", "dirNameInput"))

  const actions = document.createElement("div")
  actions.className = "form__actions"
  form.append(actions)

  const back = document.createElement("button")
  back.innerText = "Cancel"
  back.addEventListener("click", (event) => {
    modals.innerHTML = ""
  })
  actions.append(back)

  const apply = document.createElement("button")
  apply.setAttribute("data-path", path)
  apply.innerText = "Create"
  apply.addEventListener("click", (event) => {
    const name = document.getElementById("dirNameInput").value
    const path = event.target.getAttribute("data-path")

    if (name === "" || name === null) return

    disk.createDir({name, pathToDir: path})
    modals.innerHTML = ""
    updateTree()
  })
  actions.append(apply)

  const modals = document.getElementById("modals")
  modals.innerHTML = ""
  modals.append(modal)
}

function renderList(files, path) {
  const fileTree = document.getElementById("file-tree")
  fileTree.innerHTML = ""

  const pathElem = document.createElement("span")
  pathElem.className = "file-tree__path"
  pathElem.innerText = path
  fileTree.append(pathElem)

  const createButton = document.createElement("button")
  createButton.innerText = "New file"
  createButton.setAttribute("data-path", path)
  createButton.addEventListener("click", (event) => {
    renderModal(event.target.getAttribute("data-path"))
  })
  fileTree.append(createButton)

  const createDirButton = document.createElement("button")
  createDirButton.innerText = "New directory"
  createDirButton.setAttribute("data-path", path)
  createDirButton.addEventListener("click", (event) => {
    renderDirectoryDialog(event.target.getAttribute("data-path"))
  })
  fileTree.append(createDirButton)

  files.forEach(file => {
    const div = document.createElement('div')
    div.className = "file"

    const name = document.createElement('span')
    name.className = "file__name"
    name.innerText = file.name
    div.append(name)

    if (file.type !== 0x10) {
      const date = document.createElement('span')
      date.className = "file__wrt-time"
      date.innerText = formatDate(file.wrtTime)
      div.append(date)

      const size = document.createElement('span')
      size.className = "file__size"
      size.innerText = file.size + "Б"
      div.append(size)
    }

    div.setAttribute("name", file.name)

    div.addEventListener("click", (event) => {
      const name = event.target.getAttribute("name") || event.target.parentElement.getAttribute("name")

      const file = disk.readFile(name, currentPath)

      if (file.type === 0x10) {
        currentPath = currentPath + file.name + "\\"
        const {files, path} = disk.parseFiles(currentPath)
        renderList(files, path)
      } else if (file.name === "..") {
        currentPath = "\\" + currentPath.split("\\").slice(1, -2).join("\\")
        if (currentPath[currentPath.length - 1] !== "\\") currentPath = currentPath + "\\"
        const {files, path} = disk.parseFiles(currentPath)
        renderList(files, path)
      } else {
        renderFileInfo(file, currentPath)
        renderFileClusters(file)
      }
    })

    fileTree.append(div)
  })
}

function renderFileInfo(file, dir) {
  function getInfoLine(label, val) {
    const line = document.createElement('div')
    line.className = "info"
    const nameLabel = document.createElement('span')
    nameLabel.className = "info-name"
    nameLabel.innerText = label
    const nameValue = document.createElement('span')
    nameValue.className = "info-value"
    nameValue.innerText = val
    line.append(nameLabel, nameValue)
    return line
  }

  function getContentLine(label, val) {
    const line = document.createElement('div')
    line.className = "file-content"
    const labelElem = document.createElement("span")
    labelElem.className = "file-content__label"
    labelElem.innerText = label

    const valueElem = document.createElement("textarea")
    valueElem.className = "file-content__text"
    valueElem.value = val
    valueElem.setAttribute("id", "textAreaInfo")

    line.append(labelElem, valueElem)
    return line
  }

  const fileInfo = document.getElementById("file-info")
  fileInfo.innerHTML = ""

  const name = renderInput("Имя:", "nameInfo", "text", file.name)
  const crtTime = getInfoLine("Time of create:", formatDate(file.crtTime))
  const wrtTime = getInfoLine("Last change:", formatDate(file.wrtTime))
  const firstCluster = getInfoLine("First cluster:", file.firstCluster)
  const size = getInfoLine("Size:", file.size)
  const type = getInfoLine("Type:", file.type)
  const content = getContentLine("Content:", file.content)

  const addButton = document.createElement("button")
  addButton.innerText = "Save changes"
  addButton.addEventListener("click", event => {
    const data = {}
    const nameInValue = document.getElementById("nameInfo").value
    if (file.name !== nameInValue) data.name = nameInValue
    const contentInValue = document.getElementById("textAreaInfo").value
    if (file.content !== contentInValue) data.content = contentInValue
    disk.updateFile(file.name, dir, data)
   
    updateTree()
    const nfile = disk.readFile(nameInValue, dir)
    renderFileInfo(nfile, dir)
    renderFileClusters(nfile)
  })

  const removeButton = document.createElement("button")
  removeButton.innerText = "Delete file"
  removeButton.addEventListener("click", event => {
    disk.removeFile(file.name, dir)
    updateTree()
    clearFileInfo()
    clearClustersInfo()
  })

  fileInfo.append(...name, crtTime, wrtTime, firstCluster, size, type, content, addButton, removeButton)
}

function clearFileInfo() {
  const fileInfo = document.getElementById("file-info")
  fileInfo.innerHTML = ""
}

function clearClustersInfo() {
  const clustersInfo = document.getElementById("clusters-info")
  clustersInfo.innerHTML = ""
}

function renderFileClusters(file) {
  function renderCluster(index, indexInChain) {
    const cluster = document.createElement('div')
    cluster.className =  indexInChain !== -1 ? "cluster cluster_full" : "cluster"
    cluster.innerText = index
    if (indexInChain !== -1) {
      const span = document.createElement("span")
      span.className = "cluster__index-in-chain"
      span.innerText = indexInChain
      cluster.append(span)
    }
    return cluster
  }

  const clustersInfo = document.getElementById("clusters-info")
  clustersInfo.innerHTML = ""

  const clustersGrid = document.createElement("div")
  clustersGrid.className = "clusters"

  for (let i = 0; i < disk.data.length; i++) {
    const cluster = renderCluster(i, file.clusters.indexOf(i))
    clustersGrid.append(cluster)
  }

  clustersInfo.append(clustersGrid)
}
