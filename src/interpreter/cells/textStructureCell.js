import StructureCell from "./common/structureCell.js";

class TextStructureCell extends StructureCell {
  /**
   * @param {Mavka} mavka
   */
  constructor(mavka) {
    super(mavka, "текст");

    this.properties["виконати_виклик"] = this.mavka.makeProxyFunction(
      (args, context) => {
        if (Array.isArray(args) && args.length) {
          return args[0].asText(context);
        }

        return this.mavka.toCell("");
      }
    );

    this.setMethod("виконати_перетворення_на_текст", (args, context, options) => {
      return options.meValue;
    });
    this.setMethod("виконати_перетворення_на_число", (args, context, options) => {
      return this.mavka.toCell(Number(options.meValue.asJsValue(context)));
    });
    this.setMethod("виконати_перетворення_на_логічне", (args, context, options) => {
      return this.mavka.toCell(Boolean(options.meValue.asJsValue(context)));
    });
  }

  static createInstance(mavka) {
    return new TextStructureCell(mavka);
  }
}

export default TextStructureCell;
