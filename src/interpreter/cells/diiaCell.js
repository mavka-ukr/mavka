import { ReturnValue } from "../instructions/returnInstruction.js";
import { Cell } from "./cell.js";
import { runParams } from "../../std/tools.js";

class DiiaCell extends Cell {
  /**
   * @param {Mavka} mavka
   * @param {Context} context
   * @param {DiiaNode|AnonymousDiiaNode} node
   */
  constructor(mavka, context, node) {
    super(mavka, "Дія");

    this.node = node;
    this.context = context;

    this.meValue = this.mavka.emptyCellInstance;

    this.defaultValues = {};

    this.contextClass = this.mavka.Context;
  }

  /**
   * @param {Context} context
   * @param {Array|Object} args
   * @param {Object} options
   * @return {Cell|Promise<Cell>}
   */
  call(context, args, options = {}) {
    const runContext = new this.contextClass(this.mavka, this.context);

    if (!this.mavka.isEmpty(this.meValue)) {
      runContext.set("я", this.meValue);
    } else if (!this.mavka.isEmpty(options.meValue)) {
      runContext.set("я", options.meValue);
    }

    if (this.node.async) {
      runContext.setAsync(true);
    }

    runParams(this.mavka, runContext, runContext, this.node.params, args, this.defaultValues);

    let result = this.mavka.run(runContext, this.node.body);

    if (result instanceof ReturnValue) {
      result = result.value;
    }

    // if (this.node.async) {
    //   if (!(result instanceof this.mavka.AsyncCell)) {
    //     result = new this.mavka.AsyncCell(this.mavka, () => result);
    //   }
    // }

    return result;
  }

  asString() {
    return this.mavka.toCell("Дія");
  }
}

export default DiiaCell;
