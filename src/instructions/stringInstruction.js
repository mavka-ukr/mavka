import Instruction from "./instruction.js";
import { parse } from "mavka-parser";

function interpolate(value) {
  const parts = [];

  let part = "";
  let interpolation = false;
  for (let i = 0; i < value.length; i++) {
    if (!interpolation && value[i] === "%" && value[i + 1] === "(" && value[i - 1] !== "\\") {
      interpolation = true;
      parts.push(part);
      part = "";
      i += 1;
      continue;
    }

    if (interpolation && value[i] === ")" && value[i - 1] !== "\\") {
      interpolation = false;
      const program = parse(part);
      parts.push(program.body[0]);
      part = "";
      continue;
    }

    part += value[i];
  }

  parts.push(part);

  return parts;
}

class StringInstruction extends Instruction {
  /**
   * @param {Scope} scope
   * @param {StringNode} node
   * @returns {*}
   */
  async compile(scope, node) {
    const debugInfoVarName = this.mavka.putDebugInfoVarName(node);
    const interpolated = interpolate(node.value);

    const inner = [];

    for (const el of interpolated) {
      if (typeof el === "string") {
        inner.push(`"${el.replaceAll("\n", "\\n")}"`);
      } else {
        inner.push(`to_string(${await this.mavka.compileNode(scope, el)}, ${debugInfoVarName})`);
      }
    }

    if (inner.length === 1) {
      return inner[0];
    }

    return "(" + inner.join("+") + ")";
  }
}

export default StringInstruction;
