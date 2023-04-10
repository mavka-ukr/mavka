import { Cell } from "../common/cell.js";

/**
 * Portal to JS-function.
 */
class PortalFunctionCell extends Cell {
  /**
   * @param {Mavka} mavka
   * @param {function} fn
   */
  constructor(mavka, fn) {
    super(
      mavka,
      "<портал функція>",
      {},
      mavka.diiaStructureCellInstance,
      () => this.meta.fn,
      null,
      { fn }
    );
  }

  /**
   * @inheritDoc
   */
  doCall(context, args, options = {}) {
    const jsArgs = Object.values(args)
      .map((v) => v.asJsValue(context));

    return this.mavka.toCell(this.meta.fn(...jsArgs));
  }
}

export default PortalFunctionCell;
