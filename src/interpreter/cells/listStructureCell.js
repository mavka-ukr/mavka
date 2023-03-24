import StructureCell from "./common/structureCell.js";

class ListStructureCell extends StructureCell {
  /**
   * @param {Mavka} mavka
   */
  constructor(mavka) {
    super(mavka, "список");

    this.properties["виконати_виклик"] = this.mavka.makeProxyFunction(
      (args) => {
        return this.mavka.makeList(Object.values(args));
      }
    );

    this.setMethod("виконати_перетворення_на_текст", (args, context, options) => {
      const values = options.meValue.properties.values
        .map((v) => v.asText(context).asJsValue(context))
        .join(", ");

      return this.mavka.toCell(`[${values}]`);
    });
  }

  static createInstance(mavka) {
    return new ListStructureCell(mavka);
  }
}

export default ListStructureCell;
