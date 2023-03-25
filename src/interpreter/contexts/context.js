class Context {
  constructor(mavka, parent = null, vars = {}) {
    this.mavka = mavka;
    this.parent = parent;
    this.vars = vars;
    this.isAsync = false;
  }

  setAsync(isAsync) {
    this.isAsync = isAsync;
  }

  get(name) {
    if (name in this.vars) {
      return this.vars[name];
    }

    if (this.parent) {
      return this.parent.get(name);
    }

    this.mavka.fall(this, this.mavka.makeText(`"${name}" не знайдено в контексті.`));
  }

  set(name, value) {
    if (value == null) {
      console.trace(value);
      throw "fyck";
    }
    if (!(value instanceof this.mavka.Cell)) {
      console.trace(typeof value, name);
      throw "not cell";
    }
    this.vars[name] = value;
  }

  // has(name) {
  //   if (name in this.vars) {
  //     return true;
  //   }
  //
  //   if (this.parent) {
  //     return this.parent.has(name);
  //   }
  //
  //   return false;
  // }

  delete(name) {
    delete this.vars[name];
  }
}

export default Context;
