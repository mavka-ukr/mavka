import { Cell } from "../common/cell.js";

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
