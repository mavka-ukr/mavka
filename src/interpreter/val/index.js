import { Context, ContextLess } from "../context/index.js";
import { ReturnValue, run, runNode } from "../run/index.js";

export function toVal(value) {
    if (typeof value === 'string') {
        return new StringVal(value);
    }

    if (typeof value === 'number') {
        return new NumberVal(value);
    }

    if (typeof value === 'boolean') {
        return new BooleanVal(value);
    }

    if (value == null) {
        return new UndefinedVal();
    }

    if (value instanceof Val) {
        return value;
    }

    return new UndefinedVal();
}

class Val {
    constructor() {
        this.properties = {};
    }

    get(name) {
        return this.properties[name];
    }

    set(name, value) {
        this.properties[name] = value;
    }

    call() {
        throw 'Not implemented.';
    }

    plus(value) {
        return new NumberVal(this.asNumber().asJsNumber() + value.asNumber().asJsNumber());
    }

    minus(value) {
        return new NumberVal(this.asNumber().asJsNumber() - value.asNumber().asJsNumber());
    }

    multiply(value) {
        return new NumberVal(this.asNumber().asJsNumber() * value.asNumber().asJsNumber());
    }

    divide(value) {
        return new NumberVal(this.asNumber().asJsNumber() / value.asNumber().asJsNumber());
    }

    equals(value) {
        return this._test(value, (a, b) => a === b);
    }

    notEquals(value) {
        return this._test(value, (a, b) => a !== b);
    }

    greaterThan(value) {
        return this._test(value, (a, b) => a > b);
    }

    lesserThan(value) {
        return this._test(value, (a, b) => a < b);
    }

    greaterThanOrEquals(value) {
        return this._test(value, (a, b) => a >= b);
    }

    lesserThanOrEquals(value) {
        return this._test(value, (a, b) => a <= b);
    }

    asNumber() {
        throw 'Not implemented.';
    }

    asString() {
        return new StringVal('значення');
    }

    asBoolean() {
        return true;
    }

    [Symbol.iterator]() {
        return {
            next() {
                return { done: true };
            },
        };
    }

    _test(value, fn) {
        if (this instanceof NumberVal && value instanceof NumberVal) {
            return new BooleanVal(fn(this.asNumber().asJsNumber(), value.asNumber().asJsNumber()));
        }

        if (this instanceof StringVal && value instanceof StringVal) {
            return new BooleanVal(fn(this.asNumber().asJsString(), value.asNumber().asJsString()));
        }

        return new BooleanVal(fn(this, value));
    }
}

export class AsyncVal extends Val {
    constructor(promise) {
        super();

        this.properties['__promise__'] = promise;
    }

    getPromise() {
        return this.properties['__promise__'];
    }

    asString() {
        return new StringVal('ТривалийРезультат');
    }
}

export class BooleanVal extends Val {
    constructor(value) {
        super();

        this.properties['__value__'] = value;
    }

    asBoolean() {
        return this;
    }

    asJsBoolean() {
        return this.properties['__value__'];
    }
}

export class DiiaVal extends Val {
    constructor(context, node) {
        super();

        this.context = context;
        this.node = node;
    }

    call(args) {
        const runContext = new Context(this.context);

        if (this.node.async) {
            runContext.set('__async__', true);
        }

        if (Array.isArray(args)) {
            for (const [k, parameter] of Object.entries(this.node.parameters)) {
                runContext.set(parameter.name, args[k] ?? runNode(parameter.defaultValue));
            }
        } else {
            for (const parameter of this.node.parameters) {
                runContext.set(parameter.name, args[parameter.name] ?? runNode(parameter.defaultValue));
            }
        }

        let result = run(runContext, this.node.body);

        if (result instanceof ReturnValue) {
            result = result.value;
        }

        if (this.node.async) {
            if (!(result instanceof AsyncVal)) {
                result = new AsyncVal(new Promise((resolve) => {
                    resolve(result);
                }));
            }
        }

        return result;
    }

    asString() {
        return new StringVal(`дія:${this.node.name}`);
    }
}

export class JsFunctionVal extends Val {
    constructor(fn) {
        super();

        this.fn = fn;
    }

    call(args) {
        return this.fn(...Object.values(args));
    }
}

export class LambdaVal extends Val {
    constructor(context, node) {
        super();

        this.context = context;
        this.node = node;
    }

    call(args) {
        const runContext = new ContextLess(this.context);

        if (Array.isArray(args)) {
            for (const [k, parameter] of Object.entries(this.node.parameters)) {
                runContext.vars[parameter.name] = args[k] ?? runNode(parameter.defaultValue);
            }
        } else {
            for (const parameter of this.node.parameters) {
                runContext.vars[parameter.name] = args[parameter.name] ?? runNode(parameter.defaultValue);
            }
        }

        return runNode(runContext, this.node.expression);
    }

    asString() {
        return new StringVal(`():`);
    }
}

export class NumberVal extends Val {
    constructor(value) {
        super();

        this.properties['__value__'] = value;
    }

    asNumber() {
        return this;
    }

    asJsNumber() {
        return this.properties['__value__'];
    }

    asString() {
        return new StringVal(String(this.asJsNumber()));
    }
}

export class RangeVal extends Val {
    constructor(from, to, step) {
        super();

        this.from = from.asJsNumber();
        this.to = to.asJsNumber();
        this.step = step ? step.asJsNumber() : null;
    }

    * [Symbol.iterator]() {
        let value = this.from;

        while (value <= this.to) {
            yield new NumberVal(value);

            value += this.step;
        }
    }
}

export class StringVal extends Val {
    constructor(value) {
        super();

        this.properties['__value__'] = value;
    }

    plus(value) {
        return new StringVal(this.asJsString() + value.asString().asJsString());
    }

    minus(value) {
        throw 'Not implemented.';
    }

    multiply(value) {
        throw 'Not implemented.';
    }

    divide(value) {
        throw 'Not implemented.';
    }

    asBoolean() {
        return new BooleanVal(!!this.asJsString());
    }

    asString() {
        return this;
    }

    asJsString() {
        return this.properties['__value__'];
    }

    asNumber() {
        return new NumberVal(Number(this.asJsString()));
    }
}

export class StructureVal extends Val {
    constructor(node) {
        super();

        this.node = node;
    }

    asString() {
        const properties = Object.entries(this.properties)
            .map(([k, v]) => `${k}=${toVal(v).asString().asJsString()}`)
            .join(', ');

        return new StringVal(`${this.node.name}(${properties})`);
    }
}

export class StructureConstructorVal extends DiiaVal {
    constructor(context, node) {
        super();

        this.context = context;
        this.node = node;
    }

    call(args) {
        const structure = new StructureVal(this.node);

        if (Array.isArray(args)) {
            for (const [k, parameter] of Object.entries(this.node.parameters)) {
                structure.set(parameter.name, args[k] ?? runNode(this.context, parameter.defaultValue));
            }
        } else {
            for (const parameter of this.node.parameters) {
                structure.set(parameter.name, args[parameter.name] ?? runNode(this.context, parameter.defaultValue));
            }
        }

        for (const method of this.node.methods) {
            const context = new Context(this.context);
            context.set('я', structure);
            structure.set(method.name, new DiiaVal(context, method));
        }

        return structure;
    }
}

export class UndefinedVal extends Val {
    asString() {
        return new StringVal('невизначено');
    }
}

export class WaitVal extends Val {
    constructor(value) {
        super();

        this.properties['__value__'] = value;
    }
}

export class ModuleVal extends Val {
    constructor(name, context) {
        super();

        this.properties['__name__'] = name;
        this.properties['__context__'] = context;
    }

    get(name) {
        return this.getContext().get(name);
    }

    set(name, value) {
        throw 'Cannot set on module.';
    }

    getContext() {
        return this.properties['__context__'];
    }

    getName() {
        return this.properties['__name__'];
    }

    asString() {
        return new StringVal(`модуль:${this.getName()}`);
    }
}
