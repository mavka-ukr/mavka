import Instruction from "./utils/instruction.js";
import RangeStructureCell from "../../library/rangeStructureCell.js";

class FromtoInstruction extends Instruction {
  /**
   * @param {Context} context
   * @param {FromtoNode} node
   * @returns {*}
   */
  runSync(context, node) {
    const from = this.mavka.runSync(context, node.from);
    const to = this.mavka.runSync(context, node.to);
    const include = node.include;

    return RangeStructureCell.getInstance(this.mavka).doCall(context, [
      from,
      to,
      this.mavka.makeNumber(1), include ? this.mavka.yes : this.mavka.no
    ]);
  }

  /**
   * @param {Context} context
   * @param {FromtoNode} node
   * @returns {Promise<*>}
   */
  async runAsync(context, node) {
    const from = await this.mavka.runAsync(context, node.from);
    const to = await this.mavka.runAsync(context, node.to);
    const include = node.include;

    return RangeStructureCell.getInstance(this.mavka).doCall(context, [
      from,
      to,
      this.mavka.makeNumber(1), include ? this.mavka.yes : this.mavka.no
    ]);
  }
}

export default FromtoInstruction;
