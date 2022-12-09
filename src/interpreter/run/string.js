import { parse } from "diia-parser";
import { runNode, runNodeAsync } from "./index.js";
import { StringVal } from "../val/index.js";

function interpolate(value) {
    const parts = [];

    let part = '';
    let interpolation = false;
    for (let i = 0; i < value.length; i++) {
        if (value[i] === '\\' && value[i + 1] === '"') {
            continue;
        }

        if (value[i] === '\\' && value[i + 1] === 'n') {
            part += '\n';
            i += 1;
            continue;
        }

        if (value[i] === '\\' && value[i + 1] === 'r') {
            i += 1;
            continue;
        }

        if (!interpolation && value[i] === '%' && value[i + 1] === '(' && value[i - 1] !== '\\') {
            interpolation = true;
            parts.push(part);
            part = '';
            i += 1;
            continue;
        }

        if (interpolation && value[i] === ')' && value[i - 1] !== '\\') {
            interpolation = false;
            parts.push(parse(part, { start: 'atom' }));
            part = '';
            continue;
        }

        part += value[i];
    }

    parts.push(part);

    return parts;
}

function runStringNode(context, node) {
    const interpolated = interpolate(node.value);

    const runSync = () => {
        let value = '';

        for (const el of interpolated) {
            if (typeof el === 'string') {
                value += el;
            } else {
                value += runNode(context, el).asString().asJsString();
            }
        }

        return new StringVal(value);
    }

    const runAsync = async () => {
        let value = '';

        for (const el of interpolated) {
            if (typeof el === 'string') {
                value += el;
            } else {
                value += (await runNodeAsync(context, el)).asString().asJsString();
            }
        }

        return new StringVal(value);
    }

    return context.vars.__async__ ? runAsync() : runSync();
}

export default runStringNode;
