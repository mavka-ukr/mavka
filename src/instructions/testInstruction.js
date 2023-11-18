import Instruction from "./instruction.js";

class TestInstruction extends Instruction {
  /**
   * @param {Scope} scope
   * @param {TestNode} node
   * @returns {*}
   */
  async compile(scope, node) {
    const left = await this.mavka.compileNode(scope, node.left);
    const right = await this.mavka.compileNode(scope, node.right);

    switch (node.operation) {
      case "і":
        return `${left} && ${right}`;
      case "або":
        return `${left} || ${right}`;
      default:
        throw new Error(`Unknown operation ${node.operation}`);
    }
  }
}

export default TestInstruction;
