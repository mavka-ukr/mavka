import StructureCell from "./common/structureCell.js";

class ModuleStructureCell extends StructureCell {
  /**
   * @param {Mavka} mavka
   */
  constructor(mavka) {
    super(mavka, "модуль");

    this.setMethod("виконати_перетворення_на_текст", (args, context, options) => {
      const keys = Object.keys(options.meValue.properties).join(", ");

      return this.mavka.makeText(`<модуль ${options.meValue.meta.name}[${keys}]>`);
    });
  }

  static createInstance(mavka) {
    return new ModuleStructureCell(mavka);
  }
}

export default ModuleStructureCell;
