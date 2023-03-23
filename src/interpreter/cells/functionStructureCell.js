import StructureCell from "./common/structureCell.js";

class FunctionStructureCell extends StructureCell {
  /**
   * @param {Mavka} mavka
   */
  constructor(mavka) {
    super(
      mavka,
      "функція",
      {},
      mavka.anonymousDiiaStructureCellInstance,
      [],
      {}
    );

    this.methods["виконати_перетворення_на_текст"] = this.mavka.tools.fn(
      (args, context, options) => {
        let value = "<";
        if (options.meValue.isAsync) {
          value = `${value}тривала `;
        }
        value = `${value}функція>`;
        return this.mavka.toCell(value);
      },
      { jsArgs: false }
    );
  }
}

export default FunctionStructureCell;
