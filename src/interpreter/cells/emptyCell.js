import { Cell } from "./cell.js";
import { ThrowValue } from "../instructions/throwInstruction.js";

class EmptyCell extends Cell {
  get(name) {
    throw new ThrowValue(this, this.mavka.toCell(`Неможливо отримати "${name}" з пустоти.`));
  }

  set(name, value) {
    throw new ThrowValue(this, this.mavka.toCell(`Неможливо встановити "${name}" на пустоту.`));
  }

  call(context) {
    throw new ThrowValue(this, this.mavka.toCell(`Неможливо викликати пустоту.`));
  }

  asString() {
    return this.mavka.toCell("пусто");
  }

  asJsValue() {
    return null;
  }

  asBoolean() {
    return this.mavka.toCell(false);
  }
}

export default EmptyCell;
