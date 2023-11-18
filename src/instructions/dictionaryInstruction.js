import Instruction from "./instruction.js";
import { buildDictionary } from "../builders.js";

class DictionaryInstruction extends Instruction {
  /**
   * @param {Scope} scope
   * @param {DictionaryNode} node
   * @returns {*}
   */
  async compile(scope, node) {
    return await buildDictionary(this.mavka, scope, node.args);
  }
}

export default DictionaryInstruction;
