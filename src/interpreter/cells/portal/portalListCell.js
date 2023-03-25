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
      () => this.meta.values,
      null,
      { values }
    );
  }
}

export default PortalListCell;
