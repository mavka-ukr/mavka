import Instruction from "./utils/instruction.js";

class PostIncrementInstruction extends Instruction {
  /**
   * @param {Context} context
   * @param {PostIncrementNode} node
   * @returns {*}
   */
  runSync(context, node) {
    //
  }

  /**
   * @param {Context} context
   * @param {PostIncrementNode} node
   * @returns {Promise<*>}
   */
  async runAsync(context, node) {
    //
  }
}

export default PostIncrementInstruction;
