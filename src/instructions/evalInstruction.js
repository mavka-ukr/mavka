import Instruction from "./instruction.js";
import StringNode from "mavka-parser/src/ast/StringNode.js";

class EvalInstruction extends Instruction {
  /**
   * @param {Scope} scope
   * @param {EvalNode} node
   * @returns {*}
   */
  async compile(scope, node) {
    if (node.value instanceof StringNode) {
      return `${node.value.value}`.trim();
    }
  }
}

export default EvalInstruction;
