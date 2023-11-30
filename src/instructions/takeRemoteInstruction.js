import Instruction from "./instruction.js";
import semver from "semver";

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

    const [, version] = node.url.split("/");

    if (version && semver.valid(version) !== null) {
      return await this.mavka.loadRemoteModule(node.url.split("/"), node.as, di, options);
    }

    return await this.mavka.loadBuiltinModule(node.url.split("/"), node.as, di, options);
  }
}

export default TakeRemoteInstruction;
