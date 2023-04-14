import { Cell } from "../common/cell.js";

/**
 * Convert JS-function to diia-cell.
 */
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
      if (Array.isArray(args)) {
        args = Object.values(args).map((arg) => arg.asJsValue(context));
      } else {
        const newArgs = {};
        Object.entries(args).forEach(([name, arg]) => {
          newArgs[name] = arg.asJsValue(context);
        });
        args = newArgs;
      }
    }

    const getArgument = (position, name) => {
      if (Array.isArray(args)) {
        if (args[position]) {
          return args[position];
        }

        return this.meta.isWrapped ? null : this.mavka.empty;
      } else {
        if (name in args) {
          return args[name];
        }

        return this.meta.isWrapped ? null : this.mavka.empty;
      }
    };

    if (this.meta.isAsync) {
      return new this.mavka.AsyncCell(this.mavka, async () => {
        let result = await this.meta.fn(args, context, { ...options, arg: getArgument });

        if (this.meta.isWrapped) {
          result = this.mavka.toCell(result);
        }

        return result;
      });
    } else {
      let result = this.meta.fn(args, context, { ...options, arg: getArgument });

      if (this.meta.isWrapped) {
        result = this.mavka.toCell(result);
      }

      return result;
    }
  }
}

export default ProxyFunctionCell;
