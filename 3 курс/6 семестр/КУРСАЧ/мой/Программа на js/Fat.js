export default class Fat {
    data = []
  
    constructor(sectorsNum, sectorsPerCluster) {
      this.data = new Array(sectorsNum / sectorsPerCluster).fill(0)
      this.data[0] = 0xFFFFF00
      this.data[1] = 0xFFFFFFFF
      this.data[2] = 0xFFFFFFFF
    }
  
    countEmptyClusters() {
      return this.data.reduce((acc, cluster) => {
        if (cluster === 0) acc++
        return acc
      }, 0)
    }
  
    findFirstEmptyCluster(from = 0) {
      for (let i = from; i < this.data.length; i++) {
        if (this.data[i] === 0) return i
      }
      return null
    }
  
    getFileClusters(startIndex) {
      if (this.data[startIndex] === 0xFFFFFFFF) return [startIndex]
      return [startIndex, ...this.getFileClusters(this.data[startIndex])]
    }
  }
  