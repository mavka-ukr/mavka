import Instruction from "./instruction.js";

class DiiaInstruction extends Instruction {
  /**
   * @param {Context} context
   * @param {DiiaNode} node
   * @returns {*}
   */
  runSync(context, node) {
    const diia = new this.mavka.DiiaCell(this.mavka, context, node);

    context.set(node.name.name, diia);

    return diia;
  }

  /**
   * @param {Context} context
   * @param {DiiaNode} node
   * @returns {Promise<*>}
   */
  async runAsync(context, node) {
    const diia = new this.mavka.DiiaCell(this.mavka, context, node);

    context.set(node.name.name, diia);

    return diia;
  }
}

export default DiiaInstruction;
