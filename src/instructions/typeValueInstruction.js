import Instruction from "./instruction.js";
import IdentifierNode from "mavka-parser/src/ast/IdentifierNode.js";

function toFlatArray(node) {
  const toFlat = (id) => {
    if (!id) {
      return [];
    }

    return [...toFlat(id.left), ...toFlat(id.right)];
  };

  return toFlat(node).flat(Infinity);
}

class TypeValueInstruction extends Instruction {
  /**
   * @param {Scope} scope
   * @param {TypeValueNode} node
   * @returns {*}
   */
  async compile(scope, node) {
    return "[" + (await Promise.all(toFlatArray(node).map((v) => this.mavka.compileNode(scope, v)))).join(",") + "]";
  }
}

export default TypeValueInstruction;
