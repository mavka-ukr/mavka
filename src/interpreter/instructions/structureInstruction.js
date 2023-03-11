import Instruction from "./instruction.js";

class StructureInstruction extends Instruction {
  /**
   * @param {Context} context
   * @param {StructureNode} node
   * @returns {*}
   */
  runSync(context, node) {
    const structureCell = new this.mavka.StructureCell(this.mavka, context, node);

    context.set(node.name.name, structureCell);

    return structureCell;
  }

  /**
   * @param {Context} context
   * @param {StructureNode} node
   * @returns {Promise<*>}
   */
  async runAsync(context, node) {
    const structureCell = new this.mavka.StructureCell(this.mavka, context, node);

    context.set(node.name.name, structureCell);

    return structureCell;
  }
}

export default StructureInstruction;
