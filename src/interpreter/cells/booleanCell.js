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
      {},
      null,
      mavka.booleanStructureCellInstance
    );

    this.value = value;
  }

  asText(context) {
    return this.asJsValue(context)
      ? this.mavka.toCell("так")
      : this.mavka.toCell("ні");
  }

  asBoolean() {
    return this;
  }

  /**
   * @return {boolean}
   */
  asJsValue(context) {
    return Boolean(this.value);
  }

  not() {
    return this.asJsValue(context) ? this.mavka.falseCellInstance : this.mavka.trueCellInstance;
  }
}

export default BooleanCell;
