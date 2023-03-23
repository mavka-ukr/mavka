import StructureCell from "./common/structureCell.js";

class ListStructureCell extends StructureCell {
  /**
   * @param {Mavka} mavka
   */
  constructor(mavka) {
    super(mavka, "список");

    this.properties["виконати_виклик"] = this.mavka.tools.fn(
      (args) => {
        return this.mavka.makeList(Object.values(args));
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
