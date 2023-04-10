import { Cell } from "../common/cell.js";

/**
 * Operation that is not finished yet. Can be awaited in async context.
 */
class AsyncCell extends Cell {
  /**
   * @param {Mavka} mavka
   * @param {Promise|function} asyncOperation
   */
  constructor(mavka, asyncOperation) {
    super(
      mavka,
      "<триваюча операція>",
      {},
      null,
      () => this.meta.asyncOperation,
      null,
      { asyncOperation }
    );
  }
}

export default AsyncCell;
