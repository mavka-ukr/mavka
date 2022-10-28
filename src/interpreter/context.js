import { runInstruction } from "./instructions.js";
import { parse } from "diia-parser";
import { NamedArguments } from "./diia.js";

export class WaitValue {
    constructor(value) {
        this.value = value;
    }
}

export async function waitRecursively(value) {
    value = await value;

    if (value instanceof WaitValue) {
        return waitRecursively(value.value);
    }

    return value;
}

export async function waitAll(waits) {
    if (Array.isArray(waits)) {
        waits = Promise.all(waits.map((wait) => {
            if (wait instanceof WaitValue) {
                return waitRecursively(wait.value);
            }

            return wait;
        }));
    } else if (waits instanceof NamedArguments) {
        for (const [k, v] of Object.entries(waits)) {
            waits[k] = await waitRecursively(v);
        }
    }

    return waits;
}

class Context {
    constructor(parent = null) {
        this.parent = parent;
        this.properties = {
            'виконати': (code) => {
                const context = new Context(this);
                return context.run(parse(code));
            },
            '__async__': false,
        };
    }

    get async() {
        return !!this.get('__async__');
    }

    get(name) {
        if (name in this.properties) {
            return this.properties[name];
        }

        if (this.parent) {
            return this.parent.get(name);
        }

        throw new Error(`Невідома змінна: ${name}`);
    }

    localGet(name) {
        return this.properties[name];
    }

    set(name, value) {
        this.properties[name] = value;
    }

    call(name, args) {
        const diia = this.get(name);

        if (!diia) {
            throw new Error(`Невідома дія: ${name}`);
        }

        if (diia.__diia_fn__ || diia.__lambda_fn__) {
            return diia(args);
        }

        return diia(...Object.values(args || []));
    }

    run(ast) {
        if (this.get('__async__')) {
            const resolve = async () => {
                let value;

                for (const node of ast) {
                    value = runInstruction(this, node);

                    if (value instanceof WaitValue) {
                        value = await waitRecursively(value.value);
                    }

                    if (this.localGet('__return__')) {
                        if (this.parent && !(this instanceof DiiaContext)) {
                            this.parent.set('__return__', this.localGet('__return__'));
                        }

                        return value;
                    }
                }

                return value;
            }

            return resolve();
        } else {
            let value;

            for (const node of ast) {
                value = runInstruction(this, node);

                if (this.localGet('__return__')) {
                    if (this.parent && !(this instanceof DiiaContext)) {
                        this.parent.set('__return__', this.localGet('__return__'));
                    }

                    return value;
                }
            }

            return value;
        }
    }
}

export class StructureContext extends Context {
    constructor(parent) {
        super(parent);

        this.set('я', this);
    }
}

export class DiiaContext extends Context {
}

export class ModuleContext extends Context {
}

export class LambdaContext extends Context {
    // set(name, value) {
    //     this.parent.set(name, value);
    // }
}

export default Context;
