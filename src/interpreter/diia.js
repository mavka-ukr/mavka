import { DiiaContext, LambdaContext } from "./context.js";

export class NamedArguments {
    constructor(args = {}) {
        Object.assign(args);
    }
}

export function makeDiia(context, name, parameters, body, async) {
    const diiaFn = function (args) {
        const diiaContext = new DiiaContext(context);
        diiaContext.set('__diia__', diiaContext);
        diiaContext.set('__async__', async);

        diiaContext.set('аргументи', args);

        if (Array.isArray(args)) {
            parameters.forEach((p, i) => {
                diiaContext.set(p, args[i]);
            });
        } else if (args instanceof NamedArguments) {
            parameters.forEach((p) => {
                diiaContext.set(p, args[p]);
            });
        } else {
            diiaContext.set(parameters[0], args);
        }

        return diiaContext.run(body);
    }

    diiaFn.__diia_fn__ = true;

    return diiaFn;
}


export function makeLambda(context, parameters, expression) {
    const lambdaFn = function (args) {
        const lambdaContext = new LambdaContext(context);

        if (Array.isArray(args)) {
            parameters.forEach((p, i) => {
                lambdaContext.set(p, args[i]);
            });
        } else if (args instanceof NamedArguments) {
            parameters.forEach((p) => {
                lambdaContext.set(p, args[p]);
            });
        } else {
            lambdaContext.set(parameters[0], args);
        }

        return lambdaContext.run([expression]);
    }

    lambdaFn.__lambda_fn__ = true;

    return lambdaFn;
}
