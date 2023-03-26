class Context {
  /**
   * @param {Mavka} mavka
   * @param {Context|null} parent
   * @param {Record<string, Cell>} vars
   * @param {Cell} module
   */
  constructor(mavka,
              parent = null,
              vars = {},
              module = null) {
    this.mavka = mavka;
    this.parent = parent;
    this.vars = vars;
    this.isAsync = false;
    this.module = module;
  }

  /**
   * @param {boolean} isAsync
   */
  setAsync(isAsync) {
    this.isAsync = isAsync;
  }

  /**
   * @param {string} name
   * @return {Cell}
   */
  get(name) {
    if (name in this.vars) {
      return this.vars[name];
    }

    if (this.parent) {
      return this.parent.get(name);
    }

    this.mavka.fall(this, this.mavka.makeText(`"${name}" не знайдено в контексті.`));
  }

  /**
   * @param {string} name
   * @param {Cell} value
   */
  set(name, value) {
    this.vars[name] = value;
  }

  /**
   * @param {string} name
   * @param {Cell} value
   */
  setHigher(name, value) {
    const higherContext = this.getHigherContextForVar(name);

    if (higherContext) {
      higherContext.set(name, value);
    } else if (this.parent) {
      this.parent.set(name, value);
    } else {
      this.vars[name] = value;
    }
  }

  /**
   * @return {Cell}
   */
  getModule() {
    if (this.module) {
      return this.module;
    }

    if (this.parent) {
      return this.parent.getModule();
    }

    return null;
  }

  /**
   * @param {Cell} module
   */
  setModule(module) {
    this.module = module;
  }

  /**
   * @param {string} name
   * @param {Cell} value
   */
  give(name, value) {
    const module = this.getModule();
    if (module) {
      module.properties[name] = value;
    } else {
      this.mavka.fall(this, this.mavka.makeText(`Не знайдено модуля для надання ${name}.`));
    }
  }

  has(name) {
    if (name in this.vars) {
      return true;
    }

    if (this.parent) {
      return this.parent.has(name);
    }

    return false;
  }

  /**
   * @param {string} name
   */
  delete(name) {
    delete this.vars[name];
  }

  getHigherContextForVar(name) {
    if (this.parent) {
      if (name in this.parent.vars) {
        return this.parent;
      }

      return this.parent.getHigherContextForVar(name)
    }

    return null;
  }
}

export default Context;
