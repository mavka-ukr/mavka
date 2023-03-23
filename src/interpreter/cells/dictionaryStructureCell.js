import StructureCell from "./common/structureCell.js";

class DictionaryStructureCell extends StructureCell {
  /**
   * @param {Mavka} mavka
   */
  constructor(mavka) {
    super(mavka, "словник");

    this.properties["виконати_виклик"] = this.mavka.tools.fn(
      (args) => {
        return new this.mavka.makeDictionary(args);
      },
      { jsArgs: false }
    );

    this.methods["виконати_перетворення_на_текст"] = this.mavka.tools.fn(
      (args, context, options) => {
        const items = Object.entries(options.meValue.items)
          .map(([k, v]) => {
            const kt = this.mavka.toCell(k).asText(context).asJsValue(context);
            const vt = v.asText(context).asJsValue(context);

            return `${kt}=${vt}`;
          })
          .join(", ");

        return this.mavka.toCell(`(${items})`);
      },
      { jsArgs: false }
    );
  }
}

export default DictionaryStructureCell;
