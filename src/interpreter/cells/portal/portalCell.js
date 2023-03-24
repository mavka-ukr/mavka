import { Cell } from "../common/cell.js";

class PortalCell extends Cell {
  /**
   * @param {Mavka} mavka
   * @param {Object} object
   */
  constructor(mavka, object) {
    super(
      mavka,
      "<портал>",
      {},
      null,
      () => this.object
    );

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
}

export default PortalCell;
