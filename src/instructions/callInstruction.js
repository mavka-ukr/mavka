import Instruction from "./instruction.js";
import ArgNode from "mavka-parser/src/ast/ArgNode.js";

class CallInstruction extends Instruction {
  /**
   * @param {Scope} scope
   * @param {CallNode} node
   * @returns {*}
   */
  async compile(scope, node) {
    const debugInfoVarName = this.mavka.putDebugInfoVarName(node);

    const value = await this.mavka.compileNode(scope, node.value);

    if (Array.isArray(node.args)) {
      const args = await Promise.all(node.args.map(async (arg) => {
        if (arg instanceof ArgNode) {
          if (arg.spread) {
            return `...${await this.mavka.compileNode(scope, arg.value)}`;
          }
          return await this.mavka.compileNode(scope, arg.value);
        }
        return await this.mavka.compileNode(scope, arg);
      }));

      return `mavka_call(${value}, [${args.join(", ")}], ${debugInfoVarName})`;
    } else {
      const args = await Promise.all(Object.entries(node.args).map(async ([name, value]) => {
        value = await this.mavka.compileNode(scope, value);
        return `${name}: ${value}`;
      }));

      return `mavka_call(${value}, { ${args.join(", ")} }, ${debugInfoVarName})`;
    }
  }
}

export default CallInstruction;
