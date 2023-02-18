import { Cell } from "./cell.js";
import NumberCell from "./numberCell.js";
import StringCell from "./stringCell.js";
import BooleanCell from "./booleanCell.js";
import ListCell from "./listCell.js";

export class StructureConstructorCell extends Cell {
  /**
   * @param {Mavka} mavka
   * @param {Context} context
   * @param {StructureNode} node
   */
  constructor(mavka, context, node) {
    super(mavka, context);

    this.context = context;
    this.node = node;
  }

  call(context, args) {
    const structure = new this.mavka.StructureCell(this.mavka, this.node.name.name);

    if (Array.isArray(args)) {
      for (const [k, param] of Object.entries(this.node.params)) {
        let value = args[k];
        if (!value) {
          value = this.mavka.runSync(this.context, param.defaultValue);
        }
        structure.set(param.name.name, value);
      }
    } else {
      for (const param of this.node.params) {
        let value = args[param.name];
        if (!value) {
          value = this.mavka.runSync(this.context, param.defaultValue);
        }
        structure.set(param.name.name, value);
      }
    }

    for (const method of this.node.methods) {
      const context = new this.mavka.Context(this.mavka, this.context);
      context.set("я", structure);
      structure.set(method.name.name, new this.mavka.diiaCell(this.mavka, context, method));
    }

    return structure;
  }

  asString() {
    return this.mavka.toCell(`структура ${this.node.name.name}`);
  }
}

export class ListConstructorCell extends Cell {
  /**
   * @param {Mavka} mavka
   * @param {Context} context
   */
  constructor(mavka, context) {
    super(mavka, context);

    this.context = context;
  }

  call(context, args) {
    const values = [];

    for (const arg of args) {
      values.push(arg);
    }

    return new this.mavka.ListCell(this.mavka, values);
  }

  asString() {
    return this.mavka.toCell(`структура Список`);
  }
}

class StructureCell extends Cell {
  constructor(mavka, name) {
    super(mavka);

    this.name = name;
  }

  asString() {
    const properties = Object.entries(this.properties)
      .map(([k, v]) => `${k}=${this.mavka.toCell(v).asString().asJsString()}`)
      .join(", ");

    return this.mavka.toCell(`${this.name}(${properties})`);
  }

  asJsValue() {
    const jsObject = {};

    Object.entries(this.properties)
      .forEach(([k, v]) => {
        if (v instanceof NumberCell) {
          jsObject[k] = v.asJsValue();
        }
        if (v instanceof StringCell) {
          jsObject[k] = v.asJsValue();
        }
        if (v instanceof BooleanCell) {
          jsObject[k] = v.asJsValue();
        }
        if (v instanceof StructureCell) {
          jsObject[k] = v.asJsValue();
        }
        if (v instanceof ListCell) {
          jsObject[k] = v.asJsValue();
        }
      });

    return jsObject;
  }

  asBoolean() {
    return this.mavka.toCell(true);
  }

  compare(value, fn) {
    if (value instanceof StructureCell) {
      return this.mavka.toCell(fn(this, value));
    }

    return this.mavka.toCell(false);
  }
}

export default StructureCell;
