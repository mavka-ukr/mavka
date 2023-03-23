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
