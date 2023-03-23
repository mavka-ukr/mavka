import { Cell } from "./utils/cell.js";

class ListStructureCell extends Cell {
  /**
   * @param {Mavka} mavka
   */
  constructor(mavka) {
    super(mavka, "<структура список>");

    this.methods["виконати_виклик"] = this.mavka.tools.fn(
      (args) => {
        return new this.mavka.ListCell(this.mavka, Object.values(args));
      },
      { jsArgs: false }
    );

    this.methods["виконати_перетворення_на_текст"] = this.mavka.tools.fn(
      (args, context, options) => {
        const values = options.meValue.values
          .map((v) => v.asText(context).asJsValue(context))
          .join(", ");

        return this.mavka.toCell(`[${values}]`);
      },
      { jsArgs: false }
    );
  }
}

export default ListStructureCell;
