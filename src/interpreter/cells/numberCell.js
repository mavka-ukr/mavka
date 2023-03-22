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
      {},
      null,
      mavka.numberStructureCellInstance
    );

    this.value = value;

    this.methods["виконати_додавання"] = this.mavka.tools.fn(
      ([value], context) => new this.mavka.NumberCell(this.mavka, this.asJsValue(context) + value.asNumber(context).asJsValue(context)),
      { jsArgs: false }
    );
    this.methods["виконати_віднімання"] = this.mavka.tools.fn(
      ([value], context) => new this.mavka.NumberCell(this.mavka, this.asJsValue(context) - value.asNumber(context).asJsValue(context)),
      { jsArgs: false }
    );
    this.methods["виконати_множення"] = this.mavka.tools.fn(
      ([value], context) => new this.mavka.NumberCell(this.mavka, this.asJsValue(context) * value.asNumber(context).asJsValue(context)),
      { jsArgs: false }
    );
    this.methods["виконати_ділення"] = this.mavka.tools.fn(
      ([value], context) => new this.mavka.NumberCell(this.mavka, this.asJsValue(context) / value.asNumber(context).asJsValue(context)),
      { jsArgs: false }
    );
  }

  asNumber() {
    return this;
  }

  asText(context) {
    return new this.mavka.TextCell(this.mavka, String(this.asJsValue(context)));
  }

  asBoolean() {
    return this.asJsValue(context) ? this.mavka.trueCellInstance : this.mavka.falseCellInstance;
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
