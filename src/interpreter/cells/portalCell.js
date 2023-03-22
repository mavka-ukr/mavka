import { Cell } from "./utils/cell.js";

class PortalCell extends Cell {
  constructor(mavka, object) {
    super(mavka, "<портал>");

    this.object = object;
  }

  get(name) {
    let value = this.object[name];
    if (typeof value === "function") {
      // do not lose context on call
      value = (...args) => this.object[name](...args);
    }
    return this.mavka.toCell(value);
  }

  set(name, value) {
    this.object[name] = value ? value.asJsValue(context) : undefined;
  }

  doCall(context) {
    throw new this.mavka.ThrowValue(this, this.mavka.toCell(`Неможливо викликати портал.`));
  }

  asJsValue(context) {
    return this.object;
  }

  asBoolean() {
    return this.mavka.toCell(true);
  }
}

export default PortalCell;
