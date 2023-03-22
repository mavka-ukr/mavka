class Context {
  constructor(mavka, parent = null, vars = {}) {
    this.mavka = mavka;
    this.parent = parent;
    this.vars = vars;
  }

  isAsync() {
    return !!this.vars["__тривалий__"];
  }

  setAsync(async) {
    this.set("__тривалий__", async);
  }

  get(name) {
    if (name in this.vars) {
      return this.vars[name];
    }

    if (this.parent) {
      return this.parent.get(name);
    }

    throw new this.mavka.ThrowValue(this, `"${name}" не знайдено в контексті.`);
  }

  set(name, value) {
    this.vars[name] = value ?? this.mavka.emptyCellInstance;
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
