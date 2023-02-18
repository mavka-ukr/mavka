import { Cell } from "./cell.js";

class WaitCell extends Cell {
  /**
   * @param {Mavka} mavka
   * @param {AsyncCell} value
   */
  constructor(mavka, value) {
    super(mavka, {
      "__value__": value
    });
  }

  getValue() {
    return this.properties["__value__"];
  }

  asString() {
    return this.mavka.toCell("очікувач");
  }
}

export default WaitCell;
