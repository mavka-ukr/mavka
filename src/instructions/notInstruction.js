import Instruction from "./instruction.js";

class NotInstruction extends Instruction {
  /**
   * @param {Scope} scope
   * @param {NotNode} node
   * @returns {*}
   */
  async compile(scope, node) {
    const debugInfoVarName = this.mavka.putDebugInfoVarName(node);

    const value = await this.mavka.compileNode(scope, node.value);

    return `not(${value}, ${debugInfoVarName})`;
  }
}

export default NotInstruction;
