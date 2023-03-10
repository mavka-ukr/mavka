import { Cell } from "./cell.js";

class ProxyCell extends Cell {
  constructor(mavka, object) {
    super(mavka, "Проксі");

    this.object = object;
  }

  get(name) {
    return this.mavka.toCell(this.object[name]);
  }

  set(name, value) {
    this.object[name] = value ? value.asJsValue() : undefined;
  }

  call(context) {
    throw new this.mavka.ThrowValue(this, this.mavka.toCell(`Неможливо викликати на Проксі.`));
  }

  asString() {
    return this.mavka.toCell("Проксі");
  }

  asJsValue() {
    return this.object;
  }

  asBoolean() {
    return this.mavka.toCell(true);
  }
}

export default ProxyCell;
