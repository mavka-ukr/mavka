import StructureCell from "./common/structureCell.js";

class TextStructureCell extends StructureCell {
  /**
   * @param {Mavka} mavka
   */
  constructor(mavka) {
    super(mavka, "текст");

    this.properties["виконати_виклик"] = this.mavka.tools.fn(
      (args, context) => {
        if (Array.isArray(args) && args.length) {
          return args[0].asText(context);
        }

        return this.mavka.toCell("");
      },
      { jsArgs: false }
    );

    this.methods["виконати_перетворення_на_текст"] = this.mavka.tools.fn(
      (args, context, options) => options.meValue,
      { jsArgs: false }
    );
    this.methods["виконати_перетворення_на_число"] = this.mavka.tools.fn(
      (args, context, options) => this.mavka.toCell(Number(options.meValue.asJsValue(context))),
      { jsArgs: false }
    );
    this.methods["виконати_перетворення_на_логічне"] = this.mavka.tools.fn(
      (args, context, options) => this.mavka.toCell(Boolean(options.meValue.asJsValue(context))),
      { jsArgs: false }
    );
  }
}

export default TextStructureCell;
