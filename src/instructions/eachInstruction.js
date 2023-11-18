import Instruction from "./instruction.js";
import FromtoNode from "mavka-parser/src/ast/FromtoNode.js";
import { processBody, varname } from "../utils.js";

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

    const iteratordebugInfoVarName = this.mavka.putDebugInfoVarName(iterator);

    const compiledBody = await this.mavka.compileBody(scope, processBody(this.mavka, scope, body));

    if (iterator instanceof FromtoNode) {
      const compiledFrom = await this.mavka.compileNode(scope, iterator.from);
      const compiledTo = await this.mavka.compileNode(scope, iterator.to);
      const compiledSymbol = iterator.symbol || "<=";

      return `
for (${varname(name)} = ${compiledFrom}; ${varname(name)} ${compiledSymbol} ${compiledTo}; ${varname(name)} = add(${varname(name)}, 1, ${iteratordebugInfoVarName})) {
  ${compiledBody}
}
`.trim();
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
