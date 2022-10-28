import NumberNode from "diia-parser/src/ast/NumberNode.js";
import StringNode from "diia-parser/src/ast/StringNode.js";
import BooleanNode from "diia-parser/src/ast/BooleanNode.js";
import IdentifierNode from "diia-parser/src/ast/IdentifierNode.js";
import CallNode from "diia-parser/src/ast/CallNode.js";
import AssignNode from "diia-parser/src/ast/AssignNode.js";
import DiiaNode from "diia-parser/src/ast/DiiaNode.js";
import ChainNode from "diia-parser/src/ast/ChainNode.js";
import ArithmeticNode from "diia-parser/src/ast/ArithmeticNode.js";
import NestedArithmeticNode from "diia-parser/src/ast/NestedArithmeticNode.js";
import IfNode from "diia-parser/src/ast/IfNode.js";
import TestNode from "diia-parser/src/ast/TestNode.js";
import EachNode from "diia-parser/src/ast/EachNode.js";
import IdentifiersChainNode from "diia-parser/src/ast/IdentifiersChainNode.js";
import { makeDiia, makeLambda, NamedArguments } from "./diia.js";
import Context, { waitAll, WaitValue } from "./context.js";
import StructureNode from "diia-parser/src/ast/StructureNode.js";
import TakeNode from "diia-parser/src/ast/TakeNode.js";
import GiveNode from "diia-parser/src/ast/GiveNode.js";
import { loadModule } from "./module.js";
import ReturnNode from "diia-parser/src/ast/ReturnNode.js";
import LambdaNode from "diia-parser/src/ast/LambdaNode.js";
import { makeStructure } from "./structure.js";
import WaitChainNode from "diia-parser/src/ast/WaitChainNode.js";

/**
 * @param {Context} context
 * @param {ASTNode} node
 * @returns {*}
 */
export function runInstruction(context, node) {
    if (node instanceof NumberNode) {
        return node.value;
    }

    if (node instanceof StringNode) {
        return node.value;
    }

    if (node instanceof BooleanNode) {
        return node.value;
    }

    if (node instanceof IdentifierNode) {
        return runIdentifierInstruction(context, node);
    }

    if (node instanceof CallNode) {
        return runCallInstruction(context, node);
    }

    if (node instanceof AssignNode) {
        return runAssignInstruction(context, node);
    }

    if (node instanceof DiiaNode) {
        return runDiiaInstruction(context, node);
    }

    if (node instanceof ChainNode) {
        return runChainInstruction(context, node);
    }

    if (node instanceof ArithmeticNode) {
        return runArithmeticInstruction(context, node);
    }

    if (node instanceof NestedArithmeticNode) {
        return runInstruction(node.arithmetic);
    }

    if (node instanceof IfNode) {
        return runIfInstruction(context, node);
    }

    if (node instanceof TestNode) {
        return runTestInstruction(context, node);
    }

    if (node instanceof EachNode) {
        return runEachInstruction(context, node);
    }

    if (node instanceof StructureNode) {
        return runStructureInstruction(context, node);
    }

    if (node instanceof TakeNode) {
        return runTakeInstruction(context, node);
    }

    if (node instanceof GiveNode) {
        return runGiveInstruction(context, node);
    }

    if (node instanceof ReturnNode) {
        const value = runInstruction(context, node.value);

        context.set('__return__', value);

        return value;
    }

    if (node instanceof LambdaNode) {
        return runLambdaInstruction(context, node);
    }

    if (node instanceof WaitChainNode) {
        if (!context.get('__async__')) {
            throw new Error('"чекати" може використовуватись лише в тривалому контексті.')
        }

        return new WaitValue(runInstruction(context, node.chain));
    }

    throw new Error('Невідома інструкція: ' + node);
}

/**
 * @param {Context} context
 * @param {CallNode} callNode
 */
function runCallInstruction(context, callNode) {
    const name = callNode.name;
    let parameters = extractCallArguments(context, callNode.parameters);

    if (context.async) {
        const resolve = async () => {
            parameters = await waitAll(parameters);

            return context.call(name, parameters);
        }

        return new WaitValue(resolve());
    } else {
        return context.call(name, parameters);
    }
}

/**
 * @param context
 * @param {[]} callArguments
 */
function extractCallArguments(context, callArguments) {
    let args;

    if (Array.isArray(callArguments)) {
        args = callArguments
            .map((arg) => runInstruction(context, arg));
    } else {
        args = new NamedArguments();

        Object.entries(callArguments)
            .forEach(([k, v]) => {
                args[k] = runInstruction(context, v);
            });
    }

    return args;
}

/**
 *
 * @param object
 * @param context
 * @param {CallNode} callNode
 */
function runCallOnObjectInstruction(context, object, callNode) {
    const name = callNode.name;
    const parameters = extractCallArguments(context, callNode.parameters);

    return object[name](...Object.values(parameters));
}

/**
 * @param {Context} context
 * @param {AssignNode} assignNode
 */
function runAssignInstruction(context, assignNode) {
    const identifier = assignNode.identifier;
    let value = runInstruction(context, assignNode.value);

    let name;
    if (identifier instanceof IdentifierNode) {
        name = identifier.value;
    } else if (identifier instanceof IdentifiersChainNode) {
        // todo: handle it
    }

    if (context.get('__async__')) {
        if (value instanceof WaitValue) {
            const code = async () => {
                value = await value.value;

                context.set(name, value);

                return value;
            }

            return new WaitValue(code());
        } else {
            context.set(name, value);
        }
    } else {
        context.set(name, value);

        return value;
    }
}

/**
 *
 * @param context
 * @param {IdentifierNode} identifierNode
 */
function runIdentifierInstruction(context, identifierNode) {
    return context.get(identifierNode.value);
}

/**
 *
 * @param object
 * @param context
 * @param {IdentifierNode} identifierNode
 */
function runIdentifierOnObjectInstruction(context, object, identifierNode) {
    return object[identifierNode.value];
}

/**
 *
 * @param context
 * @param {DiiaNode} diiaNode
 */
function runDiiaInstruction(context, diiaNode) {
    const name = diiaNode.name;
    const parameters = diiaNode.parameters;
    const body = diiaNode.body;
    const async = diiaNode.async;

    context.set(name, makeDiia(context, name, parameters, body, async));
}

/**
 *
 * @param context
 * @param {LambdaNode} lambdaNode
 */
function runLambdaInstruction(context, lambdaNode) {
    const parameters = lambdaNode.parameters;
    const expression = lambdaNode.expression;

    return makeLambda(context, parameters, expression);
}

/**
 *
 * @param context
 * @param {ChainNode} chainNode
 */
function runChainInstruction(context, chainNode) {
    const chain = chainNode.chain;

    const initialContext = context;

    for (const node of chain) {
        if (context instanceof Context) {
            context = runInstruction(context, node);
        } else {
            if (node instanceof IdentifierNode) {
                return runIdentifierOnObjectInstruction(initialContext, context, node);
            }

            if (node instanceof CallNode) {
                return runCallOnObjectInstruction(initialContext, context, node);
            }
        }
    }

    return context;
}

/**
 *
 * @param context
 * @param {ArithmeticNode} arithmeticNode
 */
function runArithmeticInstruction(context, arithmeticNode) {
    const left = runInstruction(context, arithmeticNode.left);
    const right = runInstruction(context, arithmeticNode.right);

    switch (arithmeticNode.operation) {
        case '+':
            return left + right;
        case '-':
            return left - right;
        case '*':
            return left * right;
        case '/':
            return left / right;
        default:
            throw new Error('Недоступна операція: ' + arithmeticNode.operation);
    }
}

/**
 *
 * @param context
 * @param {IfNode} ifNode
 */
function runIfInstruction(context, ifNode) {
    const testResult = runInstruction(context, ifNode.expression);

    if (testResult) {
        const ifContext = new Context(context);

        return ifContext.run(ifNode.body);
    }
}

/**
 *
 * @param context
 * @param {TestNode} testNode
 */
function runTestInstruction(context, testNode) {
    const left = runInstruction(context, testNode.left);
    const right = runInstruction(context, testNode.right);

    switch (testNode.operation) {
        case '==':
            return left === right;
        case '!=':
            return left !== right;
        case '>=':
            return left >= right;
        case '<=':
            return left <= right;
        case 'є':
            return left instanceof right;
        default:
            throw new Error('Недоступна операція: ' + testNode.operation);
    }
}

/**
 *
 * @param context
 * @param {EachNode} eachNode
 */
function runEachInstruction(context, eachNode) {
    const name = eachNode.name;
    const iterator = runInstruction(context, eachNode.iterator);

    const eachContext = new Context(context);

    for (const v of iterator) {
        eachContext.properties[name] = v;
        eachContext.run(eachNode.body);

        const returnVal = eachContext.localGet('__return__');

        if (returnVal) {
            context.set('__return__', returnVal);
            return returnVal;
        }
    }
}

/**
 *
 * @param context
 * @param {StructureNode} structureNode
 */
function runStructureInstruction(context, structureNode) {
    const name = structureNode.name;
    const parameters = structureNode.parameters;
    const functions = structureNode.functions;

    context.set(name, makeStructure(context, name, parameters, functions));
}

/**
 *
 * @param context
 * @param {TakeNode} takeNode
 */
function runTakeInstruction(context, takeNode) {
    const rootPath = context.get('__кореневий_шлях_до_модуля');

    let moduleName = takeNode.name;

    let loadedContext;

    if (takeNode.pak) {
        loadedContext = loadModule(global.globalContext, `${rootPath}/.пакидії/${moduleName}/${moduleName}.дія`);
    } else {
        loadedContext = loadModule(global.globalContext, `${rootPath}/${moduleName}.дія`);
    }

    const moduleContext = loadedContext.get('__moduleContext');

    if (takeNode.chain) {
        const lastElementName = takeNode.chain.chain[takeNode.chain.chain.length - 1].value;

        context.set(
            takeNode.as || lastElementName,
            runChainInstruction(moduleContext, takeNode.chain)
        );
    } else {
        context.set(
            takeNode.as || moduleName,
            moduleContext
        );
    }

    return loadedContext;
}

/**
 *
 * @param context
 * @param {GiveNode} giveNode
 */
function runGiveInstruction(context, giveNode) {
    const moduleContext = context.get('__moduleContext');

    const name = giveNode.name;

    if (moduleContext) {
        moduleContext.set(giveNode.as || name, context.get(name));
    }

    return moduleContext;
}
