import Loader from "./loader.js";

class MemoryLoader extends Loader {
  constructor(mavka, modules = {}) {
    super(mavka);

    this.modules = modules;
  }

  async load(context, name, pak = false) {
    if (this.modules[name]) {
      return this.modules[name];
    } else {
      throw `[помилка] модуль ${name} не знайдено`;
    }
  }
}

export default MemoryLoader;
