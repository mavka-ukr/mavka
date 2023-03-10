import { Cell } from "./cell.js";

class StringCell extends Cell {
  /**
   * @param {Mavka} mavka
   * @param {string} value
   */
  constructor(mavka, value) {
    super(mavka, "Текст");

    this.value = value;

    this.set("обрізати", mavka.tools.fn(() => this.asJsValue().trim()));
  }

  plus(value) {
    return new this.mavka.StringCell(this.mavka, this.asJsString() + value.asString().asJsString());
  }

  asBoolean() {
    return this.mavka.toCell(!!this.asJsString());
  }

  asString() {
    return this;
  }

  asPrettyString() {
    return this.mavka.toCell(`"${this.asJsValue()}"`);
  }

  /**
   * @return {string}
   */
  asJsString() {
    return this.value;
  }

  asJsValue() {
    return this.asJsString();
  }

  asNumber() {
    return new this.mavka.NumberCell(this.mavka, Number(this.asJsString()));
  }

  compare(value, fn) {
    if (value instanceof StringCell) {
      return this.mavka.toCell(fn(this.asJsString(), value.asJsString()));
    }

    return this.mavka.toCell(false);
  }
}

export default StringCell;
