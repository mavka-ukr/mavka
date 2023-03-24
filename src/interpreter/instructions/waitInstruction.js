import Instruction from "./utils/instruction.js";

class WaitInstruction extends Instruction {
  /**
   * @param {Context} context
   * @param {WaitNode} node
   * @returns {*}
   */
  runSync(context, node) {
    this.mavka.throw(context, "Не можна чекати в нетривалому контексті.");
  }

  /**
   * @param {Context} context
   * @param {WaitNode} node
   * @returns {Promise<*>}
   */
  async runAsync(context, node) {
    return new this.mavka.WaitCell(this.mavka, this.mavka.runSync(context, node.value));
  }
}

export default WaitInstruction;
