import { Cell } from "./utils/cell.js";

class DictionaryCell extends Cell {
  constructor(mavka, items) {
    super(
      mavka,
      "<словник>",
      {},
      mavka.dictionaryStructureCellInstance
    );

    this.items = items;
  }

  asJsValue(context) {
    const obj = {};

    for (const [k, v] of Object.entries(this.items)) {
      obj[this.mavka.toCell(k).asJsValue(context)] = v.asJsValue(context);
    }

    return obj;
  }

  * [Symbol.iterator]() {
    for (const [key, value] of Object.entries(this.items)) {
      yield { key, value };
    }
  }
}

export default DictionaryCell;
