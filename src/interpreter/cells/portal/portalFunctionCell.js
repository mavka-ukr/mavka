import { Cell } from "../common/cell.js";

class PortalFunctionCell extends Cell {
  /**
   * @param {Mavka} mavka
   * @param {function} fn
   */
  constructor(mavka, fn) {
    super(mavka, "<портал функція>");

    this.fn = fn;
  }

  /**
   * @inheritDoc
   */
  doCall(context, args, options = {}) {
    const jsArgs = Object.values(args).map((v) => v.asJsValue(context));

    return this.mavka.toCell(this.fn(...jsArgs));
  }
}

export default PortalFunctionCell;
