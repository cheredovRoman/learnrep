import BPB from "./BPB.js";
import FSInfo from "./FSInfo.js";
import Fat from "./Fat.js";
import FileStruct from "./FileStruct.js";
import DirectoryCluster from "./DirectoryCluster.js";

export default class Disk {
  constructor(size, sectorSize, clusterSize) {
    this.data = new Array(size / (sectorSize * clusterSize)).fill(0)
    this.data[0] = [new BPB(size, sectorSize, clusterSize)]
    this.data[0].push(new FSInfo())
    this.data[0].push(new Fat(this.getTotalSectors(), this.getSectorPerCluster()))
    this.data[1] = new FileStruct("\\", null, null, 2, 0, 0x10);
    this.data[2] = new DirectoryCluster(this.getSectorSize() * this.getSectorPerCluster(), "\\", 2)
  }

  getBPB = () => this.data[0][0]
  getFSInfo = () => this.data[0][1]
  getFat = () => this.data[0][2]

  getTotalSectors = () => this.getBPB().totalSectors;
  getSectorPerCluster = () => this.getBPB().sectorPerCluster;
  getSectorSize = () => this.getBPB().bytePerSector;
  findFirstEmptyCluster = (from = 3) => this.getFSInfo().firstEmptyCluster = this.getFat().findFirstEmptyCluster(from);
  countEmptyClusters = () => this.getFSInfo().emptyClustersNum = this.getFat().countEmptyClusters()

  parsePath(path) {
    return ["\\", ...path.split("\\").slice(1, -1)]
  }

  splitContent(content, size) {
    const clustersNum = Math.ceil(size / (this.getSectorSize() * this.getSectorPerCluster()))
    const chunkLen = Math.ceil(content.length / clustersNum)
    const chunks = []
    for (let i = 0; i < clustersNum; i++) {
      const end = chunkLen * (i + 1) > content.length ? content.length : chunkLen * (i + 1)
      chunks.push(content.slice(chunkLen * i, end))
    }
  
    return chunks
  }

  createFile({name, content, size, type, pathToDir}) {
    this.findFirstEmptyCluster()
    this.countEmptyClusters()

    const clustersNum = Math.ceil(size / (this.getSectorSize() * this.getSectorPerCluster()))
    if (clustersNum > this.getFSInfo().emptyClustersNum) {
      alert("Not enough disk space")
      return
    }
   
    const dirStruct = this.findDir(pathToDir)
    if (dirStruct === -1) return;

    if (dirStruct[dirStruct.length - 1].content.findIndex(f => f.name === name) !== -1) {
      alert("There is already such a file in this directory")
      return
    }

    let index = this.getFSInfo().firstEmptyCluster
    const ans = dirStruct[dirStruct.length - 1].addFile(new FileStruct(name, new Date(), new Date(), index, size, type))
    if (ans === 1) {
      alert("Not enough space in the directory")
      return
    }
    if (size<=content.length)
    {
      alert("out of space")
      return
    }
    const contentChunks = this.splitContent(content, size)
   
    let num = 0
    let remainingSize = size
    while (remainingSize > 0) {
      const nextFreeIndex = this.findFirstEmptyCluster(index + 1)

      const isLastCluster = remainingSize - this.getSectorSize() * this.getSectorPerCluster() <= 0
      this.getFat().data[index] = isLastCluster ? 0xFFFFFFFF : nextFreeIndex
      this.data[index] = contentChunks[num]

      num++
      index = nextFreeIndex
      remainingSize -= this.getSectorSize() * this.getSectorPerCluster()
    }
  }

  createDir({name, pathToDir}) {
    this.findFirstEmptyCluster()
    this.countEmptyClusters()

    if (this.getFSInfo().emptyClustersNum === 0) {
      alert("Not enough disk space")
      return
    }

    const dirStruct = this.findDir(pathToDir)
    if (dirStruct === -1) return;

    if (dirStruct[dirStruct.length - 1].content.findIndex(f => f.name === name) !== -1) {
      alert("There is already such a file in this directory")
      return
    }

    let index = this.getFSInfo().firstEmptyCluster
    const ans = dirStruct[dirStruct.length - 1].addFile(new FileStruct(name, new Date(), new Date(), index, 0, 0x10))
    if (ans === 1) {
      alert("Not enough space in the directory")
      return
    }
    this.getFat().data[index] = 0xFFFFFFFF
    this.data[index] = new DirectoryCluster(this.getSectorSize() * this.getSectorPerCluster(), name, index)
    this.data[index].addFile(new FileStruct("..", new Date(), new Date(), dirStruct[dirStruct.length - 1].cluster, 0, 0x01))
  }

  findDir(path = "\\") {
    const parsedPath = this.parsePath(path)
    const chain = [this.data[2]]

    for (let i = 1; i < parsedPath.length; i++) {
      const fileStruct = chain[i-1].content.find(str => str.name === parsedPath[i])
      if (fileStruct) {
        chain.push(this.data[fileStruct.firstCluster])
      }
      else {
        return -1
      }
    }

    return chain
  }

  readFile(name, pathToDir) {
    let content = ''
    let file = {}
    const dirStruct = this.findDir(pathToDir)
    if (dirStruct === -1) return;
    file = dirStruct[dirStruct.length - 1].content.find(f => f.name === name)

    let index = file.firstCluster
    while (true) {
      content = content + this.data[index]
      index = this.getFat().data[index]
     
      if (index === 0xFFFFFFFF) break
    }
    
    const clusters = this.getFat().getFileClusters(file.firstCluster)

    return {...file, content, clusters}
  }

  parseFiles(pathToDir = "\\") {
    const dirStruct = this.findDir(pathToDir)
    if (dirStruct === -1) return;
    return {files: dirStruct[dirStruct.length - 1].parse(), path: pathToDir}
  }

  removeFile(name, pathToDir) {
    const dirStruct = this.findDir(pathToDir)
    if (dirStruct === -1) return;
    const file = dirStruct[dirStruct.length - 1].content.find(file => file.name === name)
    dirStruct[dirStruct.length - 1].removeFile(name)

    let index = file.firstCluster

    while (true) {
      const tmp = index
      index = this.getFat().data[index]
      this.getFat().data[tmp] = 0
      if (index === 0xFFFFFFFF) break
    }
  }

  updateFile(name, pathToDir, data = {}) {
    const dirStruct = this.findDir(pathToDir)
    if (dirStruct === -1) return;
    const file = dirStruct[dirStruct.length - 1].content.find(file => file.name === name)

    if (data?.name || data?.content) file.wrtTime = new Date()

    if (data?.name) file.name = data.name
    if (data?.content) {
      let index = file.firstCluster

      while (true) {
        const tmp = index
        index = this.getFat().data[index]
        this.getFat().data[tmp] = 0
        if (index === 0xFFFFFFFF) break
      }

      this.findFirstEmptyCluster()
      index = this.getFSInfo().firstEmptyCluster

      file.firstCluster = index

      const contentChunks = this.splitContent(data.content, file.size)

      let num = 0
      let remainingSize = file.size
      while (remainingSize > 0) {
        const nextFreeIndex = this.findFirstEmptyCluster(index + 1)

        const isLastCluster = remainingSize - this.getSectorSize() * this.getSectorPerCluster() <= 0
        this.getFat().data[index] = isLastCluster ? 0xFFFFFFFF : nextFreeIndex
        this.data[index] = contentChunks[num]

        num++
        index = nextFreeIndex
        remainingSize -= this.getSectorSize() * this.getSectorPerCluster()
        if(file.size<=content.length)
        {
          alert("out of space")
          return
        }
      }
    }
  }
}
