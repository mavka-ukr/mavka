import Instruction from "./instruction.js";
import { processBody, varname } from "../utils.js";

class TryInstruction extends Instruction {
  /**
   * @param {Scope} scope
   * @param {TryNode} node
   * @param {object} options
   * @returns {*}
   */
  async compile(scope, node, options) {
    const body = await this.mavka.compileBody(scope, processBody(this.mavka, scope, node.tryBody, options), options);
    const catchName = node.catchName ? node.catchName : null;
    const catchBody = await this.mavka.compileBody(scope, processBody(this.mavka, scope, node.catchBody, options), options);

    return `try {
  ${body}
} catch (e) {
  if (e instanceof MavkaError) {
    ${catchName ? `${varname(catchName)} = e.value;` : ""}
    ${catchBody}
  } else {
    throw e;
  }
}`;
  }
}

export default TryInstruction;
