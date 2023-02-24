import { Cell } from "./cell.js";

class ModuleCell extends Cell {
  constructor(mavka, name, context) {
    super(mavka, "Модуль", {
      "__name__": name,
      "__context__": context
    });
  }

  get(name) {
    return this.getContext().get(name);
  }

  set(name, value) {
    throw "Cannot set on module.";
  }

  getContext() {
    return this.properties["__context__"];
  }

  getName() {
    return this.properties["__name__"];
  }

  asString() {
    return this.mavka.toCell(`модуль ${this.getName()}`);
  }
}

export default ModuleCell;
