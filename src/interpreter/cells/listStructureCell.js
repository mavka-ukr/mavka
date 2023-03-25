import StructureCell from "./common/structureCell.js";

class ListStructureCell extends StructureCell {
  /**
   * @param {Mavka} mavka
   */
  constructor(mavka) {
    super(mavka, "список");

    this.properties["виконати_виклик"] = this.mavka.makeProxyFunction((args) => {
      return this.mavka.makeList(Object.values(args));
    });

    this.setMethod("виконати_перетворення_на_текст", (args, context, options) => {
      const values = options.meValue.properties.values
        .map((v) => {
          if (this.mavka.isText(v)) {
            return `"${v.asText(context).asJsValue(context)}"`;
          }
          return v.asText(context).asJsValue(context);
        })
        .join(", ");

      return this.mavka.toCell(`[${values}]`);
    });

    this.setMethod("виконати_отримання_елемента", (args, context, options) => {
      const index = Object.values(args)[0].asJsValue(context);

      return this.mavka.toCell(options.meValue.properties.values[index]);
    });
    this.setMethod("виконати_присвоєння_елемента", (args, context, options) => {
      const index = Object.values(args)[0].asJsValue(context);
      const value = Object.values(args)[1];

      options.meValue.properties.values[index] = value;

      return value;
    });

    this.setMethod("довжина", (args, context, options) => {
      return this.mavka.makeNumber(options.meValue.properties.values.length);
    });
    this.setMethod("додати", (args, context, options) => {
      return this.mavka.makeNumber(options.meValue.properties.values.push(Object.values(args)[0]));
    });
  }

  static createInstance(mavka) {
    return new ListStructureCell(mavka);
  }
}

export default ListStructureCell;
