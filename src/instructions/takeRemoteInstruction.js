import Instruction from "./instruction.js";

class TakeRemoteInstruction extends Instruction {
  /**
   * @param {Scope} scope
   * @param {TakeRemoteNode} node
   * @param {*}options
   * @returns {Promise<string>}
   */
  async compile(scope, node, options) {
    const diName = this.mavka.putDebugInfoVarName(node);
    const di = this.mavka.debugInfoVarNames.get(diName);

    const name = node.url.split("/")[0];
    const version = node.url.split("/")[1];

    if (version) {
      return await this.mavka.loadRemoteModule(name, node.as, version, di, options);
    }

    return await this.mavka.loadBuiltinModule(node.url, node.as, di, options);
  }
}

export default TakeRemoteInstruction;
