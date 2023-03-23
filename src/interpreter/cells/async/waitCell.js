import { Cell } from "../common/cell.js";

class WaitCell extends Cell {
  /**
   * @param {Mavka} mavka
   * @param {AsyncCell} value
   */
  constructor(mavka, value) {
    super(mavka, "<очікування>");

    this.value = value;
  }
}

export default WaitCell;
