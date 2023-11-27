import Instruction from "./instruction.js";
import { varname } from "../utils.js";
import { buildParams, buildParamsExtracting } from "../builders.js";

class StructureInstruction extends Instruction {
  async compile(scope, node) {
    const debugInfoVarName = this.mavka.putDebugInfoVarName(node);
    const name = node.name;
    const compiledParent = node.parent ? await this.mavka.compileNode(scope, node.parent) : "null";
    const compiledParams = await buildParams(this.mavka, scope, node.params);

    return `${varname(name)} = mavka_structure("${name}",${compiledParent},${compiledParams},{},${debugInfoVarName})`;
  }
}

export default StructureInstruction;
