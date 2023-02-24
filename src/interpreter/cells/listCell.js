import { Cell } from "./cell.js";

class ListCell extends Cell {
  constructor(mavka, values) {
    super(mavka, "Список");

    this.values = values;

    const context = new this.mavka.Context(this.mavka, this.mavka.context);

    this.set("отримати", this.mavka.tools.asyncFn(([index]) => {
      return this.values[index];
    }));
  }

  asString() {
    const values = this.values
      .map((v) => this.mavka.toCell(v).asString().asJsString())
      .join(", ");

    return this.mavka.toCell(`Список(${values})`);
  }

  asJsValue() {
    return this.values
      .map((v) => {
        if (v instanceof this.mavka.Cell) {
          return v.asJsValue();
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
