import Instruction from "./instruction.js";
import FromtoNode from "mavka-parser/src/ast/FromtoNode.js";
import { processBody, varname } from "../utils.js";

let i = 0;

class EachInstruction extends Instruction {
  /**
   * @param {Scope} scope
   * @param {EachNode} node
   * @returns {*}
   */
  async compile(scope, node) {
    const iterator = node.iterator;
    const keyName = node.keyName;
    const name = node.name;
    const body = node.body;

    i++;

    const iteratordebugInfoVarName = this.mavka.putDebugInfoVarName(iterator);

    const compiledBody = await this.mavka.compileBody(scope, processBody(this.mavka, scope, body));

    if (iterator instanceof FromtoNode) {
      const compiledFrom = await this.mavka.compileNode(scope, iterator.from);
      const compiledTo = await this.mavka.compileNode(scope, iterator.to);
      const compiledSymbol = iterator.toSymbol || "<=";

      if (iterator.middle) {
        const compiledMiddle = await this.mavka.compileNode(scope, iterator.middle);
        let compiledMiddleSymbol;

        switch (iterator.middleSymbol || "+") {
          case "+":
            compiledMiddleSymbol = "add";
            break;
          case "-":
            compiledMiddleSymbol = "sub";
            break;
          case "*":
            compiledMiddleSymbol = "mul";
            break;
          case "/":
            compiledMiddleSymbol = "div";
            break;
          case "%":
            compiledMiddleSymbol = "mod";
            break;
          case "//":
            compiledMiddleSymbol = "divDiv";
            break;
          case "**":
            compiledMiddleSymbol = "pow";
            break;
          case "^":
            compiledMiddleSymbol = "bitXor";
            break;
          default:
            throw new Error(`BUG: Unknown operation ${node.operation}`);
        }

        return `
var compiledFrom_${i} = ${compiledFrom};var compiledTo_${i} = ${compiledTo};var compiledMiddle_${i} = ${compiledMiddle};
for (${varname(name)} = compiledFrom_${i}; ${varname(name)} ${compiledSymbol} compiledTo_${i}; ${varname(name)} = ${compiledMiddleSymbol}(${varname(name)}, compiledMiddle_${i}, ${iteratordebugInfoVarName})) {
  ${compiledBody}
}
`.trim();
      } else {
        return `
var compiledFrom_${i} = ${compiledFrom};var compiledTo_${i} = ${compiledTo};
for (${varname(name)} = compiledFrom_${i}; ${varname(name)} ${compiledSymbol} compiledTo_${i}; ${varname(name)} = add(${varname(name)}, 1, ${iteratordebugInfoVarName})) {
  ${compiledBody}
}
`.trim();
      }
    }

    const compiledIterator = await this.mavka.compileNode(scope, iterator);

    if (keyName) {
      return `
for (${varname(keyName)} in ${compiledIterator}) {
  ${varname(name)} = ${compiledIterator}[${varname(keyName)}];
  ${compiledBody}
}
`.trim();
    }

    return `
for (${varname(name)} of ${compiledIterator}) {
  ${compiledBody}
}
`.trim();
  }
}

export default EachInstruction;
