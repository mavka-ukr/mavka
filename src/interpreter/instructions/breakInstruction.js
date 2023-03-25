import Instruction from "./utils/instruction.js";

export class BreakSignal {
}

class BreakInstruction extends Instruction {
  /**
   * @param {Context} context
   * @param {BreakNode} node
   * @returns {*}
   */
  runSync(context, node) {
    return new BreakSignal();
  }

  /**
   * @param {Context} context
   * @param {BreakNode} node
   * @returns {Promise<*>}
   */
  async runAsync(context, node) {
    return new BreakSignal();
  }
}

export default BreakInstruction;
