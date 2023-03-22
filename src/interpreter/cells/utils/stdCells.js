import { Cell } from "./cell.js";
import DiiaCell from "../diiaCell.js";

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
      yield new this.mavka.NumberCell(this.mavka, value);

      value += this.step;
    }
  }
}

export class RangeDiiaCell extends DiiaCell {
  doCall(context, args) {
    if (Array.isArray(args)) {
      return new this.mavka.RangeCell(this.mavka, args[0], args[1], args[2] || new this.mavka.NumberCell(this.mavka, 1));
    } else {
      return new this.mavka.RangeCell(this.mavka, args["від"], args["до"], args["крок"] || new this.mavka.NumberCell(this.mavka, 1));
    }
  }
}
