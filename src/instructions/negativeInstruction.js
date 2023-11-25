import Instruction from "./instruction.js";

class NegativeInstruction extends Instruction {
  /**
   * @param {Scope} scope
   * @param {NegativeNode} node
   * @returns {*}
   */
  async compile(scope, node) {
    const debugInfoVarName = this.mavka.putDebugInfoVarName(node);

    const value = await this.mavka.compileNode(scope, node.value);

    return `mavka_negative(${value}, ${debugInfoVarName})`;
  }
}

export default NegativeInstruction;
