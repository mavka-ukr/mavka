import Instruction from "./instruction.js";
import ArithmeticNode from "mavka-parser/src/ast/ArithmeticNode.js";
import AssignComplexNode from "mavka-parser/src/ast/AssignComplexNode.js";
import ChainNode from "mavka-parser/src/ast/ChainNode.js";
import GetElementNode from "mavka-parser/src/ast/GetElementNode.js";
import IdentifierNode from "mavka-parser/src/ast/IdentifierNode.js";

class AssignComplexInstruction extends Instruction {
  /**
   * @param {Scope} scope
   * @param {AssignComplexNode} node
   * @returns {*}
   */
  async compile(scope, node) {
    const debugInfoVarName = this.mavka.putDebugInfoVarName(node);

    if (node.symbol !== "=") {
      let operation = "";
      switch (node.symbol) {
        case "+=":
          operation = "+";
          break;
        case "-=":
          operation = "-";
          break;
        case "*=":
          operation = "*";
          break;
        case "/=":
          operation = "/";
          break;
        case "%=":
          operation = "%";
          break;
        case "//=":
          operation = "//";
          break;
        case "**=":
          operation = "**";
          break;
        case "<<=":
          operation = "<<";
          break;
        case ">>=":
          operation = ">>";
          break;
        case "&=":
          operation = "&";
          break;
        case "|=":
          operation = "|";
          break;
        case "~=":
          operation = "~";
          break;
        case "^=":
          operation = "^";
          break;
        default:
          throw new Error(`BUG: Unknown operation ${node.symbol}`);
      }
      let id;
      if (node.right.name) {
        id = new ChainNode(node.context, {
          left: node.left,
          right: new IdentifierNode(node.context, { name: node.right.name })
        });
      } else if (node.right.element) {
        id = new GetElementNode(node.context, {
          left: node.left,
          element: node.right.element
        });
      }
      const newAssignNode = new AssignComplexNode(node.context, {
        left: node.left,
        right: node.right,
        symbol: "=",
        value: new ArithmeticNode(node.context, {
          left: id,
          right: node.value, operation
        })
      });
      return await this.mavka.compileNode(scope, newAssignNode);
    }
    const left = await this.mavka.compileNode(scope, node.left);
    const value = await this.mavka.compileNode(scope, node.value);
    if (node.right.name) {
      return `mavka_set(${left}, "${node.right.name}", ${value}, ${debugInfoVarName})`;
    } else if (node.right.element) {
      const right = await this.mavka.compileNode(scope, node.right.element);
      return `mavka_setSpecial(${left}, ${right}, ${value}, ${debugInfoVarName})`;
    }
  }
}

export default AssignComplexInstruction;
