import { runInstruction } from "./instructions.js";
import { parse } from "diia-parser";
import Diia from "./diia.js";

class Context {
    constructor(parent = null) {
        this.parent = parent;
        this.properties = {
            'виконати': (code) => {
                const context = new Context(this);
                return context.run(parse(code));
            },
        };
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

    set(name, value) {
        this.properties[name] = value;
    }

    call(name, parameters) {
        const diia = this.get(name);

        if (!diia) {
            throw new Error(`Невідома дія: ${name}`);
        }

        if (diia instanceof Diia) {
            return diia.call(parameters);
        }

        return diia(...Object.values(parameters || []));
    }

    run(ast) {
        let value;

        for (const node of ast) {
            value = runInstruction(this, node);
        }

        return value;
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

export default Context;
