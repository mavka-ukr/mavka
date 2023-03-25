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
      () => this.meta.object,
      null,
      { object }
    );
  }

  /**
   * @inheritDoc
   */
  get(context, name) {
    let value = this.meta.object[name];
    if (typeof value === "function") {
      // do not lose context on call
      value = (...args) => this.meta.object[name](...args);
    }
    return this.mavka.toCell(value);
  }

  /**
   * @inheritDoc
   */
  set(context, name, value) {
    this.meta.object[name] = value ? value.asJsValue(context) : undefined;
  }
}

export default PortalCell;
