import { Cell } from "./utils/cell.js";

class DictionaryStructureCell extends Cell {
  /**
   * @param {Mavka} mavka
   */
  constructor(mavka) {
    super(mavka, "<структура словник>");
  }

  doCall(context, args) {
    return new this.mavka.DictionaryCell(this.mavka, args);
  }
}

export default DictionaryStructureCell;
