import Instruction from "./instruction.js";
import FromtoNode from "mavka-parser/src/ast/FromtoNode.js";
import { processBody, varname } from "../utils.js";

let i = 0;

class EachInstruction extends Instruction {
  /**
   * @param {Scope} scope
   * @param {EachNode} node
   * @param {object} options
   * @returns {*}
   */
  async compile(scope, node, options) {
    const iterator = node.iterator;
    const keyName = node.keyName;
    const name = node.name;
    const body = node.body;

    i++;

    const iteratordebugInfoVarName = this.mavka.putDebugInfoVarName(iterator);

    const compiledBody = await this.mavka.compileBody(scope, processBody(this.mavka, scope, body, {
      ...options,
      loop: true
    }), {
      ...options,
      loop: true
    });

    if (iterator instanceof FromtoNode) {
      const compiledFrom = await this.mavka.compileNode(scope, iterator.from);
      const compiledTo = await this.mavka.compileNode(scope, iterator.to);
      const compiledSymbol = iterator.toSymbol || "<=";

      if (iterator.middle) {
        const compiledMiddle = await this.mavka.compileNode(scope, iterator.middle);
        let compiledMiddleSymbol;

        switch (iterator.middleSymbol || "+") {
          case "+":
            compiledMiddleSymbol = "mavka_add";
            break;
          case "-":
            compiledMiddleSymbol = "mavka_sub";
            break;
          case "*":
            compiledMiddleSymbol = "mavka_mul";
            break;
          case "/":
            compiledMiddleSymbol = "mavka_div";
            break;
          case "%":
            compiledMiddleSymbol = "mavka_mod";
            break;
          case "//":
            compiledMiddleSymbol = "mavka_divDiv";
            break;
          case "**":
            compiledMiddleSymbol = "mavka_pow";
            break;
          case "^":
            compiledMiddleSymbol = "mavka_bitXor";
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
for (${varname(name)} = compiledFrom_${i}; ${varname(name)} ${compiledSymbol} compiledTo_${i}; ${varname(name)} = mavka_add(${varname(name)}, 1, ${iteratordebugInfoVarName})) {
  ${compiledBody}
}
`.trim();
      }
    }

    const compiledIterator = await this.mavka.compileNode(scope, iterator);

    if (keyName) {
      return `
for (var entry of mavka_entries(${compiledIterator})) {
  ${varname(keyName)} = entry[0];
  ${varname(name)} = entry[1];
  ${compiledBody}
}
`.trim();
    }

    return `
for (${varname(name)} of mavka_values(${compiledIterator})) {
  ${compiledBody}
}
`.trim();
  }
}

export default EachInstruction;
