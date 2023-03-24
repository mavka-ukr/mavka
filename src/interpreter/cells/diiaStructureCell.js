import StructureCell from "./common/structureCell.js";

class DiiaStructureCell extends StructureCell {
  /**
   * @param {Mavka} mavka
   */
  constructor(mavka) {
    super(mavka, "дія");


    this.setMethod("виконати_перетворення_на_текст", (args, context, options) => {
      let value = "<";
      if (options.meValue.isAsync) {
        value = `${value}тривала `;
      }
      value = `${value}дія ${options.meValue.name}>`;
      return this.mavka.toCell(value);
    });
  }

  static createInstance(mavka) {
    return new DiiaStructureCell(mavka);
  }
}

export default DiiaStructureCell;
