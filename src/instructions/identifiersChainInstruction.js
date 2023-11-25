import Instruction from "./instruction.js";
import IdentifierNode from "mavka-parser/src/ast/IdentifierNode.js";

class IdentifiersChainInstruction extends Instruction {
  /**
   * @param {Scope} scope
   * @param {IdentifiersChainNode} node
   * @returns {*}
   */
  async compile(scope, node) {
    const debugInfoVarName = this.mavka.putDebugInfoVarName(node);

    const left = await this.mavka.compileNode(scope, node.left);
    let right;

    if (node.right instanceof IdentifierNode) {
      right = node.right.name;
    } else {
      right = await this.mavka.compileNode(scope, node.right);
    }

    return `mavka_get(${left}, "${right}", ${debugInfoVarName})`;
  }
}

export default IdentifiersChainInstruction;
