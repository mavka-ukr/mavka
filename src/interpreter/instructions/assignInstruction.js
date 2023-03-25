import Instruction from "./utils/instruction.js";
import WaitNode from "mavka-parser/src/ast/WaitNode.js";
import IdentifierNode from "mavka-parser/src/ast/IdentifierNode.js";
import ObjectDestructionNode from "mavka-parser/src/ast/ObjectDestructionNode.js";
import ArrayDestructionNode from "mavka-parser/src/ast/ArrayDestructionNode.js";

class AssignInstruction extends Instruction {
  /**
   * @param {Context} context
   * @param {AssignNode} node
   * @returns {*}
   */
  runSync(context, node) {
    if (node.symbol !== "=") {
      this.mavka.fall(context, this.mavka.makeText(`Присвоєння через "${node.symbol}" наразі недоступне.`));
    }
    if (node.id instanceof ObjectDestructionNode) {
      this.mavka.fall(context, this.mavka.makeText(`Деструкція обʼєкта наразі недоступна.`));
    }
    if (node.id instanceof ArrayDestructionNode) {
      this.mavka.fall(context, this.mavka.makeText(`Деструкція списку наразі недоступна.`));
    }

    if (node.wait) {
      this.mavka.fall(context, this.mavka.makeText(`"${node.symbol}" недоступно в нетривалому контексті.`));
    }

    const value = this.mavka.runSync(context, node.value);

    if (node.setElement) {
      const val = this.mavka.runSync(context, node.id);
      const element = this.mavka.runSync(context, node.setElement);

      val.doSetElement(context, element, value);
    } else if (node.id instanceof IdentifierNode) {
      context.set(node.id.name, value);
    } else {
      const val = this.mavka.runSync(context, node.id.left);

      val.set(context, node.id.right.name, value);
    }

    return value;
  }

  /**
   * @param {Context} context
   * @param {AssignNode} node
   * @returns {Promise<*>}
   */
  async runAsync(context, node) {
    if (node.symbol !== "=") {
      this.mavka.fall(context, this.mavka.makeText(`Присвоєння через "${node.symbol}" наразі недоступне.`));
    }
    if (node.id instanceof ObjectDestructionNode) {
      this.mavka.fall(context, this.mavka.makeText(`Деструкція обʼєкта наразі недоступна.`));
    }
    if (node.id instanceof ArrayDestructionNode) {
      this.mavka.fall(context, this.mavka.makeText(`Деструкція списку наразі недоступна.`));
    }

    const value = await this.mavka.runAsync(context, node.wait ? new WaitNode(context, { value: node.value }) : node.value);

    if (node.setElement) {
      const val = await this.mavka.runAsync(context, node.id);
      const element = await this.mavka.runAsync(context, node.setElement);

      val.doSetElement(context, element, value);
    } else if (node.id instanceof IdentifierNode) {
      context.set(node.id.name, value);
    } else {
      const val = await this.mavka.runAsync(context, node.id.left);

      val.set(context, node.id.right.name, value);
    }

    return value;
  }
}

export default AssignInstruction;
