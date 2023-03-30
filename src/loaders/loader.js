class Loader {
  constructor(mavka) {
    this.mavka = mavka;

    this.loadedRemoteModules = {};
  }

  /**
   * @param {Context} context
   * @param {string} path
   * @return {Promise<Buffer>}
   */
  async loadFile(context, path) {
  }

  /**
   * Load a module.
   *
   * @param {Context} context
   * @param {string[]} pathElements
   * @param {boolean} absolute
   */
  async loadModule(context, pathElements, absolute = false) {
  }

  /**
   * Load a pak.
   *
   * @param {Context} context
   * @param {string[]} pathElements
   */
  async loadPak(context, pathElements) {
  }

  /**
   * Load remote file.
   *
   * @param {Context} context
   * @param {string} url
   * @param {Object} options
   */
  async loadRemote(context, url, options = {}) {
  }
}

export default Loader;
