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

    return RangeStructureCell.getInstance(this.mavka).doCall(context, [from, to]);
  }

  /**
   * @param {Context} context
   * @param {FromtoNode} node
   * @returns {Promise<*>}
   */
  async runAsync(context, node) {
    const from = await this.mavka.runAsync(context, node.from);
    const to = await this.mavka.runAsync(context, node.to);

    return RangeStructureCell.getInstance(this.mavka).doCall(context, [from, to]);
  }
}

export default FromtoInstruction;
