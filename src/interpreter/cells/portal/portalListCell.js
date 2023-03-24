import { Cell } from "../common/cell.js";

class PortalListCell extends Cell {
  /**
   * @param {Mavka} mavka
   * @param {Array} values
   */
  constructor(mavka, values) {
    super(
      mavka,
      "<портал список>",
      {},
      null,
      () => this.values
    );

    this.values = values;
  }
}

export default PortalListCell;
