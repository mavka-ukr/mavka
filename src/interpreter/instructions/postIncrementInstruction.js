import Instruction from "./utils/instruction.js";

class PostIncrementInstruction extends Instruction {
  /**
   * @param {Context} context
   * @param {PostIncrementNode} node
   * @returns {*}
   */
  runSync(context, node) {
    this.mavka.fall(context, this.mavka.makeText(`Інкремент наразі недоступний.`));
  }

  /**
   * @param {Context} context
   * @param {PostIncrementNode} node
   * @returns {Promise<*>}
   */
  async runAsync(context, node) {
    this.mavka.fall(context, this.mavka.makeText(`Інкремент наразі недоступний.`));
  }
}

export default PostIncrementInstruction;
