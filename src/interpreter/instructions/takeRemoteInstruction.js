import Instruction from "./utils/instruction.js";

function doOperation(mavka, context, node) {
  const takeAsyncCell = new mavka.AsyncCell(mavka, async () => {
    mavka.events.emit("module::load::remote::start", {
      url: node.url,
      progress: 0
    });
    await mavka.loader.loadRemote(context, node.url, {
      onProgress: (progress) => {
        mavka.events.emit("module::load::remote::progress", {
          url: node.url,
          progress
        });
      },
      onFailed: () => {
        mavka.events.emit("module::load::remote::failed", {
          url: node.url
        });
      }
    });
    mavka.events.emit("module::load::remote::stop", {
      url: node.url,
      progress: 100
    });

    return mavka.empty;
  });

  return new mavka.AwaitCell(mavka, takeAsyncCell);
}

class TakeRemoteInstruction extends Instruction {
  /**
   * @param {Context} context
   * @param {TakeRemoteNode} node
   * @returns {*}
   */
  runSync(context, node) {
    this.mavka.fall(context, this.mavka.makeText("Не можна брати модулі в звичайному контексті."));
  }

  /**
   * @param {Context} context
   * @param {TakeRemoteNode} node
   * @returns {Promise<*>}
   */
  async runAsync(context, node) {
    return doOperation(this.mavka, context, node);
  }
}

export default TakeRemoteInstruction;
