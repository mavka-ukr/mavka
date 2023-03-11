import { Cell } from "./cell.js";

class BooleanCell extends Cell {
  /**
   * @param {Mavka} mavka
   * @param {boolean} value
   */
  constructor(mavka, value) {
    super(
      mavka,
      "Логічне",
      {},
      {},
      null,
      mavka.booleanStructureCellInstance
    );

    this.value = value;
  }

  asString() {
    return this.asJsValue()
      ? this.mavka.toCell("так")
      : this.mavka.toCell("ні");
  }

  asBoolean() {
    return this;
  }

  /**
   * @return {boolean}
   */
  asJsValue() {
    return Boolean(this.value);
  }

  opposite() {
    return this.asJsValue() ? this.mavka.falseCellInstance : this.mavka.trueCellInstance;
  }
}

export class BooleanStructureCell extends Cell {
  /**
   * @param {Mavka} mavka
   */
  constructor(mavka) {
    super(mavka, "логічне");
  }

  call(context, args, options = {}) {
    if (Array.isArray(args)) {
      return args[0].asBoolean();
    } else {
      throw "not ok";
    }
  }

  asString() {
    return this.mavka.toCell(`структура логічне`);
  }
}

export default BooleanCell;
