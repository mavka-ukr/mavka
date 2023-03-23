import StructureCell from "./common/structureCell.js";

class AnonymousDiiaStructureCell extends StructureCell {
  /**
   * @param {Mavka} mavka
   */
  constructor(mavka) {
    super(
      mavka,
      "анонімна дія",
      {},
      mavka.diiaStructureCellInstance,
      [],
      {}
    );

    this.methods["виконати_перетворення_на_текст"] = this.mavka.tools.fn(
      (args, context, options) => {
        let value = "<";
        if (options.meValue.isAsync) {
          value = `${value}тривала `;
        }
        value = `${value}анонімна дія>`;
        return this.mavka.toCell(value);
      },
      { jsArgs: false }
    );
  }
}

export default AnonymousDiiaStructureCell;
