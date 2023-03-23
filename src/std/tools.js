export function makeFn(mavka, fn, options = {}) {
  options.jsArgs = options.jsArgs ?? true;

  return new mavka.ProxyFunctionCell(mavka, (args, context, callOptions = {}) => {
    if (options.jsArgs) {
      args = Object.values(args)
        .map((arg) => mavka.toCell(arg).asJsValue(context));
    }

    const result = fn(args, context, callOptions);

    return mavka.toCell(result);
  });
}

export function makeAsyncFn(mavka, fn, options = {}) {
  options.jsArgs = options.jsArgs ?? true;

  return new mavka.ProxyFunctionCell(mavka, (args, context, callOptions = {}) => {
    if (options.jsArgs) {
      args = Object.values(args)
        .map((arg) => mavka.toCell(arg).asJsValue(context));
    }

    return new mavka.AsyncCell(mavka, async () => {
      const result = await fn(args, context, callOptions);

      return mavka.toCell(result);
    });
  });
}

/**
 * @param {Mavka} mavka
 * @param {Context} callContext
 * @param {Cell|Context} cellOrContext
 * @param {{ name: string, defaultValue: Cell|undefined }[]} parameters
 * @param {Record<string, Cell>|Cell[]} args
 */
export function fillParameters(mavka,
                               callContext,
                               cellOrContext,
                               parameters,
                               args) {
  const retrieveValue = (paramName, defaultValue) => {
    let value;

    if (Array.isArray(args)) {
      const paramIndex = parameters.map(({ name }) => name).indexOf(paramName);
      value = args[paramIndex];
    } else {
      value = args[paramName];
    }

    if (value == null) {
      if (defaultValue) {
        value = defaultValue;
      } else {
        value = mavka.emptyCellInstance;
      }
    }

    return value;
  };

  for (const { name, defaultValue } of parameters) {
    const value = retrieveValue(name, defaultValue);

    if (cellOrContext instanceof mavka.LightContext) {
      cellOrContext.setLocal(name, value);
    } else if (cellOrContext instanceof mavka.Context) {
      cellOrContext.set(name, value);
    } else {
      cellOrContext.set(callContext, name, value);
    }
  }
}
