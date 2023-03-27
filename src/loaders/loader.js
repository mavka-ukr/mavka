class Loader {
  constructor(mavka) {
    this.mavka = mavka;
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
   * @param {string[]} url
   */
  async loadRemote(context, url) {
  }
}

export default Loader;
