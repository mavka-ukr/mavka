class Scope {
  constructor(parent, vars = new Set()) {
    this.parent = parent;
    this.vars = vars;
    this.setters = vars;
  }

  has(name) {
    if (this.vars.has(name)) {
      return true;
    }
    if (this.parent) {
      return this.parent.has(name);
    }
    return false;
  }
}

export default Scope;
