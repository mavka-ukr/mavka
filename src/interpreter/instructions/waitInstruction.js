import Instruction from "./instruction.js";
import { ThrowValue } from "./throwInstruction.js";

class WaitInstruction extends Instruction {
  /**
   * @param {Context} context
   * @param {WaitNode} node
   * @returns {*}
   */
  runSync(context, node) {
    throw new ThrowValue(context, "Не можна чекати в нетривалому контексті.");
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
