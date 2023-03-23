export function makeFn(mavka, fn, options = {}) {
  options.jsArgs = options.jsArgs ?? true;

  return new mavka.PortalFunctionCell(mavka, (args, context, callOptions = {}) => {
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

  return new mavka.PortalFunctionCell(mavka, (args, context, callOptions = {}) => {
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

export function makePureFn(mavka, fn, options = {}) {
  options.jsArgs = options.jsArgs ?? true;

  return new mavka.PortalFunctionCell(mavka, (args, context) => {
    if (options.jsArgs) {
      args = Object.values(args)
        .map((arg) => mavka.toCell(arg).asJsValue(context));
    }

    let result;

    if (options.thisArg) {
      result = fn.call(options.thisArg, args);
    } else {
      result = fn(...args);
    }

    return mavka.toCell(result);
  });
}

export function runParams(mavka, context, cellOrContext, params, args, defaultValues = {}) {
  const retrieveValue = (paramName, defaultValueNode) => {
    let value;

    if (Array.isArray(args)) {
      const paramIndex = params.map((param) => param.name.name).indexOf(paramName);
      value = args[paramIndex];
    } else {
      value = args[paramName];
    }

    if (value == null) {
      if (defaultValueNode) {
        if (paramName in defaultValues) {
          value = defaultValues[paramName];
        } else {
          value = defaultValues[paramName] = mavka.runSync(context, defaultValueNode, { forceSync: true });
        }
      } else {
        value = mavka.emptyCellInstance;
      }
    }

    return value;
  };

  for (const param of params) {
    const name = param.name.name;
    const value = retrieveValue(name, param.defaultValue, true);
    if (cellOrContext instanceof mavka.LightContext) {
      cellOrContext.setLocal(name, value);
    } else {
      cellOrContext.set(name, value);
    }
  }
}
