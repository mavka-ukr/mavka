import Instruction from "./instruction.js";

class GetElementInstruction extends Instruction {
  /**
   * @param {Scope} scope
   * @param {GetElementNode} node
   * @returns {*}
   */
  async compile(scope, node) {
    const debugInfoVarName = this.mavka.putDebugInfoVarName(node);

    const value = await this.mavka.compileNode(scope, node.left);
    const index = await this.mavka.compileNode(scope, node.element);

    return `mavka_getSpecial(${value}, ${index}, ${debugInfoVarName})`;
  }
}

export default GetElementInstruction;
