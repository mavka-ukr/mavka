import Instruction from "./utils/instruction.js";

class PostDecrementInstruction extends Instruction {
  /**
   * @param {Context} context
   * @param {PostDecrementNode} node
   * @returns {*}
   */
  runSync(context, node) {
    //
  }

  /**
   * @param {Context} context
   * @param {PostDecrementNode} node
   * @returns {Promise<*>}
   */
  async runAsync(context, node) {
    //
  }
}

export default PostDecrementInstruction;
