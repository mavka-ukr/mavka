import { Cell } from "./cell.js";

class AsyncCell extends Cell {
  /**
   * @param {Mavka} mavka
   * @param {Promise} promise
   */
  constructor(mavka, promise) {
    super(mavka, {
      "__promise__": promise
    });
  }

  /**
   * @return {Promise}
   */
  getPromise() {
    return this.properties["__promise__"];
  }

  asString() {
    return this.mavka.toCell("ТривалаОперація");
  }
}

export default AsyncCell;
