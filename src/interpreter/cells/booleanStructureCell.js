import StructureCell from "./common/structureCell.js";

class BooleanStructureCell extends StructureCell {
  /**
   * @param {Mavka} mavka
   */
  constructor(mavka) {
    super(mavka, "логічне");

    this.properties["виконати_виклик"] = this.mavka.tools.fn(
      (args, context) => {
        if (Array.isArray(args) && args.length) {
          return args[0].asBoolean(context);
        }

        return this.mavka.noCellInstance;
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
