import Instruction from "./utils/instruction.js";

function doOperation(context, left, right, operation) {
  return ({
    "і": () => left.asBoolean(context).asJsValue(context) && right.asBoolean(context).asJsValue(context),
    "або": () => left.asBoolean(context).asJsValue(context) || right.asBoolean(context).asJsValue(context)
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
      if (left.asBoolean(context).asJsValue(context)) {
        return left;
      }
    }

    const right = this.mavka.runSync(context, node.right);

    return this.mavka.toCell(doOperation(context, left, right, node.operation));
  }

  /**
   * @param {Context} context
   * @param {TestNode} node
   * @returns {Promise<*>}
   */
  async runAsync(context, node) {
    const left = await this.mavka.runAsync(context, node.left);
    if (node.operation === "або") {
      if (left.asBoolean(context).asJsValue(context)) {
        return left;
      }
    }

    const right = await this.mavka.runAsync(context, node.right);

    return this.mavka.toCell(doOperation(context, left, right, node.operation));
  }
}

export default TestInstruction;
