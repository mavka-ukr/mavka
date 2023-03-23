import { Cell } from "./utils/cell.js";

class EmptyCell extends Cell {
  constructor(mavka) {
    super(mavka, "<пусто>");

    this.structure = this;
  }

  get(context, name) {
    throw new this.mavka.ThrowValue(this, this.mavka.toCell(`Неможливо отримати "${name}" з пустоти.`));
  }

  set(context, name, value) {
    throw new this.mavka.ThrowValue(this, this.mavka.toCell(`Неможливо встановити "${name}" на пустоту.`));
  }

  doCall(context) {
    throw new this.mavka.ThrowValue(this, this.mavka.toCell(`Неможливо викликати пустоту.`));
  }

  asText(context) {
    return this.mavka.toCell("пусто");
  }

  asJsValue(context) {
    return null;
  }

  asBoolean() {
    return this.mavka.toCell(false);
  }
}

export default EmptyCell;
