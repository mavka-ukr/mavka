import Instruction from "./instruction.js";
import IdentifierNode from "mavka-parser/src/ast/IdentifierNode.js";
import IdentifiersChainNode from "mavka-parser/src/ast/IdentifiersChainNode.js";

class TakeModuleInstruction extends Instruction {
  /**
   * @param {Scope} scope
   * @param {TakeModuleNode} node
   * @param {*} options
   * @returns {Promise<string>}
   */
  async compile(scope, node, options) {
    const diName = this.mavka.putDebugInfoVarName(node);
    const di = this.mavka.debugInfoVarNames.get(diName);

    if (node.id instanceof IdentifierNode) {
      const name = node.id.name;

      return await this.mavka.loadModule(
        name,
        node.as || name,
        di,
        options
      );
    } else if (node.id instanceof IdentifiersChainNode) {
      const name = node.id.toFlatArray().join(".");

      return await this.mavka.loadModule(
        name,
        node.as || name,
        di,
        options
      );
    }

    return "";
  }
}

export default TakeModuleInstruction;
