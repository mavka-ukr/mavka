import { Cell } from "./cells/common/cell.js";

export class RangeCell extends Cell {
  constructor(mavka, from, to, step) {
    super(mavka, "Діапазон");

    this.from = from.asJsValue(context);
    this.to = to.asJsValue(context);
    this.step = step ? step.asJsValue(context) : null;
  }

  * [Symbol.iterator]() {
    let value = this.from;

    while (value <= this.to) {
      yield this.mavka.makeNumber(value);

      value += this.step;
    }
  }
}

export class RangeDiiaCell extends Cell {
  doCall(context, args) {
    if (Array.isArray(args)) {
      return new this.mavka.RangeCell(this.mavka, args[0], args[1], args[2] || this.mavka.makeNumber(1));
    } else {
      return new this.mavka.RangeCell(this.mavka, args["від"], args["до"], args["крок"] || this.mavka.makeNumber(1));
    }
  }
}
