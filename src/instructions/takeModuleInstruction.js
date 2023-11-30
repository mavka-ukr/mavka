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
        node.relative,
        [name],
        node.as,
        di,
        options
      );
    } else if (node.id instanceof IdentifiersChainNode) {
      const parts = node.id.toFlatArray();

      return await this.mavka.loadModule(
        node.relative,
        parts,
        node.as,
        di,
        options
      );
    }

    return "";
  }
}

export default TakeModuleInstruction;
