import { Cell } from "./utils/cell.js";

class ListStructureCell extends Cell {
  /**
   * @param {Mavka} mavka
   */
  constructor(mavka) {
    super(mavka, "<структура список>");
  }

  doCall(context, args) {
    return new this.mavka.ListCell(this.mavka, Object.values(args));
  }
}

export default ListStructureCell;
