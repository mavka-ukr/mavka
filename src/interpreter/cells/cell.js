/**
 * Cell represents a value in Mavka.
 */
export class Cell {
  /**
   * @param {Mavka} mavka
   * @param {string} name
   * @param {Object} properties
   * @param {Object} methods
   * @param {Cell|null} parent
   * @param {StructureCell} structure
   */
  constructor(mavka,
              name,
              properties = {},
              methods = {},
              parent = null,
              structure = null) {
    this.mavka = mavka;

    this.name = name;
    this.properties = properties;
    this.methods = methods;

    this.parent = parent;
    this.structure = structure;
  }

  /**
   * @param {string} name
   * @returns {Cell}
   */
  get(name) {
    if (name === "__структура__") {
      return this.structure || this.mavka.emptyCellInstance;
    }

    if (name === "__батько__") {
      return this.parent || this.mavka.emptyCellInstance;
    }

    if (name in this.properties) {
      return this.properties[name];
    }

    if (name in this.methods) {
      return this.methods[name];
    }

    if (this.parent) {
      return this.parent.get(name);
    }

    if (this.structure) {
      if (name in this.structure.methods) {
        return this.structure.methods[name];
      }
    }

    return this.mavka.emptyCellInstance;
  }

  has(name) {
    if (name === "__структура__") {
      return !this.mavka.isEmpty(this.structure);
    }

    if (name === "__батько__") {
      return !this.mavka.isEmpty(this.parent);
    }

    if (name in this.properties) {
      return true;
    }

    if (name in this.methods) {
      return true;
    }

    if (this.parent) {
      return this.parent.has(name);
    }

    if (this.structure) {
      if (name in this.structure.methods) {
        return true;
      }
    }

    return false;
  }

  /**
   * @param {string} name
   * @param {Cell} value
   */
  set(name, value) {
    this.properties[name] = this.mavka.toCell(value);
  }

  call(context, args, options = {}) {
    throw "Не реалізовано.";
  }

  /**
   * @param {Cell} value
   */
  plus(context, value) {
    const plusDiia = this.get("виконати_додавання");

    if (!this.mavka.isEmpty(plusDiia)) {
      return plusDiia.call(context, [value], {
        meValue: this
      });
    }

    throw "Не реалізовано.";
  }

  /**
   * @param {Cell} value
   */
  minus(context, value) {
    const minusDiia = this.get("виконати_віднімання");

    if (!this.mavka.isEmpty(minusDiia)) {
      return minusDiia.call(context, [value], {
        meValue: this
      });
    }

    throw "Не реалізовано.";
  }

  /**
   * @param {Cell} value
   */
  multiply(context, value) {
    const multiplyDiia = this.get("виконати_множення");

    if (!this.mavka.isEmpty(multiplyDiia)) {
      return multiplyDiia.call(context, [value], {
        meValue: this
      });
    }

    throw "Не реалізовано.";
  }

  /**
   * @param {Cell} value
   */
  divide(context, value) {
    const divideDiia = this.get("виконати_ділення");

    if (!this.mavka.isEmpty(divideDiia)) {
      return divideDiia.call(context, [value], {
        meValue: this
      });
    }

    throw "Не реалізовано.";
  }

  /**
   * @param {Cell} value
   */
  equals(value) {
    return this.compare(value, (a, b) => a === b);
  }

  /**
   * @param {Cell} value
   */
  notEquals(value) {
    return this.compare(value, (a, b) => a !== b);
  }

  /**
   * @param {Cell} value
   */
  greaterThan(value) {
    return this.compare(value, (a, b) => a > b);
  }

  /**
   * @param {Cell} value
   */
  lesserThan(value) {
    return this.compare(value, (a, b) => a < b);
  }

  /**
   * @param {Cell} value
   */
  greaterThanOrEquals(value) {
    return this.compare(value, (a, b) => a >= b);
  }

  /**
   * @param {Cell} value
   */
  lesserThanOrEquals(value) {
    return this.compare(value, (a, b) => a <= b);
  }

  /**
   * @param {Cell} value
   */
  isInstanceOf(value) {
    return this.mavka.toCell(
      this.structure
        ? this.structure === value || this.isInstanceOfThroughStructure(this.structure, value)
        : false
    );
  }

  /**
   * @param {StructureCell} structure
   * @param {Cell} value
   */
  isInstanceOfThroughStructure(structure, value) {
    return structure.parent
      ? structure.parent === value || structure.parent.isInstanceOfThroughStructure(structure.parent, value)
      : false;
  }

  /**
   * @return {NumberCell}
   */
  asNumber() {
    throw "Не реалізовано.";
  }

  /**
   * @return {StringCell}
   */
  asString() {
    const properties = Object.entries(this.properties)
      .map(([k, v]) => `${k}=${v.asPrettyString().asJsValue()}`)
      .join(", ");

    return this.mavka.toCell(`${this.name}(${properties})`);
  }

  asPrettyString() {
    return this.asString();
  }

  /**
   * @return {BooleanCell}
   */
  asBoolean() {
    return this.mavka.toCell(true);
  }

  asJsValue() {
    const jsObject = {};

    Object.entries(this.properties)
      .forEach(([k, v]) => {
        if (this.get("__оминати_пустоту_конвертуючи__").asBoolean().asJsValue()) {
          if (this.mavka.isEmpty(v)) {
            return;
          }
        }

        jsObject[k] = v.asJsValue();
      });

    return jsObject;
  }

  /**
   * @param {Cell} value
   * @param {function} fn
   * @return {BooleanCell}
   */
  compare(value, fn) {
    if (value instanceof Cell) {
      return this.mavka.toCell(fn(this, value));
    }

    return this.mavka.falseCellInstance;
  }

  [Symbol.iterator]() {
    return {
      next() {
        return { done: true };
      }
    };
  }
}

