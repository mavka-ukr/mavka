import Context from "./context.js";

class LightContext extends Context {
  set(name, value) {
    this.parent.vars[name] = value;
  }

  setLocal(name, value) {
    this.vars[name] = value;
  }
}

export default LightContext;
