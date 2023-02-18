import { Cell } from "./cell.js";

class BooleanCell extends Cell {
  /**
   * @param {Mavka} mavka
   * @param {boolean} value
   */
  constructor(mavka, value) {
    super(mavka, {
      "__value__": value
    });
  }

  asString() {
    return this.asJsValue()
      ? this.mavka.toCell("так")
      : this.mavka.toCell("ні");
  }

  asBoolean() {
    return this;
  }

  /**
   * @return {boolean}
   */
  asJsValue() {
    return Boolean(this.properties["__value__"]);
  }
}

export default BooleanCell;
