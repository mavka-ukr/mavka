import { Cell } from "./cell.js";

class BooleanCell extends Cell {
  /**
   * @param {Mavka} mavka
   * @param {boolean} value
   */
  constructor(mavka, value) {
    super(mavka, "Логічне");

    this.value = value;
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
    return Boolean(this.value);
  }

  opposite() {
    return this.asJsValue() ? this.mavka.falseCellInstance : this.mavka.trueCellInstance;
  }
}

export default BooleanCell;
