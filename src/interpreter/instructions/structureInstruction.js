import Instruction from "./instruction.js";
import { StructureConstructorCell } from "../cells/structureCell.js";

class StructureInstruction extends Instruction {
  /**
   * @param {Context} context
   * @param {StructureNode} node
   * @returns {*}
   */
  runSync(context, node) {
    const structureConstructor = new StructureConstructorCell(this.mavka, context, node);

    context.set(node.name.name, structureConstructor);

    return structureConstructor;
  }

  /**
   * @param {Context} context
   * @param {StructureNode} node
   * @returns {Promise<*>}
   */
  async runAsync(context, node) {
    const structureConstructor = new StructureConstructorCell(this.mavka, context, node);

    context.set(node.name.name, structureConstructor);

    return structureConstructor;
  }
}

export default StructureInstruction;
