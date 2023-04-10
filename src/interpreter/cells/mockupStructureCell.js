import StructureCell from "./common/structureCell.js";

class MockupStructureCell extends StructureCell {
  /**
   * @param {Mavka} mavka
   */
  constructor(mavka) {
    super(mavka, "макет");

    this.setMethod("виконати_перетворення_на_текст", (args, context, options) => {
      return this.mavka.toCell(`<макет ${options.meValue.meta.name}>`);
    });
  }

  static createInstance(mavka) {
    return new MockupStructureCell(mavka);
  }
}

export default MockupStructureCell;
