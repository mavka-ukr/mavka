import Instruction from "./instruction.js";

class IdentifierInstruction extends Instruction {
  /**
   * @param {Context} context
   * @param {IdentifierNode} node
   * @returns {*}
   */
  runSync(context, node) {
    return context.get(node.name);
  }

  /**
   * @param {Context} context
   * @param {IdentifierNode} node
   * @returns {Promise<*>}
   */
  async runAsync(context, node) {
    return context.get(node.name);
  }
}

export default IdentifierInstruction;
