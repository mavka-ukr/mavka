import Instruction from "./instruction.js";

function run(left, right, operation) {
  return ({
    "==": () => left.equals(right),
    "!=": () => left.notEquals(right),
    ">": () => left.greaterThan(right),
    "<": () => left.lesserThan(right),
    ">=": () => left.greaterThanOrEquals(right),
    "<=": () => left.lesserThanOrEquals(right),
    "рівно": () => left.equals(right),
    "не": () => left.notEquals(right),
    "не рівно": () => left.notEquals(right),
    "більше": () => left.greaterThan(right),
    "менше": () => left.lesserThan(right),
    "не більше": () => left.lesserThanOrEquals(right),
    "не менше": () => left.greaterThanOrEquals(right),
    "є": () => left.isInstanceOf(right),
    "не є": () => left.isInstanceOf(right).opposite()
  }[operation])();
}

class ComparisonInstruction extends Instruction {
  /**
   * @param {Context} context
   * @param {ComparisonNode} node
   * @returns {*}
   */
  runSync(context, node) {
    const left = this.mavka.runSync(context, node.left);
    const right = this.mavka.runSync(context, node.right);

    return run(left, right, node.operation);
  }

  /**
   * @param {Context} context
   * @param {ComparisonNode} node
   * @returns {Promise<*>}
   */
  async runAsync(context, node) {
    const left = await this.mavka.runAsync(context, node.left);
    const right = await this.mavka.runAsync(context, node.right);

    return run(left, right, node.operation);
  }
}

export default ComparisonInstruction;
