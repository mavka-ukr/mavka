import Instruction from "./instruction.js";

class TakeInstruction extends Instruction {
  commonRun(context, node) {
    return new this.mavka.WaitCell(this.mavka, new this.mavka.AsyncCell(this.mavka, new Promise((resolve) => {
      (async () => {
        let moduleName = node.name;

        let loadedContext = await this.mavka.loader.load(context, moduleName, node.pak);

        const giveContext = loadedContext.get("__give_context__");

        if (node.chain) {
          let k = node.chain.identifiers[0];

          let value = giveContext.get(k);

          for (k of node.chain.identifiers.slice(1)) {
            value = value.get(k);
          }

          context.set(node.as ? node.as : k, value);

          resolve(value);
        } else {
          const module = new this.mavka.ModuleCell(this.mavka, moduleName, giveContext);

          context.set(node.as ? node.as : node.name, module);

          resolve(module);
        }
      })();
    })));
  }

  /**
   * @param {Context} context
   * @param {TakeNode} node
   * @returns {*}
   */
  runSync(context, node) {
    return this.commonRun(context, node);
  }

  /**
   * @param {Context} context
   * @param {TakeNode} node
   * @returns {Promise<*>}
   */
  async runAsync(context, node) {
    return this.commonRun(context, node);
  }
}

export default TakeInstruction;
