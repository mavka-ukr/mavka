import { Cell } from "./utils/cell.js";

class BooleanStructureCell extends Cell {
  /**
   * @param {Mavka} mavka
   */
  constructor(mavka) {
    super(mavka, "<структура логічне>");
  }

  doCall(context, args, options = {}) {
    if (Array.isArray(args) && args.length) {
      return args[0].asBoolean(context);
    }

    return this.mavka.falseCellInstance;
  }
}

export default BooleanStructureCell;
