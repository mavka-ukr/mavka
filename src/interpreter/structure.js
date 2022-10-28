import { StructureContext } from "./context.js";

export class StructureConstructor {
    constructor(context, name, parameters, functions) {
        this.context = context;
        this.name = name;
        this.parameters = parameters;
        this.functions = functions;
    }

    call(args) {
        const structureContext = new StructureContext(this.context);

        if (Array.isArray(args)) {
            this.parameters.forEach((p, i) => {
                structureContext.set(p, args[i]);
            });
        } else if (typeof args === "object") {
            this.parameters.forEach((p) => {
                structureContext.set(p, args[p]);
            });
        }

        structureContext.run(this.functions);

        return structureContext;
    }
}
