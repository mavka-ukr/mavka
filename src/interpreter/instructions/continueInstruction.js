import Instruction from "./utils/instruction.js";

export class ContinueSignal {
}

class ContinueInstruction extends Instruction {
  /**
   * @param {Context} context
   * @param {ContinueNode} node
   * @returns {*}
   */
  runSync(context, node) {
    return new ContinueSignal();
  }

  /**
   * @param {Context} context
   * @param {ContinueNode} node
   * @returns {Promise<*>}
   */
  async runAsync(context, node) {
    return new ContinueSignal();
  }
}

export default ContinueInstruction;
