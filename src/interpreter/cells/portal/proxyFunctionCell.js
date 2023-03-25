import { Cell } from "../common/cell.js";

class ProxyFunctionCell extends Cell {
  /**
   * @param {Mavka} mavka
   * @param {function} fn
   * @param {boolean} isAsync
   * @param {boolean} isWrapped
   */
  constructor(mavka, fn, isAsync = false, isWrapped = false) {
    super(
      mavka,
      "<проксі функція>",
      {},
      mavka.diiaStructureCellInstance,
      () => this.meta.fn,
      null,
      {
        fn,
        isAsync,
        isWrapped
      }
    );
  }

  /**
   * @inheritDoc
   */
  doCall(context, args, options = {}) {
    if (this.meta.isWrapped) {
      args = Object.values(args).map((arg) => arg.asJsValue(context));
    }

    if (this.meta.isAsync) {
      return new this.mavka.AsyncCell(this.mavka, async () => {
        let result = await this.meta.fn(args, context, options);

        if (this.meta.isWrapped) {
          result = this.mavka.toCell(result);
        }

        return result;
      });
    } else {
      let result = this.meta.fn(args, context, options);

      if (this.meta.isWrapped) {
        result = this.mavka.toCell(result);
      }

      return result;
    }
  }
}

export default ProxyFunctionCell;
