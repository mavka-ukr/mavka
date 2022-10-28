import { DiiaContext } from "./context.js";

class Diia {
    constructor(context, name, parameters, body) {
        this.context = context;
        this.name = name;
        this.parameters = parameters;
        this.body = body;
    }

    call(args) {
        const diiaContext = new DiiaContext(this.context);

        diiaContext.set('аргументи', args);

        if (Array.isArray(args)) {
            this.parameters.forEach((p, i) => {
                diiaContext.set(p, args[i]);
            });
        } else if (typeof args === "object") {
            this.parameters.forEach((p) => {
                diiaContext.set(p, args[p]);
            });
        }

        return diiaContext.run(this.body);
    }
}

export default Diia;
