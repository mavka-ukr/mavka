import { Cell } from "../common/cell.js";

/**
 * Portal to JS-object.
 */
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

  asBoolean(context) {
    return this.mavka.toCell(!!this.meta.object);
  }

  /**
   * @inheritDoc
   */
  get(context, name) {
    let value = this.meta.object[name];
    if (typeof value === "function") {
      const fn = value;
      const that = this.meta.object;
      // do not lose context on call
      value = (...args) => fn.call(that, ...args);
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
