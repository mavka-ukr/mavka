import { StructureContext } from "./context.js";
import { NamedArguments } from "./diia.js";

export function makeStructure(context, name, parameters, functions) {
    const structureFn = (args) => {
        const structureContext = new StructureContext(context);

        parameters.forEach((p) => {
            structureContext.set(p, null);
        });

        if (Array.isArray(args)) {
            parameters.forEach((p, i) => {
                structureContext.set(p, args[i]);
            });
        } else if (args instanceof NamedArguments) {
            parameters.forEach((p) => {
                structureContext.set(p, args[p]);
            });
        } else {
            structureContext.set(parameters[0], args);
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
