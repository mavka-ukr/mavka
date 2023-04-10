import { Cell } from "../common/cell.js";
import context from "../../contexts/context.js";

/**
 * Portal to JS-array.
 */
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

    this.set(context, "перетворити_на_список", mavka.makeProxyFunction(() => {
      return this.mavka.makeList(this.meta.values.map((v) => mavka.toCell(v)));
    }));
  }
}

export default PortalListCell;
