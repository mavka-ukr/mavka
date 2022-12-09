export class Context {
    constructor(parent) {
        this.parent = parent;
        this.vars = {};
    }

    get(name) {
        if (name in this.vars) {
            return this.vars[name];
        }

        if (this.parent) {
            return this.parent.get(name);
        }

        throw `Невідома змінна: ${name}`;
    }

    set(name, value) {
        this.vars[name] = value;
    }

    call(name, args) {
        const diia = this.get(name);

        if (!diia) {
            throw `Невідома дія: ${name}`;
        }

        return diia.call(args);
    }
}

export class ContextLess extends Context {
    set(name, value) {
        this.parent.vars[name] = value;
    }
}
