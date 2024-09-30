export default class BPB {
    constructor(size, sectorSize, clusterSize) {
      this.bytePerSector = sectorSize
      this.sectorPerCluster = clusterSize
      this.totalSectors = size / sectorSize
    }
  }
  