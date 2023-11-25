import { processBody, varname } from "./utils.js";
import TypeValueSingleNode from "mavka-parser/src/ast/TypeValueSingleNode.js";

export async function buildParamsExtracting(mavka, scope, params) {
  if (params.length) {
    const paramsExtractionFromObject = await Promise.all(params.map(async (param) => {
      const name = param.name;
      const defaultValue = param.defaultValue && !Array.isArray(param.defaultValue) ? await mavka.compileNode(scope, param.defaultValue) : "undefined";
      if (param.type) {
        if (param.type instanceof TypeValueSingleNode) {
          const compiledTypeIdentifier = await mavka.compileNode(scope, param.type.value);
          return `var ${varname(name)} = mavka_mapParam(params.${name}, ${compiledTypeIdentifier}, ${defaultValue}, callDi);`;
        }
      }
      return `var ${varname(name)} = params.${name};`;
    }).join("\n"));
    const paramsExtractionFromArray = await Promise.all(params.map(async (param, i) => {
      const name = param.name;
      const defaultValue = param.defaultValue && !Array.isArray(param.defaultValue) ? await mavka.compileNode(scope, param.defaultValue) : "undefined";
      if (param.type) {
        if (param.type instanceof TypeValueSingleNode) {
          const compiledTypeIdentifier = await mavka.compileNode(scope, param.type.value);
          return `var ${varname(name)} = mavka_mapParam(params[${i}], ${compiledTypeIdentifier}, ${defaultValue}, callDi);`;
        }
      }
      return `var ${varname(name)} = params[${i}];`;
    }).join("\n"));

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

export async function buildDiia(mavka, name, scope, async, params, body) {
  params.forEach((param) => {
    scope.vars.set(param.name, true);
  });

  const paramsExtracting = await buildParamsExtracting(mavka, scope, params);
  const compiledBody = await mavka.compileDiiaBody(scope, processBody(mavka, scope, body));
  const vars = await buildVars(scope, params.map((p) => p.name));
  const bodyString = [vars, paramsExtracting, compiledBody].filter((v) => v).join("\n");

  return `
((function() {
  var ${name} = ${async ? "async " : ""}function(params, callDi) {
    ${bodyString}
  };
  ${name}.__m_name__ = "${name}";
  return ${name};
})())
`.trim();
}

export async function buildStructureMethod(mavka, name, scope, async, params, body) {
  params.forEach((param) => {
    scope.vars.set(param.name, true);
  });

  const paramsExtracting = await buildParamsExtracting(mavka, scope, params);
  const compiledBody = await mavka.compileDiiaBody(scope, processBody(mavka, scope, body));
  const vars = await buildVars(scope, params.map((p) => p.name));
  const bodyString = [vars, paramsExtracting, compiledBody].filter((v) => v).join("\n");

  return `
((function() {
  var ${name} = ${async ? "async " : ""}function($я, params, callDi) {
    ${bodyString}
  };
  ${name}.__m_name__ = "${name}";
  return ${name};
})())
`.trim();
}

export async function buildDictionary(mavka, scope, args) {
  const compiledArgs = await Promise.all(Object.entries(args).map(async ([name, value]) => {
    value = await mavka.compileNode(scope, value);
    return `dictionaryValue.__m_map__.set("${name}", ${value});`;
  }).join("\n"));

  return `
((function() {
  var dictionaryValue = Object.create(null);
  dictionaryValue.constructor = $словник;
  dictionaryValue.__m_type__ = "dictionary";
  dictionaryValue.__m_props__ = Object.create(null);
  dictionaryValue.__m_map__ = new Map();
  ${compiledArgs}
  return dictionaryValue;
})())
`.trim();
}
