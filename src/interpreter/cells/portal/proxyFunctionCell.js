import { Cell } from "../common/cell.js";

class ProxyFunctionCell extends Cell {
  /**
   * @param {Mavka} mavka
   * @param {function} fn
   */
  constructor(mavka, fn) {
    super(mavka, "<проксі функція>");

    this.fn = fn;
  }

  /**
   * @inheritDoc
   */
  doCall(context, args, options = {}) {
    return this.fn(args, context, options);
  }
}

export default ProxyFunctionCell;
