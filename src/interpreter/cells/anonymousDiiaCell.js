import DiiaCell from "./diiaCell.js";

class AnonymousDiiaCell extends DiiaCell {
  /**
   * @param {Mavka} mavka
   * @param {Context} context
   * @param {AnonymousDiiaNode} node
   */
  constructor(mavka, context, node) {
    super(mavka, context, node);
  }
}

export default AnonymousDiiaCell;
