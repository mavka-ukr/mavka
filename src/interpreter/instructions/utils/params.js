/**
 * @param {Mavka} mavka
 * @param {Context} context
 * @param {ParamNode[]} paramNodes
 */
export function convertParamNodes(mavka, context, paramNodes) {
  const parameters = [];
  for (const nodeParam of paramNodes) {
    parameters.push({
      name: nodeParam.name.name,
      defaultValue: nodeParam.defaultValue ? mavka.runSync(context, nodeParam.defaultValue, { forceSync: true }) : undefined
    });
  }
  return parameters;
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
        value = mavka.empty;
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
