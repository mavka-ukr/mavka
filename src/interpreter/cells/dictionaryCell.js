import { Cell } from "./utils/cell.js";

class DictionaryCell extends Cell {
  constructor(mavka, properties) {
    super(mavka, "словник", properties, {}, null, mavka.dictionaryStructureCellInstance);

    const getFn = this.mavka.tools.fn(([index]) => {
      return this.properties[index];
    });

    this.set("отримати", getFn);

    this.methods["виконати_отримання_елементу"] = getFn;
  }

  asText(context) {
    const properties = Object.entries(this.properties)
      .map(([k, v]) => `${this.mavka.toCell(k).asText(context).asJsString()}=${this.mavka.toCell(v).asText(context).asJsString()}`)
      .join(", ");

    return this.mavka.toCell(`(${properties})`);
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

export default DictionaryCell;
