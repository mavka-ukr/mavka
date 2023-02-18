import Instruction from "./instruction.js";

class ArithmeticInstruction extends Instruction {
  /**
   * @param {Context} context
   * @param {ArithmeticNode} node
   * @returns {*}
   */
  runSync(context, node) {
    const left = this.mavka.runSync(context, node.left);
    const right = this.mavka.runSync(context, node.right);

    return ({
      "+": () => left.plus(right),
      "-": () => left.minus(right),
      "*": () => left.multiply(right),
      "/": () => left.divide(right)
    }[node.operation])();
  }

  /**
   * @param {Context} context
   * @param {ArithmeticNode} node
   * @returns {Promise<*>}
   */
  async runAsync(context, node) {
    const left = await this.mavka.runAsync(context, node.left);
    const right = await this.mavka.runAsync(context, node.right);

    return ({
      "+": () => left.plus(right),
      "-": () => left.minus(right),
      "*": () => left.multiply(right),
      "/": () => left.divide(right)
    }[node.operation])();
  }
}

export default ArithmeticInstruction;
