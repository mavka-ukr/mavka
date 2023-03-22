import Instruction from "./utils/instruction.js";

class IfInstruction extends Instruction {
  /**
   * @param {Context} context
   * @param {IfNode} node
   * @returns {*}
   */
  runSync(context, node) {
    const value = this.mavka.runSync(context, node.value);

    if (value.asBoolean(context).asJsValue(context)) {
      return this.mavka.run(context, node.body);
    } else {
      return this.mavka.run(context, node.elseBody);
    }
  }

  /**
   * @param {Context} context
   * @param {IfNode} node
   * @returns {Promise<*>}
   */
  async runAsync(context, node) {
    let value = await this.mavka.runAsync(context, node.value);

    if (value.asBoolean(context).asJsValue(context)) {
      return this.mavka.run(context, node.body);
    } else {
      return this.mavka.run(context, node.elseBody);
    }
  }
}

export default IfInstruction;
