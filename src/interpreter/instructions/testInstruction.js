import Instruction from "./instruction.js";

function run(left, right, operation) {
  return ({
    "і": () => left.asBoolean().asJsValue() && right.asBoolean().asJsValue(),
    "або": () => left.asBoolean().asJsValue() || right.asBoolean().asJsValue()
  }[operation])();
}

class TestInstruction extends Instruction {
  /**
   * @param {Context} context
   * @param {TestNode} node
   * @returns {*}
   */
  runSync(context, node) {
    const left = this.mavka.runSync(context, node.left);
    if (node.operation === "або") {
      if (left.asBoolean().asJsValue()) {
        return left;
      }
    }

    const right = this.mavka.runSync(context, node.right);

    return this.mavka.toCell(run(left, right, node.operation));
  }

  /**
   * @param {Context} context
   * @param {TestNode} node
   * @returns {Promise<*>}
   */
  async runAsync(context, node) {
    const left = await this.mavka.runAsync(context, node.left);
    if (node.operation === "або") {
      if (left.asBoolean().asJsValue()) {
        return left;
      }
    }

    const right = await this.mavka.runAsync(context, node.right);

    return this.mavka.toCell(run(left, right, node.operation));
  }
}

export default TestInstruction;
