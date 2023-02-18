import Instruction from "./instruction.js";

class AnonymousDiiaInstruction extends Instruction {
  /**
   * @param {Context} context
   * @param {AnonymousDiiaNode} node
   * @returns {*}
   */
  runSync(context, node) {
    return new this.mavka.AnonymousDiiaCell(this.mavka, context, node);
  }

  /**
   * @param {Context} context
   * @param {AnonymousDiiaNode} node
   * @returns {Promise<*>}
   */
  async runAsync(context, node) {
    return new this.mavka.AnonymousDiiaCell(this.mavka, context, node);
  }
}

export default AnonymousDiiaInstruction;
