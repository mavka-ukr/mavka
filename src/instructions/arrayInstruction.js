import Instruction from "./instruction.js";

class ArrayInstruction extends Instruction {
  /**
   * @param {Scope} scope
   * @param {ArrayNode} node
   * @returns {*}
   */
  async compile(scope, node) {
    const elements = await Promise.all(node.elements.map(async (element) => {
      return await this.mavka.compileNode(scope, element);
    }));
    return `[${elements.join(", ")}]`;
  }
}

export default ArrayInstruction;
