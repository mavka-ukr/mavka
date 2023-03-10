import { Cell } from "./cell.js";
import DiiaCell from "./diiaCell.js";

export class ProxyFunctionCell extends Cell {
  constructor(mavka, fn) {
    super(mavka, "ПроксіФункція");

    this.fn = fn;
  }

  call(context, args) {
    return this.fn(args, context);
  }

  asString() {
    return this.mavka.toCell("ПроксіФункція");
  }
}

export class RangeCell extends Cell {
  constructor(mavka, from, to, step) {
    super(mavka, "Діапазон");

    this.from = from.asJsNumber();
    this.to = to.asJsNumber();
    this.step = step ? step.asJsNumber() : null;
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
  call(context, args) {
    if (Array.isArray(args)) {
      return new this.mavka.RangeCell(this.mavka, args[0], args[1], args[2] || new this.mavka.NumberCell(this.mavka, 1));
    } else {
      return new this.mavka.RangeCell(this.mavka, args["від"], args["до"], args["крок"] || new this.mavka.NumberCell(this.mavka, 1));
    }
  }
}
