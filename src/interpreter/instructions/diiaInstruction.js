import Instruction from "./utils/instruction.js";
import { ThrowValue } from "./throwInstruction.js";

class DiiaInstruction extends Instruction {
  /**
   * @param {Context} context
   * @param {DiiaNode} node
   * @returns {*}
   */
  runSync(context, node) {
    const diia = new this.mavka.DiiaCell(this.mavka, context, node);

    if (node.structure) {
      const cell = this.mavka.runSync(context, node.structure);

      if (cell instanceof this.mavka.StructureCell) {
        cell.methods[node.name.name] = diia;
      } else {
        throw new ThrowValue(context, `Не вдалось встановити дію "${node.structure.name}.${node.name.name}".`);
      }
    } else {
      context.set(node.name.name, diia);
    }

    return diia;
  }

  /**
   * @param {Context} context
   * @param {DiiaNode} node
   * @returns {Promise<*>}
   */
  async runAsync(context, node) {
    const diia = new this.mavka.DiiaCell(this.mavka, context, node);

    if (node.structure) {
      const cell = await this.mavka.runAsync(context, node.structure);

      if (cell instanceof this.mavka.StructureCell) {
        cell.methods[node.name.name] = diia;
      } else {
        throw new ThrowValue(context, `Не вдалось встановити дію "${node.structure.name}.${node.name.name}".`);
      }
    } else {
      context.set(node.name.name, diia);
    }

    return diia;
  }
}

export default DiiaInstruction;
