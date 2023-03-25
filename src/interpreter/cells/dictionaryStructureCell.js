import StructureCell from "./common/structureCell.js";

class DictionaryStructureCell extends StructureCell {
  /**
   * @param {Mavka} mavka
   */
  constructor(mavka) {
    super(mavka, "словник");

    this.properties["виконати_виклик"] = this.mavka.makeProxyFunction((args) => {
      return this.mavka.makeDictionary(args);
    });

    this.setMethod("виконати_перетворення_на_текст", (args, context, options) => {
      const items = Object.entries(options.meValue.properties.items)
        .map(([k, v]) => {
          let kt = this.mavka.toCell(k).asText(context).asJsValue(context);
          let vt = v.asText(context).asJsValue(context);

          if (this.mavka.isText(this.mavka.toCell(kt))) {
            kt = `"${kt}"`;
          }
          if (this.mavka.isText(v)) {
            vt = `"${vt}"`;
          }

          return `${kt}=${vt}`;
        })
        .join(", ");

      return this.mavka.toCell(`(${items})`);
    });
  }

  static createInstance(mavka) {
    return new DictionaryStructureCell(mavka);
  }
}

export default DictionaryStructureCell;
