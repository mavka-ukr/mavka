import Context from "./context.js";

class LightContext extends Context {
  set(name, value) {
    this.parent.vars[name] = value ?? this.mavka.emptyCellInstance;
  }

  setLocal(name, value) {
    this.vars[name] = value ?? this.mavka.emptyCellInstance;
  }
}

export default LightContext;
