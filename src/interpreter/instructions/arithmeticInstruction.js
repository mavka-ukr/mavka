import Instruction from "./utils/instruction.js";

function doOperation(context, left, right, operation) {
  return ({
    "+": () => left.doAdd(context, right),
    "-": () => left.doSub(context, right),
    "*": () => left.doMul(context, right),
    "/": () => left.doDiv(context, right),
    "%": () => left.doDivMod(context, right),
    "//": () => left.doDivFloor(context, right),
    "**": () => left.doPow(context, right),
    "^": () => left.doXor(context, right)
  }[operation])();
}

class ArithmeticInstruction extends Instruction {
  /**
   * @param {Context} context
   * @param {ArithmeticNode} node
   * @returns {*}
   */
  runSync(context, node) {
    const left = this.mavka.runSync(context, node.left);
    const right = this.mavka.runSync(context, node.right);

    return doOperation(context, left, right, node.operation);
  }

  /**
   * @param {Context} context
   * @param {ArithmeticNode} node
   * @returns {Promise<*>}
   */
  async runAsync(context, node) {
    const left = await this.mavka.runAsync(context, node.left);
    const right = await this.mavka.runAsync(context, node.right);

    return doOperation(context, left, right, node.operation);
  }
}

export default ArithmeticInstruction;
