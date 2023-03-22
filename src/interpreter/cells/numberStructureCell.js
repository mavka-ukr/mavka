import { Cell } from "./utils/cell.js";

class NumberStructureCell extends Cell {
  /**
   * @param {Mavka} mavka
   */
  constructor(mavka) {
    super(mavka, "<структура число>");
  }

  doCall(context, args, options = {}) {
    if (Array.isArray(args) && args.length) {
      return args[0].asNumber(context);
    }

    return this.mavka.toCell(0);
  }
}

export default NumberStructureCell;
