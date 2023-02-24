import Loader from "./loader.js";

class MemoryLoader extends Loader {
  constructor(mavka, modules = {}) {
    super(mavka);

    this.modules = modules;
  }

  async load(context, path, pak = false, relative = false) {
    for (let i = 0; i < path.length; i++) {
      const lpath = path.slice(0, i).join(".");

      if (this.modules[lpath]) {
        return this.modules[lpath];
      }
    }

    throw `Неможливо завантажити модуль "${path.join(".")}"`;
  }
}

export default MemoryLoader;
