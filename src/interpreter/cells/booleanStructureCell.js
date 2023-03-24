import StructureCell from "./common/structureCell.js";

class BooleanStructureCell extends StructureCell {
  /**
   * @param {Mavka} mavka
   */
  constructor(mavka) {
    super(mavka, "логічне");

    this.properties["виконати_виклик"] = this.mavka.makeProxyFunction(
      (args, context) => {
        if (Array.isArray(args) && args.length) {
          return args[0].asBoolean(context);
        }

        return this.mavka.noCellInstance;
      }
    );

    this.setMethod("виконати_перетворення_на_текст", (args, context, options) => {
        return options.meValue.asJsValue(context)
          ? this.mavka.toCell("так")
          : this.mavka.toCell("ні");
      }
    );
    this.setMethod("виконати_перетворення_на_число", (args, context, options) => {
        return options.meValue.asJsValue(context)
          ? this.mavka.toCell(1)
          : this.mavka.toCell(0);
      }
    );
    this.setMethod("виконати_перетворення_на_логічне", (args, context, options) => {
        return options.meValue;
      }
    );
  }

  static createInstance(mavka) {
    return new BooleanStructureCell(mavka);
  }
}

export default BooleanStructureCell;
