import Instruction from "./instruction.js";
import runArgs from "./args.js";

class CallInstruction extends Instruction {
  /**
   * @param {Context} context
   * @param {CallNode} node
   * @returns {*}
   */
  runSync(context, node) {
    const value = this.mavka.runSync(context, node.value);
    const args = runArgs(this.mavka, context, node.args);

    return value.call(context, args);
  }

  /**
   * @param {Context} context
   * @param {CallNode} node
   * @returns {Promise<*>}
   */
  async runAsync(context, node) {
    const value = await this.mavka.runAsync(context, node.value);
    const args = await runArgs(this.mavka, context, node.args);

    return value.call(context, args);
  }
}

export default CallInstruction;
