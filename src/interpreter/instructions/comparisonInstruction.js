import Instruction from "./utils/instruction.js";

function doOperation(mavka, context, left, right, operation) {
  return ({
    "==": () => left.doCompareEquals(context, right),
    "!=": () => left.doCompareNotEquals(context, right),
    "<": () => left.doCompareLesserThan(context, right),
    ">=": () => left.doCompareGreaterThanOrEquals(context, right),
    ">": () => left.doCompareGreaterThan(context, right),
    "<=": () => left.doCompareLesserThanOrEquals(context, right),

    "є": () => mavka.toCell(left.isInstanceOf(right)), // instanceof
    "не є": () => mavka.toCell(left.isInstanceOf(right)).not(context), // not instanceof

    "рівно": () => left.doCompareEquals(context, right), // ==
    "не рівно": () => left.doCompareNotEquals(context, right), // !=
    "менше": () => left.doCompareLesserThan(context, right), // <
    "не менше": () => left.doCompareGreaterThanOrEquals(context, right), // >=
    "більше": () => left.doCompareGreaterThan(context, right), // >
    "не більше": () => left.doCompareLesserThanOrEquals(context, right), // <=

    "не": () => left.doCompareNotEquals(context, right), // не рівно

    "містить": () => left.has(context, right), // in
    "не містить": () => left.has(context, right).not() // not in
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

    return doOperation(this.mavka, context, left, right, node.operation);
  }

  /**
   * @param {Context} context
   * @param {ComparisonNode} node
   * @returns {Promise<*>}
   */
  async runAsync(context, node) {
    const left = await this.mavka.runAsync(context, node.left);
    const right = await this.mavka.runAsync(context, node.right);

    return doOperation(this.mavka, context, left, right, node.operation);
  }
}

export default ComparisonInstruction;
