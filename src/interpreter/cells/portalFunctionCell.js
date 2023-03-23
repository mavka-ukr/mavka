import { Cell } from "./utils/cell.js";

class PortalFunctionCell extends Cell {
  constructor(mavka, fn) {
    super(mavka, "<портал функція>");

    this.fn = fn;
  }

  doCall(context, args, options = {}) {
    return this.fn(args, context, options);
  }
}

export default PortalFunctionCell;
