import { Cell } from "../common/cell.js";

class PortalCell extends Cell {
  /**
   * @param {Mavka} mavka
   * @param {Object} object
   */
  constructor(mavka, object) {
    super(mavka, "<портал>");

    this.object = object;
  }

  /**
   * @inheritDoc
   */
  get(context, name) {
    let value = this.object[name];
    if (typeof value === "function") {
      // do not lose context on call
      value = (...args) => this.object[name](...args);
    }
    return this.mavka.toCell(value);
  }

  /**
   * @inheritDoc
   */
  set(context, name, value) {
    this.object[name] = value ? value.asJsValue(context) : undefined;
  }

  /**
   * @inheritDoc
   */
  doCall() {
    throw new this.mavka.ThrowValue(this, this.mavka.makeText("Неможливо викликати портал."));
  }

  /**
   * @inheritDoc
   */
  asJsValue() {
    return this.object;
  }

  /**
   * @inheritDoc
   */
  asBoolean() {
    return this.mavka.toCell(true);
  }
}

export default PortalCell;
