import { Cell } from "../common/cell.js";

class AwaitCell extends Cell {
  /**
   * @param {Mavka} mavka
   * @param {Cell|AsyncCell} cellToAwait
   */
  constructor(mavka, cellToAwait) {
    super(
      mavka,
      "<await>",
      {},
      null,
      null,
      null,
      { cellToAwait }
    );
  }
}

export default AwaitCell;
