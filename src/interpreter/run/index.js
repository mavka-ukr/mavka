import { AsyncVal, WaitVal } from "../val/index.js";
import ChainNode from "diia-parser/src/ast/ChainNode.js";
import ArithmeticNode from "diia-parser/src/ast/ArithmeticNode.js";
import NumberNode from "diia-parser/src/ast/NumberNode.js";
import StringNode from "diia-parser/src/ast/StringNode.js";
import BooleanNode from "diia-parser/src/ast/BooleanNode.js";
import DiiaNode from "diia-parser/src/ast/DiiaNode.js";
import LambdaNode from "diia-parser/src/ast/LambdaNode.js";
import IfNode from "diia-parser/src/ast/IfNode.js";
import TestNode from "diia-parser/src/ast/TestNode.js";
import AssignNode from "diia-parser/src/ast/AssignNode.js";
import ReturnNode from "diia-parser/src/ast/ReturnNode.js";
import EachNode from "diia-parser/src/ast/EachNode.js";
import StructureNode from "diia-parser/src/ast/StructureNode.js";
import WaitChainNode from "diia-parser/src/ast/WaitChainNode.js";
import NestedArithmeticNode from "diia-parser/src/ast/NestedArithmeticNode.js";
import runChainNode from "./chain.js";
import runArithmeticNode from "./arithmetic.js";
import runNumberNode from "./number.js";
import runStringNode from "./string.js";
import runBooleanNode from "./boolean.js";
import runDiiaNode from "./diia.js";
import runLambdaNode from "./lambda.js";
import runIfNode from "./if.js";
import runTestNode from "./test.js";
import runAssignNode from "./assign.js";
import runReturnNode from "./return.js";
import runEachNode from "./each.js";
import runStructureNode from "./structure.js";
import runWaitChainNode from "./wait.js";
import TakeNode from "diia-parser/src/ast/TakeNode.js";
import runTakeNode from "./take.js";
import GiveNode from "diia-parser/src/ast/GiveNode.js";
import runGiveNode from "./give.js";

export class ReturnValue {
    constructor(value) {
        this.value = value;
    }
}

export function run(context, nodes) {
    nodes = nodes || [];

    const runSync = () => {
        let result;

        for (const node of nodes) {
            result = runNode(context, node);

            if (result instanceof ReturnValue) {
                return result;
            }
        }

        return result;
    }

    const runAsync = async () => {
        let result;

        for (const node of nodes) {
            result = await runNodeAsync(context, node);

            if (result instanceof ReturnValue) {
                return result;
            }
        }

        return result;
    }

    return context.vars.__async__ ? runAsync() : runSync();
}

export function runNode(context, node) {
    if (node instanceof ChainNode) {
        return runChainNode(context, node);
    }

    if (node instanceof ArithmeticNode) {
        return runArithmeticNode(context, node);
    }

    if (node instanceof NumberNode) {
        return runNumberNode(context, node);
    }

    if (node instanceof StringNode) {
        return runStringNode(context, node);
    }

    if (node instanceof BooleanNode) {
        return runBooleanNode(context, node);
    }

    if (node instanceof DiiaNode) {
        return runDiiaNode(context, node);
    }

    if (node instanceof LambdaNode) {
        return runLambdaNode(context, node);
    }

    if (node instanceof IfNode) {
        return runIfNode(context, node);
    }

    if (node instanceof TestNode) {
        return runTestNode(context, node);
    }

    if (node instanceof AssignNode) {
        return runAssignNode(context, node);
    }

    if (node instanceof ReturnNode) {
        return runReturnNode(context, node);
    }

    if (node instanceof EachNode) {
        return runEachNode(context, node);
    }

    if (node instanceof StructureNode) {
        return runStructureNode(context, node);
    }

    if (node instanceof WaitChainNode) {
        return runWaitChainNode(context, node);
    }

    if (node instanceof NestedArithmeticNode) {
        return runNode(context, node.arithmetic);
    }

    if (node instanceof TakeNode) {
        return runTakeNode(context, node);
    }

    if (node instanceof GiveNode) {
        return runGiveNode(context, node);
    }
}

export async function runNodeAsync(context, node) {
    let value = await runNode(context, node);

    if (value instanceof WaitVal) {
        value = await value.properties.__value__;

        if (value instanceof AsyncVal) {
            value = await value.getPromise();
        }
    }

    return value;
}
