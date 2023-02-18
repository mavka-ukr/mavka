/**
 * Cell represents a value in Mavka.
 */
export class Cell {
  /**
   * @param {Mavka} mavka
   * @param {Object} properties
   */
  constructor(mavka, properties = {}) {
    this.mavka = mavka;
    this.properties = properties;
  }

  /**
   * @param {string} name
   * @returns {Cell}
   */
  get(name) {
    return this.mavka.toCell(this.properties[name]);
  }

  /**
   * @param {string} name
   * @param {Cell} value
   */
  set(name, value) {
    this.properties[name] = value;
  }

  call(context) {
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
    return this.mavka.toCell("комірка");
  }

  /**
   * @return {BooleanCell}
   */
  asBoolean() {
    return true;
  }

  asJsValue() {
    throw "Не реалізовано.";
  }

  /**
   * @param {Cell} value
   * @param {function} fn
   * @return {BooleanCell}
   */
  compare(value, fn) {
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

