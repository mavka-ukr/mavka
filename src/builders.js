import { processBody, varname } from "./utils.js";

export async function buildParamsExtracting(mavka, scope, params) {
  return (await Promise.all(params.map(async (param) => {
    const name = param.name;
    return `var ${varname(name)} = arg("${name}");`;
  }))).join("\n");
}

export async function buildParams(mavka, scope, params) {
  return "{" + (await Promise.all(params.map(async (p, i) => {
    const name = p.name;
    const compiledType = p.type && !["ніщо", "щось"].includes(p.type.value?.name) ? await mavka.compileNode(scope, p.type) : "undefined";
    const compiledDefaultValue = p.defaultValue ? await mavka.compileNode(scope, p.defaultValue) : "undefined";
    return `"${name}":mavka_param(${i},${compiledType},${compiledDefaultValue})`;
  }))).join(",") + "}";
}

export async function buildVars(scope, ignore = []) {
  const ignoredVars = ["я", ...ignore];
  let vars = [...scope.vars.entries()]
    .filter(([, value]) => value !== false)
    .map(([name]) => name)
    .filter((v) => !ignoredVars.includes(v))
    .map((v) => `var ${varname(v)};`)
    .join("\n");
  if (vars) {
    vars += "\n";
  }
  return vars;
}

export async function buildSetters(scope, ignore = []) {
  let setters = [...scope.setters]
    .map((v) => `var set${varname(v)} = (v) => { ${varname(v)} = v; };`)
    .join("\n");
  if (setters) {
    setters += "\n";
  }
  return setters;
}

export async function buildDiia(mavka, name, scope, async, params, body) {
  params.forEach((param) => {
    scope.vars.set(param.name, true);
  });

  const compiledName = name == null ? "null" : `"${name}"`;
  const compiledParams = await buildParams(mavka, scope, params);
  const paramsExtracting = await buildParamsExtracting(mavka, scope, params);
  const compiledBody = await mavka.compileDiiaBody(scope, await processBody(mavka, scope, body));
  const vars = await buildVars(scope, params.map((p) => p.name));
  const setters = await buildSetters(scope);
  const bodyString = [vars, setters, paramsExtracting, compiledBody].filter((v) => v).join("\n");

  return `
mavka_diia(${compiledName},${compiledParams},${async ? "async " : ""}function(params, callDi, { arg }) {
  ${bodyString}
})
`.trim();
}

export async function buildStructureMethod(mavka, structureName, name, scope, async, params, body) {
  params.forEach((param) => {
    scope.vars.set(param.name, true);
  });

  const compiledParams = await buildParams(mavka, scope, params);
  const paramsExtracting = await buildParamsExtracting(mavka, scope, params);
  const compiledBody = await mavka.compileDiiaBody(scope, await processBody(mavka, scope, body));
  const vars = await buildVars(scope, params.map((p) => p.name));
  const setters = await buildSetters(scope);
  const bodyString = [vars, setters, paramsExtracting, compiledBody].filter((v) => v).join("\n");

  return `
mavka_method(${compiledParams},${async ? "async " : ""}function(м_я, params, callDi, { arg }) {
  ${bodyString}
})
`.trim();
}

export async function buildDictionary(mavka, scope, args) {
  const compiledArgs = (await Promise.all(Object.entries(args).map(async ([name, value]) => {
    value = await mavka.compileNode(scope, value);
    return `d.set("${name}", ${value});`;
  }))).join("\n");

  return `
((function() {
  var d = new Map();
  ${compiledArgs}
  return d;
})())
`.trim();
}
