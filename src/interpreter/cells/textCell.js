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
      {},
      null,
      mavka.textStructureCellInstance
    );

    this.value = value;

    this.methods["обрізати"] = mavka.tools.fn(() => this.asJsValue(context).trim());

    this.methods["виконати_додавання"] = mavka.tools.fn(
      ([value], context) => new this.mavka.TextCell(this.mavka, this.asJsString() + value.asText(context).asJsString()),
      { jsArgs: false }
    );
  }

  asBoolean() {
    return this.mavka.toCell(!!this.asJsString());
  }

  asText(context) {
    return this;
  }

  asPrettyString() {
    return this.mavka.toCell(`"${this.asJsValue(context)}"`);
  }

  /**
   * @return {string}
   */
  asJsString() {
    return this.value;
  }

  asJsValue(context) {
    return this.asJsString();
  }

  asNumber() {
    return new this.mavka.NumberCell(this.mavka, Number(this.asJsString()));
  }

  compare(value, fn) {
    if (value instanceof TextCell) {
      return this.mavka.toCell(fn(this.asJsString(), value.asJsString()));
    }

    return this.mavka.toCell(false);
  }
}

export default TextCell;
