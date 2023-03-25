import StructureCell from "./common/structureCell.js";

class DiiaStructureCell extends StructureCell {
  /**
   * @param {Mavka} mavka
   */
  constructor(mavka) {
    super(mavka, "Дія");

    this.setMethod("виконати_перетворення_на_текст", (args, context, options) => {
      let value = "<";
      if (options.meValue.meta.isAsync) {
        value = `${value}тривала `;
      }
      value = `${value}дія`;
      if (options.meValue.meta.name) {
        value = `${value} ${options.meValue.meta.name}`;
      }
      value = `${value}>`;
      return this.mavka.toCell(value);
    });
  }

  static createInstance(mavka) {
    return new DiiaStructureCell(mavka);
  }
}

export default DiiaStructureCell;
