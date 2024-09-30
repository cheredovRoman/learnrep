export default class FileStruct {
    constructor(name, crtTime, wrtTime, cluster, size, type) {
      this.name = name;
      this.crtTime = crtTime;
      this.wrtTime = wrtTime;
      this.firstCluster = cluster;
      this.size = size;
      this.type = type;
    }
  }
  