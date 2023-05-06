/**
 * @param {Mavka} mavka
 * @param {Context} context
 * @param {ParamNode[]} paramNodes
 */
export function convertParamNodes(mavka, context, paramNodes) {
  const parameters = [];
  for (const nodeParam of paramNodes) {
    if (nodeParam.spread && nodeParam.defaultValue) {
      mavka.fall(nodeParam, mavka.makeText("Параметр не може бути збірним і мати значення за замовчуванням."));
    }
    if (nodeParam.spread && paramNodes.indexOf(nodeParam) !== paramNodes.length - 1) {
      mavka.fall(nodeParam, mavka.makeText("Збірний параметр повинен бути останнім."));
    }
    parameters.push({
      name: nodeParam.name.name,
      defaultValue: nodeParam.defaultValue ? mavka.runSync(context, nodeParam.defaultValue, { forceSync: true }) : undefined,
      spread: nodeParam.spread
    });
  }
  return parameters;
}

/**
 * @param {Mavka} mavka
 * @param {Context} callContext
 * @param {Cell|Context} cellOrContext
 * @param {{ name: string, defaultValue: Cell|undefined, spread: boolean }[]} parameters
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
      const param = parameters[paramIndex];
      if (param.spread) {
        value = mavka.makeList(args.slice(paramIndex));
      } else {
        value = args[paramIndex];
      }
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
