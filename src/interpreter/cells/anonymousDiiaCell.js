import { ReturnValue } from "../instructions/returnInstruction.js";
import { Cell } from "./cell.js";

class AnonymousDiiaCell extends Cell {
  /**
   * @param {Mavka} mavka
   * @param {Context} context
   * @param {AnonymousDiiaNode} node
   */
  constructor(mavka, context, node) {
    super(mavka);

    this.context = context;
    this.node = node;
  }

  /**
   * @param {Context} context
   * @param {Array|Object} args
   * @return {Cell|Promise<Cell>}
   */
  call(context, args) {
    const runContext = new this.mavka.Context(this.mavka, this.context);

    if (this.node.async) {
      runContext.setAsync(true);
    }

    if (Array.isArray(args)) {
      for (const [k, param] of Object.entries(this.node.params)) {
        let value = args[k];

        if (value == null) {
          if (param.defaultValue) {
            value = this.mavka.runSync(runContext, param.defaultValue);
          } else {
            value = new this.mavka.EmptyCell(this.mavka);
          }
        }

        runContext.set(param.name.name, value);
      }
    } else {
      for (const param of this.node.params) {
        let value = args[param.name.name];

        if (value == null) {
          if (param.defaultValue) {
            value = this.mavka.runSync(runContext, param.defaultValue);
          } else {
            value = new this.mavka.EmptyCell(this.mavka);
          }
        }

        runContext.set(param.name.name, value);
      }
    }

    let result = this.mavka.run(runContext, this.node.body);

    if (result instanceof ReturnValue) {
      result = result.value;
    }

    if (this.node.async) {
      if (!(result instanceof this.mavka.AsyncCell)) {
        result = new this.mavka.AsyncCell(this.mavka, new Promise((resolve) => {
          resolve(result);
        }));
      }
    }

    return result;
  }

  asString() {
    return this.mavka.toCell("АнонімнаДія");
  }
}

export default AnonymousDiiaCell;
