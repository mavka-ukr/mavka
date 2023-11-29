import { processBody, varname } from "./utils.js";
import TypeValueSingleNode from "mavka-parser/src/ast/TypeValueSingleNode.js";
import IdentifierNode from "mavka-parser/src/ast/IdentifierNode.js";

export async function buildParamsExtracting(mavka, scope, params) {
  if (params.length) {
    const paramsExtractionFromObject = (await Promise.all(params.map(async (param) => {
      const name = param.name;
      const defaultValue = param.defaultValue && !Array.isArray(param.defaultValue) ? await mavka.compileNode(scope, param.defaultValue) : undefined;
      if (param.type) {
        if (param.type instanceof TypeValueSingleNode) {
          if (param.type.value instanceof IdentifierNode) {
            if (!["щось", "ніщо"].includes(param.type.value.name)) {
              const compiledTypeIdentifier = await mavka.compileNode(scope, param.type.value);
              return `var ${varname(name)} = mavka_mapArg(params.${name}, ${compiledTypeIdentifier}, ${defaultValue}, callDi);`;
            }
          }
        }
      }
      if (defaultValue) {
        return `var ${varname(name)} = params.${name} === undefined ? ${defaultValue} : params.${name};`;
      }
      return `var ${varname(name)} = params.${name};`;
    }))).join("\n");
    const paramsExtractionFromArray = (await Promise.all(params.map(async (param, i) => {
      const name = param.name;
      const defaultValue = param.defaultValue && !Array.isArray(param.defaultValue) ? await mavka.compileNode(scope, param.defaultValue) : undefined;
      if (param.type) {
        if (param.type instanceof TypeValueSingleNode) {
          if (param.type.value instanceof IdentifierNode) {
            if (!["щось", "ніщо"].includes(param.type.value.name)) {
              const compiledTypeIdentifier = await mavka.compileNode(scope, param.type.value);
              return `var ${varname(name)} = mavka_mapArg(params[${i}], ${compiledTypeIdentifier}, ${defaultValue}, callDi);`;
            }
          }
        }
      }
      if (defaultValue) {
        return `var ${varname(name)} = params[${i}] === undefined ? ${defaultValue} : params[${i}];`;
      }
      return `var ${varname(name)} = params[${i}];`;
    }))).join("\n");

    return `
if (Array.isArray(params)) {
  ${paramsExtractionFromArray}
} else {
  ${paramsExtractionFromObject}
}
    `.trim();
  }
  return "";
}

export async function buildParams(mavka, scope, params) {
  return "{" + (await Promise.all(params.map(async (p, i) => {
    const name = p.name;
    const compiledType = p.type ? await mavka.compileNode(scope, p.type) : "undefined";
    const compiledDefaultValue = p.defaultValue ? await mavka.compileNode(scope, p.defaultValue) : "undefined";
    return `"${name}":mavka_param(${i},"${name}",${compiledType},${compiledDefaultValue})`;
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
  const compiledBody = await mavka.compileDiiaBody(scope, processBody(mavka, scope, body));
  const vars = await buildVars(scope, params.map((p) => p.name));
  const setters = await buildSetters(scope);
  const bodyString = [vars, setters, paramsExtracting, compiledBody].filter((v) => v).join("\n");

  return `
mavka_diia(${compiledName},${compiledParams},${async ? "async " : ""}function(params, callDi) {
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
  const compiledBody = await mavka.compileDiiaBody(scope, processBody(mavka, scope, body));
  const vars = await buildVars(scope, params.map((p) => p.name));
  const setters = await buildSetters(scope);
  const bodyString = [vars, setters, paramsExtracting, compiledBody].filter((v) => v).join("\n");

  return `
mavka_method(${varname(structureName)},"${name}",${compiledParams},${async ? "async " : ""}function($я, params, callDi) {
  ${bodyString}
})
`.trim();
}

export async function buildDictionary(mavka, scope, args) {
  const compiledArgs = (await Promise.all(Object.entries(args).map(async ([name, value]) => {
    value = await mavka.compileNode(scope, value);
    return `dictionaryValue.set("${name}", ${value});`;
  }))).join("\n");

  return `
((function() {
  var dictionaryValue = new Map();
  ${compiledArgs}
  return dictionaryValue;
})())
`.trim();
}
