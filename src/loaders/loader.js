class Loader {
  constructor(mavka) {
    this.mavka = mavka;
  }

  /**
   * Load a module.
   *
   * @param {Context} context
   * @param {string[]} path
   * @param {boolean} pak
   * @param {boolean} relative
   */
  async load(context, path, pak = false, relative = false) {
  }
}

export default Loader;
