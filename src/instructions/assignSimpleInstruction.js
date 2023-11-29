import Instruction from "./instruction.js";
import { varname } from "../utils.js";
import IdentifierNode from "mavka-parser/src/ast/IdentifierNode.js";
import ArithmeticNode from "mavka-parser/src/ast/ArithmeticNode.js";
import AssignSimpleNode from "mavka-parser/src/ast/AssignSimpleNode.js";
import { MavkaCompilationError } from "../error.js";

class AssignSimpleInstruction extends Instruction {
  /**
   * @param {Scope} scope
   * @param {AssignSimpleNode} node
   * @returns {*}
   */
  async compile(scope, node) {
    if (node.symbol === ":=") {
      const debugInfoVarName = this.mavka.putDebugInfoVarName(node);
      const di = this.mavka.debugInfoVarNames.get(debugInfoVarName);
      if (!scope.parent || scope.parent === this.mavka.globalScope) {
        throw new MavkaCompilationError(`Неможливо визначити субʼєкт "${node.name}" у глобальному контексті.`, di);
      }
      scope.parent.setters.add(node.name);
      if (!scope.parent.has(node.name)) {
        scope.parent.vars.set(node.name, true);
      }
      const value = await this.mavka.compileNode(scope, node.value);
      return `set${varname(node.name)}(${value})`;
    }
    if (node.symbol !== "=" && node.symbol !== "це") {
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
      const newAssignNode = new AssignSimpleNode(node.context, {
        name: node.name,
        type: node.type,
        symbol: "=",
        value: new ArithmeticNode(node.context, {
          left: new IdentifierNode(node.context, { name: node.name }),
          right: node.value,
          operation
        })
      });
      return await this.mavka.compileNode(scope, newAssignNode);
    }
    const value = await this.mavka.compileNode(scope, node.value);
    return `${varname(node.name)} = ${value}`;
  }
}

export default AssignSimpleInstruction;
