import { Cell } from "./utils/cell.js";

class BooleanStructureCell extends Cell {
  /**
   * @param {Mavka} mavka
   */
  constructor(mavka) {
    super(mavka, "<структура логічне>");

    this.methods["виконати_виклик"] = this.mavka.tools.fn(
      (args, context) => {
        if (Array.isArray(args) && args.length) {
          return args[0].asBoolean(context);
        }

        return this.mavka.falseCellInstance;
      },
      { jsArgs: false }
    );

    this.methods["виконати_перетворення_на_текст"] = this.mavka.tools.fn(
      (args, context, options) =>
        options.meValue.asJsValue(context)
          ? this.mavka.toCell("так")
          : this.mavka.toCell("ні"),
      { jsArgs: false }
    );
    this.methods["виконати_перетворення_на_число"] = this.mavka.tools.fn(
      (args, context, options) =>
        options.meValue.asJsValue(context)
          ? this.mavka.toCell(1)
          : this.mavka.toCell(0),
      { jsArgs: false }
    );
    this.methods["виконати_перетворення_на_логічне"] = this.mavka.tools.fn(
      (args, context, options) => options.meValue,
      { jsArgs: false }
    );
  }
}

export default BooleanStructureCell;
