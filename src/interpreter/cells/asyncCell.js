import { Cell } from "./cell.js";

class AsyncCell extends Cell {
  /**
   * @param {Mavka} mavka
   * @param {Promise} promise
   */
  constructor(mavka, promise) {
    super(mavka, "ТривалаОперація");

    this.promise = promise;
  }

  /**
   * @return {Promise}
   */
  getPromise() {
    return this.promise;
  }

  asString() {
    return this.mavka.toCell("ТривалаОперація");
  }
}

export default AsyncCell;
