import Instruction from "./utils/instruction.js";

class TryInstruction extends Instruction {
  /**
   * @param {Context} context
   * @param {TryNode} node
   * @returns {*}
   */
  runSync(context, node) {
    try {
      return this.mavka.run(context, node.tryBody);
    } catch (e) {
      if (e instanceof this.mavka.ThrowValue) {
        if (node.catchName) {
          context.set(node.catchName.name, e.value);
        }
        return this.mavka.run(context, node.catchBody);
      } else {
        throw e;
      }
    }
  }

  /**
   * @param {Context} context
   * @param {TryNode} node
   * @returns {Promise<*>}
   */
  async runAsync(context, node) {
    try {
      return await this.mavka.run(context, node.tryBody);
    } catch (e) {
      if (e instanceof this.mavka.ThrowValue) {
        if (node.catchName) {
          context.set(node.catchName.name, e.value);
        }
        return await this.mavka.run(context, node.catchBody);
      } else {
        throw e;
      }
    }
  }
}

export default TryInstruction;
