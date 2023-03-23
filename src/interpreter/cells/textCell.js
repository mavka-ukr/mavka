import { Cell } from "./utils/cell.js";

class TextCell extends Cell {
  /**
   * @param {Mavka} mavka
   * @param {string} value
   */
  constructor(mavka, value) {
    super(
      mavka,
      "<текст>",
      {},
      mavka.textStructureCellInstance
    );

    this.value = value;

    this.methods["обрізати"] = mavka.tools.fn(() => this.asJsValue(context).trim());

    this.methods["виконати_додавання"] = mavka.tools.fn(
      ([value], context) => new this.mavka.TextCell(this.mavka, this.asJsValue(context) + value.asText(context).asJsValue(context)),
      { jsArgs: false }
    );
  }

  asBoolean(context) {
    return this.mavka.toCell(!!this.asJsValue(context));
  }

  asText(context) {
    return this;
  }

  /**
   * @param {Context} context
   * @return {string}
   */
  asJsValue(context) {
    return this.value;
  }

  asNumber() {
    return new this.mavka.NumberCell(this.mavka, Number(this.asJsValue()));
  }

  compare(value, fn) {
    if (value instanceof TextCell) {
      return this.mavka.toCell(fn(this.asJsValue(), value.asJsValue()));
    }

    return this.mavka.toCell(false);
  }
}

export default TextCell;
