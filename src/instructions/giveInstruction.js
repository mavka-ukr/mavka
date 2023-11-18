import Instruction from "./instruction.js";
import IdentifierNode from "mavka-parser/src/ast/IdentifierNode.js";
import { varname } from "../utils.js";

class GiveInstruction extends Instruction {
  /**
   * @param {Scope} scope
   * @param {GiveNode} node
   * @returns {*}
   */
  async compile(scope, node) {
    let lines = [];
    for (const el of node.elements) {
      if (el.id instanceof IdentifierNode) {
        if (el.as) {
          lines.push(`moduleValue.__m_props__["${el.as}"] = ${varname(el.id.name)};`);
        } else {
          lines.push(`moduleValue.__m_props__["${el.id.name}"] = ${varname(el.id.name)};`);
        }
      }
    }
    return lines.join("\n");
  }
}

export default GiveInstruction;
