import { ThrowValue } from "../instructions/throwInstruction.js";

class Context {
  constructor(mavka, parent = null, vars = {}) {
    this.mavka = mavka;
    this.parent = parent;
    this.vars = vars;
  }

  isAsync() {
    return !!this.vars.__async__;
  }

  setAsync(async) {
    this.set("__async__", async);
  }

  get(name) {
    if (name in this.vars) {
      return this.vars[name];
    }

    if (this.parent) {
      return this.parent.get(name);
    }

    throw new ThrowValue(this, `"${name}" не знайдено у контексті`);
  }

  set(name, value) {
    this.vars[name] = value;
  }

  delete(name) {
    delete this.vars[name];
  }

  call(name, args) {
    const diia = this.get(name);

    if (!diia) {
      throw new ThrowValue(this, `дію "${name}" не знайдено у контексті`);
    }

    return diia.call(this, args);
  }
}

export default Context;
