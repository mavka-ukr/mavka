import Instruction from "./instruction.js";
import IdentifierNode from "mavka-parser/src/ast/IdentifierNode.js";
import IdentifiersChainNode from "mavka-parser/src/ast/IdentifiersChainNode.js";
import { varname } from "../utils.js";
import ChainNode from "mavka-parser/src/ast/ChainNode.js";

class PreDecrementInstruction extends Instruction {
  /**
   * @param {Scope} scope
   * @param {PreDecrementNode} node
   * @returns {*}
   */
  async compile(scope, node) {
    const debugInfoVarName = this.mavka.putDebugInfoVarName(node);

    // well, this is complete shit
    // hopefully we will rewrite it to some real bytecode instead of js

    if (node.value instanceof IdentifierNode) {
      const value = await this.mavka.compileNode(scope, node.value);

      return `
((function() {
  ${value} = mavka_sub(${value}, 1, ${debugInfoVarName});
  return ${value};
})())
`.trim();
    } else if (node.value instanceof IdentifiersChainNode || node.value instanceof ChainNode) {
      const value = await this.mavka.compileNode(scope, node.value);
      const left = await this.mavka.compileNode(scope, node.value.left);
      const right = node.value.right.name;

      return `
((function() {
  mavka_set(${left}, "${right}", mavka_sub(${value}, 1, ${debugInfoVarName}), ${debugInfoVarName});
  return ${value};
})())
`.trim();
    } else {
      throw new Error("PostDecrementInstruction: unsupported value type");
    }
  }
}

export default PreDecrementInstruction;
