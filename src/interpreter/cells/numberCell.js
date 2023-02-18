import { Cell } from "./cell.js";

class NumberCell extends Cell {
  /**
   * @param {Mavka} mavka
   * @param {number} value
   */
  constructor(mavka, value) {
    super(mavka, {
      "__value__": value
    });
  }

  plus(value) {
    return new this.mavka.NumberCell(this.mavka, this.asJsNumber() + value.asNumber().asJsNumber());
  }

  minus(value) {
    return new this.mavka.NumberCell(this.mavka, this.asNumber().asJsNumber() - value.asNumber().asJsNumber());
  }

  multiply(value) {
    return new this.mavka.NumberCell(this.mavka, this.asNumber().asJsNumber() * value.asNumber().asJsNumber());
  }

  divide(value) {
    return new this.mavka.NumberCell(this.mavka, this.asNumber().asJsNumber() / value.asNumber().asJsNumber());
  }

  asNumber() {
    return this;
  }

  /**
   * @return {number}
   */
  asJsNumber() {
    return this.properties["__value__"];
  }

  asString() {
    return new this.mavka.StringCell(this.mavka, String(this.asJsNumber()));
  }

  asJsValue() {
    return this.asJsNumber();
  }

  compare(value, fn) {
    if (value instanceof NumberCell) {
      return this.mavka.toCell(fn(this.asJsNumber(), value.asJsNumber()));
    }

    return this.mavka.toCell(false);
  }
}

export default NumberCell;
