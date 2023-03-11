import { Cell } from "./cell.js";

class NumberCell extends Cell {
  /**
   * @param {Mavka} mavka
   * @param {number} value
   */
  constructor(mavka, value) {
    super(
      mavka,
      "Число",
      {},
      {},
      null,
      mavka.numberStructureCellInstance
    );

    this.value = value;

    this.methods["виконати_додавання"] = this.mavka.tools.convertFnToDiia(
      (value) => new this.mavka.NumberCell(this.mavka, this.asJsNumber() + value.asNumber().asJsNumber()),
      { jsArgs: false }
    );
    this.methods["виконати_віднімання"] = this.mavka.tools.convertFnToDiia(
      (value) => new this.mavka.NumberCell(this.mavka, this.asJsNumber() - value.asNumber().asJsNumber()),
      { jsArgs: false }
    );
    this.methods["виконати_множення"] = this.mavka.tools.convertFnToDiia(
      (value) => new this.mavka.NumberCell(this.mavka, this.asJsNumber() * value.asNumber().asJsNumber()),
      { jsArgs: false }
    );
    this.methods["виконати_ділення"] = this.mavka.tools.convertFnToDiia(
      (value) => new this.mavka.NumberCell(this.mavka, this.asJsNumber() / value.asNumber().asJsNumber()),
      { jsArgs: false }
    );
  }

  asNumber() {
    return this;
  }

  /**
   * @return {number}
   */
  asJsNumber() {
    return this.value;
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

export class NumberStructureCell extends Cell {
  /**
   * @param {Mavka} mavka
   */
  constructor(mavka) {
    super(mavka, "число");
  }

  call(context, args, options = {}) {
    if (Array.isArray(args)) {
      return args[0].asNumber();
    } else {
      throw "not ok";
    }
  }

  asString() {
    return this.mavka.toCell(`структура число`);
  }
}


export default NumberCell;
