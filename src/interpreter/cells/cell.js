/**
 * Cell represents a value in Mavka.
 */
export class Cell {
  static DEFAULT_NAME = "Об'єкт";

  static PROTOTYPE_PROPERTY_NAME = "__прототип__";

  static HIDDEN_PROPERTIES = [Cell.PROTOTYPE_PROPERTY_NAME, "прототип", "структура", "створити", "створено"];

  /**
   * @param {Mavka} mavka
   * @param {string} name
   * @param {Object} properties
   * @param {Object} options
   */
  constructor(mavka, name, properties = {}, options = {}) {
    this.mavka = mavka;

    this.name = name;
    this.properties = properties;

    this.options = options;
  }

  /**
   * @param {string} name
   * @returns {Cell}
   */
  get(name) {
    if (name in this.properties) {
      return this.mavka.toCell(this.properties[name]);
    }

    if (this.hasPrototype()) {
      return this.mavka.toCell(this.getPrototype().get(name));
    }

    return this.mavka.emptyCellInstance;
  }

  has(name) {
    if (name in this.properties) {
      return true;
    }

    if (this.hasPrototype()) {
      return this.getPrototype().has(name);
    }

    return false;
  }

  /**
   * @param {string} name
   * @param {Cell} value
   */
  set(name, value) {
    this.properties[name] = value;
  }

  call(context, args, options = {}) {
    throw "Не реалізовано.";
  }

  /**
   * @param {Cell} value
   */
  plus(value) {
    throw "Не реалізовано.";
  }

  /**
   * @param {Cell} value
   */
  minus(value) {
    throw "Не реалізовано.";
  }

  /**
   * @param {Cell} value
   */
  multiply(value) {
    throw "Не реалізовано.";
  }

  /**
   * @param {Cell} value
   */
  divide(value) {
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
      .filter(([k]) => {
        if (this.has(Cell.PROTOTYPE_PROPERTY_NAME)) {
          if (this.get(Cell.PROTOTYPE_PROPERTY_NAME).has("структура")) {
            const params = this.get(Cell.PROTOTYPE_PROPERTY_NAME).get("структура").getParams();

            return !!params.find((param) => param.name.name === k);
          }
        }

        return true;
      })
      .map(([k, v]) => `${k}=${this.mavka.toCell(v).asPrettyString().asJsValue()}`)
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

  getPrototype() {
    return this.properties[Cell.PROTOTYPE_PROPERTY_NAME];
  }

  hasPrototype() {
    return !this.mavka.isEmpty(this.getPrototype());
  }
}

