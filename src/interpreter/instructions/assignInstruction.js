import Instruction from "./utils/instruction.js";
import WaitNode from "mavka-parser/src/ast/WaitNode.js";
import IdentifierNode from "mavka-parser/src/ast/IdentifierNode.js";
import ObjectDestructionNode from "mavka-parser/src/ast/ObjectDestructionNode.js";
import ArrayDestructionNode from "mavka-parser/src/ast/ArrayDestructionNode.js";

function getDoName(symbol) {
  return {
    "+=": "doAdd",
    "-=": "doSub",
    "*=": "doMul",
    "/=": "doDiv",
    "%=": "doDivMod",
    "//=": "doDivFloor",
    "**=": "doPow",
    "^=": "doXor"
  }[symbol];
}

class AssignInstruction extends Instruction {
  /**
   * @param {Context} context
   * @param {AssignNode} node
   * @returns {*}
   */
  runSync(context, node) {
    if (node.wait) {
      this.mavka.fall(context, this.mavka.makeText(`"${node.symbol}" недоступно в нетривалому контексті.`));
    }

    let value = this.mavka.runSync(context, node.value);

    const doName = getDoName(node.symbol);

    if (node.setElement) {
      if (node.symbol === ":=") {
        this.mavka.fall(context, this.mavka.makeText(`Неможливо використати ":=" для елементів списку.`));
      }

      const val = this.mavka.runSync(context, node.id);
      const element = this.mavka.runSync(context, node.setElement);

      if (node.symbol === "=") {
        val.doSetElement(context, element, value);
      } else {
        value = val.doGetElement(context, element)[doName](context, value);
        val.doSetElement(context, element, value);
      }
    } else if (node.id instanceof IdentifierNode) {
      if (node.symbol === ":=") {
        context.setHigher(node.id.name, value);
      } else if (node.symbol === "=") {
        context.set(node.id.name, value);
      } else {
        value = context.get(node.id.name)[doName](context, value);
        context.set(node.id.name, value);
      }
    } else if (node.id instanceof ObjectDestructionNode) {
      for (const element of node.id.elements) {
        context.set(element.name, value.get(context, element.name));
      }
    } else if (node.id instanceof ArrayDestructionNode) {
      for (let i = 0; i < node.id.elements.length; i++) {
        const element = node.id.elements[i];

        context.set(element.name, value.doGetElement(context, this.mavka.makeNumber(i)));
      }
    } else {
      if (node.symbol === ":=") {
        this.mavka.fall(context, this.mavka.makeText(`Неможливо використати ":=" для властивостей обʼєктів.`));
      }

      const val = this.mavka.runSync(context, node.id.left);

      if (node.symbol === "=") {
        val.set(context, node.id.right.name, value);
      } else {
        value = val.get(node.id.right.name)[doName](context, value);
        val.set(context, node.id.right.name, value);
      }
    }

    return value;
  }

  /**
   * @param {Context} context
   * @param {AssignNode} node
   * @returns {Promise<*>}
   */
  async runAsync(context, node) {
    let value = await this.mavka.runAsync(context, node.wait ? new WaitNode(context, { value: node.value }) : node.value);

    const doName = getDoName(node.symbol);

    if (node.setElement) {
      if (node.symbol === ":=") {
        this.mavka.fall(context, this.mavka.makeText(`Неможливо використати ":=" для елементів списку.`));
      }

      const val = await this.mavka.runAsync(context, node.id);
      const element = await this.mavka.runAsync(context, node.setElement);

      if (node.symbol === "=") {
        val.doSetElement(context, element, value);
      } else {
        value = val.doGetElement(context, element)[doName](context, value);
        val.doSetElement(context, element, value);
      }
    } else if (node.id instanceof IdentifierNode) {
      if (node.symbol === ":=") {
        context.setHigher(node.id.name, value);
      } else if (node.symbol === "=") {
        context.set(node.id.name, value);
      } else {
        value = context.get(node.id.name)[doName](context, value);
        context.set(node.id.name, value);
      }
    } else if (node.id instanceof ObjectDestructionNode) {
      for (const element of node.id.elements) {
        context.set(element.name, value.get(context, element.name));
      }
    } else if (node.id instanceof ArrayDestructionNode) {
      for (let i = 0; i < node.id.elements.length; i++) {
        const element = node.id.elements[i];

        context.set(element.name, value.doGetElement(context, this.mavka.makeNumber(i)));
      }
    } else {
      if (node.symbol === ":=") {
        this.mavka.fall(context, this.mavka.makeText(`Неможливо використати ":=" для властивостей обʼєктів.`));
      }

      const val = await this.mavka.runAsync(context, node.id.left);

      if (node.symbol === "=") {
        val.set(context, node.id.right.name, value);
      } else {
        value = val.get(node.id.right.name)[doName](context, value);
        val.set(context, node.id.right.name, value);
      }
    }

    return value;
  }
}

export default AssignInstruction;
