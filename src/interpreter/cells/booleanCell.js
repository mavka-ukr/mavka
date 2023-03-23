import { Cell } from "./utils/cell.js";

class BooleanCell extends Cell {
  /**
   * @param {Mavka} mavka
   * @param {boolean} value
   */
  constructor(mavka, value) {
    super(
      mavka,
      "<логічне>",
      {},
      mavka.booleanStructureCellInstance
    );

    this.value = Boolean(value);
  }

  /**
   * @param {Context} context
   * @return {boolean}
   */
  asJsValue(context) {
    return this.value;
  }

  /**
   * @param {Context} context
   * @return {BooleanCell}
   */
  not(context) {
    return this.asJsValue(context)
      ? this.mavka.falseCellInstance
      : this.mavka.trueCellInstance;
  }
}

export default BooleanCell;
