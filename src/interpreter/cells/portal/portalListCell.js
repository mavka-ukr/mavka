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
      function* () {
        for (const [key, value] of Object.entries(values)) {
          yield { key, value: mavka.toCell(value) };
        }
      },
      { values }
    );
  }
}

export default PortalListCell;
