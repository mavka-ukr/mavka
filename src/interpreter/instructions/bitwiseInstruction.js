import Instruction from "./utils/instruction.js";

function doOperation(context, left, right, operation) {
  return ({
    "<<": () => left.doBitLeft(context, right),
    ">>": () => left.doBitRight(context, right),
    "&": () => left.doBitAnd(context, right),
    "|": () => left.doBitOr(context, right),
    "^": () => left.doXor(context, right)
  }[operation])();
}

class BitwiseInstruction extends Instruction {
  /**
   * @param {Context} context
   * @param {BitwiseNode} node
   * @returns {*}
   */
  runSync(context, node) {
    const left = this.mavka.runSync(context, node.left);
    const right = this.mavka.runSync(context, node.right);

    return doOperation(context, left, right, node.operation);
  }

  /**
   * @param {Context} context
   * @param {BitwiseNode} node
   * @returns {Promise<*>}
   */
  async runAsync(context, node) {
    const left = await this.mavka.runAsync(context, node.left);
    const right = await this.mavka.runAsync(context, node.right);

    return doOperation(context, left, right, node.operation);
  }
}

export default BitwiseInstruction;
