import { Cell } from "./utils/cell.js";

class ListCell extends Cell {
  constructor(mavka, values) {
    super(
      mavka,
      "<список>",
      {},
      mavka.listStructureCellInstance
    );

    this.values = values;
  }

  asJsValue(context) {
    return this.values
      .map((v) => v.asJsValue(context));
  }

  * [Symbol.iterator]() {
    for (const [key, value] of Object.entries(this.values)) {
      yield { key, value };
    }
  }
}

export default ListCell;
