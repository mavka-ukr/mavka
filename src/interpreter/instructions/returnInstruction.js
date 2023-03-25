import Instruction from "./utils/instruction.js";

export class ReturnSignal {
  constructor(value) {
    this.value = value;
  }
}

class ReturnInstruction extends Instruction {
  /**
   * @param {Context} context
   * @param {ReturnNode} node
   * @returns {*}
   */
  runSync(context, node) {
    return new ReturnSignal(this.mavka.runSync(context, node.value));
  }

  /**
   * @param {Context} context
   * @param {ReturnNode} node
   * @returns {Promise<*>}
   */
  async runAsync(context, node) {
    return new ReturnSignal(this.mavka.runSync(context, node.value));
  }
}

export default ReturnInstruction;
