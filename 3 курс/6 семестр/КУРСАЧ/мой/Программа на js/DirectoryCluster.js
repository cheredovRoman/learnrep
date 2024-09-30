export default class DirectoryCluster {
    constructor(size, name, cluster) {
      this.remainingSize = size
      this.name = name
      this.content = []
      this.cluster = cluster
    }
  
    removeFile(name) {
      const index = this.content.findIndex(file => file.name === name)
      if (index !== -1) {
        this.content[index].name = String.fromCharCode(0x0E5) + this.content[index].name.slice(1)
      }
    }
  
    addFile(file) {
      const indexOfFree = this.content.findIndex(file => file.name[0] === String.fromCharCode(0x0E5))
      if (indexOfFree === -1) {
        if (this.remainingSize < 32) return 1
        this.content.push(file)
        this.remainingSize -= 32
      }
      else {
        this.content[indexOfFree] = file
      }
  
      return 0
    }
  
    parse() {
      return this.content.map(file => ({
        dir: this.name,
        name: file.name,
        size: file.size,
        type: file.type,
        wrtTime: file.wrtTime,
      })).filter(file => file.name[0] !== String.fromCharCode(0x0E5))}
  }
  