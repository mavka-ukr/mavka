import { Cell } from "./cell.js";

class StringCell extends Cell {
  /**
   * @param {Mavka} mavka
   * @param {string} value
   */
  constructor(mavka, value) {
    super(mavka, "Текст", {}, {}, mavka.stringConstructorCellInstance);

    this.value = value;

    this.methods["обрізати"] = mavka.tools.fn(() => this.asJsValue().trim());

    this.methods["виконати_додавання"] = mavka.tools.convertFnToDiia(
      (value) => new this.mavka.StringCell(this.mavka, this.asJsString() + value.asString().asJsString()),
      { jsArgs: false }
    );
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

export class TextConstructorCell extends Cell {
  /**
   * @param {Mavka} mavka
   */
  constructor(mavka) {
    super(mavka, "текст");
  }

  call(context, args, options = {}) {
    if (Array.isArray(args)) {
      return args[0].asString();
    } else {
      throw "not ok";
    }
  }

  asString() {
    return this.mavka.toCell(`структура текст`);
  }
}

export default StringCell;
