import Instruction from "./utils/instruction.js";
import RangeStructureCell from "../../library/rangeStructureCell.js";

const makeRangeCell = (mavka, context, from, to, symbol) => {
  from = from.asNumber(context).asJsValue(context);
  to = to.asNumber(context).asJsValue(context);

  return new mavka.Cell(
    mavka,
    `діапазон(${from}, ${to}, 1)`,
    {},
    RangeStructureCell.getInstance(mavka),
    () => {
      return null;
    },
    function* () {
      if (symbol === "<=" || symbol === null) {
        for (let i = from, key = 0; i <= to; i += 1, key++) {
          yield { key, value: mavka.makeNumber(i) };
        }
      } else if (symbol === "<") {
        for (let i = from, key = 0; i < to; i += 1, key++) {
          yield { key, value: mavka.makeNumber(i) };
        }
      } else if (symbol === ">=") {
        for (let i = from, key = 0; i >= to; i += 1, key++) {
          yield { key, value: mavka.makeNumber(i) };
        }
      } else if (symbol === ">") {
        for (let i = from, key = 0; i > to; i += 1, key++) {
          yield { key, value: mavka.makeNumber(i) };
        }
      } else if (symbol === "==") {
        for (let i = from, key = 0; i === to; i += 1, key++) {
          yield { key, value: mavka.makeNumber(i) };
        }
      } else {
        for (let i = from, key = 0; i !== to; i += 1, key++) {
          yield { key, value: mavka.makeNumber(i) };
        }
      }
    }
  );
};

class FromtoInstruction extends Instruction {
  /**
   * @param {Context} context
   * @param {FromtoNode} node
   * @returns {*}
   */
  runSync(context, node) {
    const from = this.mavka.runSync(context, node.from);
    const to = this.mavka.runSync(context, node.to);
    const symbol = node.symbol;

    return makeRangeCell(this.mavka, context, from, to, symbol);
  }

  /**
   * @param {Context} context
   * @param {FromtoNode} node
   * @returns {Promise<*>}
   */
  async runAsync(context, node) {
    const from = await this.mavka.runAsync(context, node.from);
    const to = await this.mavka.runAsync(context, node.to);
    const symbol = node.symbol;

    return makeRangeCell(this.mavka, context, from, to, symbol);
  }
}

export default FromtoInstruction;
