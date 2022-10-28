import { StructureContext } from "./context.js";

export function makeStructure(context, name, parameters, functions) {
    const structureFn = (args) => {
        const structureContext = new StructureContext(context);

        if (Array.isArray(args)) {
            parameters.forEach((p, i) => {
                structureContext.set(p, args[i]);
            });
        } else if (typeof args === "object") {
            parameters.forEach((p) => {
                structureContext.set(p, args[p]);
            });
        }

        structureContext.run(functions);

        const createDiia = structureContext.localGet('створити');
        if (createDiia) {
            createDiia();
            delete structureContext.properties['створити'];
        }

        return structureContext;
    }

    structureFn.__diia_structure__ = true;

    return structureFn;
}
