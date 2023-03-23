import { Cell } from "./utils/cell.js";

class NumberCell extends Cell {
  /**
   * @param {Mavka} mavka
   * @param {number} value
   */
  constructor(mavka, value) {
    super(
      mavka,
      "<число>",
      {},
      mavka.numberStructureCellInstance
    );

    this.value = value;
  }

  asJsValue(context) {
    return this.value;
  }

  negative(context) {
    return this.mavka.toCell(-this.asJsValue(context));
  }

  positive(context) {
    return this.mavka.toCell(+this.asJsValue(context));
  }

  compare(value, fn) {
    if (value instanceof NumberCell) {
      return this.mavka.toCell(fn(this.asJsValue(context), value.asJsValue(context)));
    }

    return this.mavka.toCell(false);
  }
}


export default NumberCell;
