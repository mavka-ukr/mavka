import NumberNode from "diia-parser/src/ast/NumberNode.js";
import StringNode from "diia-parser/src/ast/StringNode.js";
import IdentifierNode from "diia-parser/src/ast/IdentifierNode.js";
import ArithmeticNode from "diia-parser/src/ast/ArithmeticNode.js";
import NestedArithmeticNode from "diia-parser/src/ast/NestedArithmeticNode.js";
import AssignNode from "diia-parser/src/ast/AssignNode.js";
import CallNode from "diia-parser/src/ast/CallNode.js";
import DiiaNode from "diia-parser/src/ast/DiiaNode.js";
import ChainNode from "diia-parser/src/ast/ChainNode.js";
import WaitChainNode from "diia-parser/src/ast/WaitChainNode.js";

class Context {
    constructor(parent) {
        this.parent = parent;

        this.vars = {
            'global': global,
            'глобал': global,
        };
        this.functions = {
            //
        };
    }

    invoke(name, parameters) {
        let fn;

        if (this.functions.hasOwnProperty(name)) {
            fn = this.functions[name];
        } else {
            if (this.parent) {
                fn = this.parent.functions[name];
            }
        }

        if (!fn) {
            throw new Error('Cannot find function: ' + name);
        }

        return fn(...parameters);
    }

    var(name) {
        if (this.vars.hasOwnProperty(name)) {
            return this.vars[name];
        }

        if (this.parent) {
            return this.parent.var(name);
        }

        return undefined;
    }

    async evaluate(node) {
        if (node instanceof NumberNode) {
            return node.value;
        }

        if (node instanceof StringNode) {
            return node.value;
        }

        if (node instanceof IdentifierNode) {
            return await this.var(node.value);
        }

        if (node instanceof ArithmeticNode) {
            const left = await this.evaluate(node.left);
            const right = await this.evaluate(node.right);

            switch (node.operation) {
                case '+':
                    return left + right;
                case '-':
                    return left - right;
                case '*':
                    return left * right;
                case '/':
                    return left / right;
            }
        }

        if (node instanceof NestedArithmeticNode) {
            return await this.evaluate(node.arithmetic);
        }

        if (node instanceof AssignNode) {
            return this.vars[node.identifier.value] = await this.evaluate(node.value);
        }

        if (node instanceof CallNode) {
            const parameters = await Promise.all(node.parameters.map((p) => this.evaluate(p)));
            return await this.invoke(node.identifier.value, parameters);
        }

        if (node instanceof DiiaNode) {
            const context = new Context(this);

            this.functions[node.name] = (...parameters) => {
                node.parameters.forEach((p, i) => {
                    context.vars[p] = parameters[i];
                });

                return context.run(node.body);
            }

            return context;
        }

        if (node instanceof ChainNode) {
            let prevPart = await this.evaluate(node.parts[0]);

            for (let i = 1; i < node.parts.length; i++) {
                if (prevPart instanceof Context) {
                    prevPart = await prevPart.evaluate(node.parts[i]);
                } else if (typeof prevPart === "object") {
                    const part = node.parts[i];

                    if (part instanceof IdentifierNode) {
                        prevPart = prevPart[part.value];
                    } else if (part instanceof CallNode) {
                        const parameters = await Promise.all(part.parameters.map((p) => this.evaluate(p)));
                        prevPart = prevPart[part.identifier.value](...parameters);
                    } else {
                        throw new Error('Failed!');
                    }
                } else {
                    console.log(prevPart);
                    throw new Error('Failed!');
                }
            }

            return prevPart;
        }

        if (node instanceof WaitChainNode) {
            return await this.evaluate(node.chain);
        }
    }

    async run(ast) {
        let value = null;
        for (const node of ast) {
            value = await this.evaluate(node);
        }
        return value;
    }
}

export default Context;
