import { Cell } from "./cell.js";

class ModuleCell extends Cell {
  constructor(mavka, name, context) {
    super(mavka, "Модуль");

    this.name = name;
    this.context = context;
  }

  get(name) {
    return this.context.get(name);
  }

  set(name, value) {
    throw "Неможливо записувати в модуль.";
  }

  asString() {
    return this.mavka.toCell(`модуль ${this.name}`);
  }
}

export default ModuleCell;
