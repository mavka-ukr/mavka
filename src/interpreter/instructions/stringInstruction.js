import Instruction from "./utils/instruction.js";
import { parse } from "mavka-parser";

function interpolate(value) {
  const parts = [];

  let part = "";
  let interpolation = false;
  for (let i = 0; i < value.length; i++) {
    if (value[i] === "\\" && value[i + 1] === "\"") {
      continue;
    }

    if (value[i] === "\\" && value[i + 1] === "n") {
      part += "\n";
      i += 1;
      continue;
    }

    if (value[i] === "\\" && value[i + 1] === "r") {
      i += 1;
      continue;
    }

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
   * @param {Context} context
   * @param {StringNode} node
   * @returns {*}
   */
  runSync(context, node) {
    const interpolated = interpolate(node.value);

    let value = "";

    for (const el of interpolated) {
      if (typeof el === "string") {
        value += el;
      } else {
        value += this.mavka.runSync(context, el).asText(context).asJsValue();
      }
    }

    return this.mavka.makeText(value);
  }

  /**
   * @param {Context} context
   * @param {StringNode} node
   * @returns {Promise<*>}
   */
  async runAsync(context, node) {
    const interpolated = interpolate(node.value);

    let value = "";

    for (const el of interpolated) {
      if (typeof el === "string") {
        value += el;
      } else {
        value += (await this.mavka.runAsync(context, el)).asText(context).asJsValue();
      }
    }

    return this.mavka.makeText(value);
  }
}

export default StringInstruction;
