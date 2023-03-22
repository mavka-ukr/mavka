import { Cell } from "./utils/cell.js";

class AsyncCell extends Cell {
  /**
   * @param {Mavka} mavka
   * @param {Promise} promise
   */
  constructor(mavka, promise) {
    super(mavka, "<тривала операція>");

    this.promise = promise;
  }

  /**
   * @return {Promise}
   */
  getPromise() {
    return this.promise;
  }
}

export default AsyncCell;
