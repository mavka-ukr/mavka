import Instruction from "./instruction.js";
import { processBody } from "../utils.js";

class TryInstruction extends Instruction {
  /**
   * @param {Scope} scope
   * @param {TryNode} node
   * @returns {*}
   */
  async compile(scope, node) {
    const body = await this.mavka.compileBody(scope, processBody(this.mavka, scope, node.tryBody));
    const catchName = node.catchName ? node.catchName : null;
    const catchBody = await this.mavka.compileBody(scope, processBody(this.mavka, scope, node.catchBody));

    return `try {
  ${body}
} catch (e) {
  if (e instanceof MavkaError) {
    ${catchName ? `${catchName} = e.value;` : ""}
    ${catchBody}
  } else {
    throw e;
  }
}`;
  }
}

export default TryInstruction;
