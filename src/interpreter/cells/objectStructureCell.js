import { Cell } from "./utils/cell.js";

class ObjectStructureCell extends Cell {
  /**
   * @param {Mavka} mavka
   */
  constructor(mavka) {
    super(mavka, `<структура обʼєкт>`);

    this.methods["виконати_виклик"] = this.mavka.tools.fn(
      (args) => {
        const properties = {};

        if (Array.isArray(args)) {
          args.forEach((v, k) => {
            properties[k] = v;
          });
        } else {
          Object.entries(args).forEach(([k, v]) => {
            properties[k] = v;
          });
        }

        return new this.mavka.ObjectCell(this.mavka, properties);
      },
      { jsArgs: false }
    );

    this.methods["виконати_перетворення_на_текст"] = this.mavka.tools.fn(
      (args, context, options) => {
        const properties = Object.entries(options.meValue.properties)
          .map(([k, v]) => `${k}=${v.asText(context).asJsValue(context)}`)
          .join(", ");

        return this.mavka.toCell(`обʼєкт(${properties})`);
      },
      { jsArgs: false }
    );
  }

  getParams() {
    return [];
  }
}

export default ObjectStructureCell;
