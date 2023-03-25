import Instruction from "./utils/instruction.js";

class PostDecrementInstruction extends Instruction {
  /**
   * @param {Context} context
   * @param {PostDecrementNode} node
   * @returns {*}
   */
  runSync(context, node) {
    this.mavka.fall(context, this.mavka.makeText(`Декремент наразі недоступний.`));
  }

  /**
   * @param {Context} context
   * @param {PostDecrementNode} node
   * @returns {Promise<*>}
   */
  async runAsync(context, node) {
    this.mavka.fall(context, this.mavka.makeText(`Декремент наразі недоступний.`));
  }
}

export default PostDecrementInstruction;
