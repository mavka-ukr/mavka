import { Cell } from "./cell.js";

class FunctionCell extends Cell {
  /**
   * @param {Mavka} mavka
   * @param {Context} context
   * @param {FunctionNode} node
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
    const runContext = new this.mavka.LambdaContext(this.mavka, this.context);

    if (Array.isArray(args)) {
      for (const [k, param] of Object.entries(this.node.params)) {
        let value = args[k];

        if (value == null) {
          if (param.defaultValue) {
            value = this.mavka.runSync(runContext, param.defaultValue);
          } else {
            value = this.mavka.emptyCellInstance;
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
            value = this.mavka.emptyCellInstance;
          }
        }

        runContext.set(param.name.name, value);
      }
    }

    return this.mavka.run(runContext, this.node.body);
  }

  asString() {
    return this.mavka.toCell("Функція");
  }
}

export default FunctionCell;
