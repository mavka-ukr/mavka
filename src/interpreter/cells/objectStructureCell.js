import { Cell } from "./utils/cell.js";

class ObjectStructureCell extends Cell {
  /**
   * @param {Mavka} mavka
   */
  constructor(mavka) {
    super(mavka, `<структура обʼєкт>`);
  }

  getParams() {
    return [];
  }

  doCall(context, args, options = {}) {
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
  }
}

export default ObjectStructureCell;
