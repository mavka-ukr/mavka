import { Cell } from "./utils/cell.js";

class ListCell extends Cell {
  constructor(mavka, values) {
    super(mavka, "<список>", {}, {}, null, mavka.listStructureCellInstance);

    this.values = values;

    const getFn = this.mavka.tools.fn(([index]) => {
      return this.values[index];
    });

    this.set("отримати", getFn);

    this.methods["виконати_отримання_елементу"] = getFn;
  }

  asText(context) {
    const values = this.values
      .map((v) => this.mavka.toCell(v).asText(context).asJsString())
      .join(", ");

    return this.mavka.toCell(`[${values}]`);
  }

  asJsValue(context) {
    return this.values
      .map((v) => {
        if (v instanceof this.mavka.Cell) {
          return v.asJsValue(context);
        }

        return null;
      });
  }

  * [Symbol.iterator]() {
    for (const value of this.values) {
      yield value;
    }
  }
}

export default ListCell;
