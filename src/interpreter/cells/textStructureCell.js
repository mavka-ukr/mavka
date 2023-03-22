import { Cell } from "./utils/cell.js";

class TextStructureCell extends Cell {
  /**
   * @param {Mavka} mavka
   */
  constructor(mavka) {
    super(mavka, "<структура текст>");
  }

  doCall(context, args, options = {}) {
    if (Array.isArray(args) && args.length) {
      return args[0].asText(context);
    }

    return this.mavka.toCell("");
  }
}

export default TextStructureCell;
