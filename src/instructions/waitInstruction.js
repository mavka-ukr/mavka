import Instruction from "./instruction.js";

class WaitInstruction extends Instruction {
  /**
   * @param {Scope} scope
   * @param {WaitNode} node
   * @returns {*}
   */
  async compile(scope, node) {
    const value = await this.mavka.compileNode(scope, node.value);
    return `await ${value}`;
  }
}

export default WaitInstruction;
