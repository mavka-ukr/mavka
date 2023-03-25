import Instruction from "./utils/instruction.js";
import runArgs from "./utils/args.js";
import ChainNode from "mavka-parser/src/ast/ChainNode.js";

class CallInstruction extends Instruction {
  /**
   * @param {Context} context
   * @param {CallNode} node
   * @returns {*}
   */
  runSync(context, node) {
    let value = this.mavka.empty;

    const args = runArgs(this.mavka, context, node.args);

    if (node.value instanceof ChainNode) {
      value = this.mavka.runSync(context, node.value.left);

      const diia = value.get(context, node.value.right.name);
      return diia.doCall(context, args);
    } else {
      const value = this.mavka.runSync(context, node.value);
      return value.doCall(context, args);
    }
  }

  /**
   * @param {Context} context
   * @param {CallNode} node
   * @returns {Promise<*>}
   */
  async runAsync(context, node) {
    let value = this.mavka.empty;

    const args = await runArgs(this.mavka, context, node.args);

    if (node.value instanceof ChainNode) {
      value = await this.mavka.runAsync(context, node.value.left);

      const diia = value.get(context, node.value.right.name);
      return diia.doCall(context, args);
    } else {
      const value = await this.mavka.runAsync(context, node.value);
      return value.doCall(context, args);
    }
  }
}

export default CallInstruction;
