import AssignSimpleNode from "mavka-parser/src/ast/AssignSimpleNode.js";
import StructureNode from "mavka-parser/src/ast/StructureNode.js";
import DiiaNode from "mavka-parser/src/ast/DiiaNode.js";
import ModuleNode from "mavka-parser/src/ast/ModuleNode.js";
import TryNode from "mavka-parser/src/ast/TryNode.js";
import EachNode from "mavka-parser/src/ast/EachNode.js";
import MockupModuleNode from "mavka-parser/src/ast/MockupModuleNode.js";
import MockupDiiaNode from "mavka-parser/src/ast/MockupDiiaNode.js";
import MockupObjectNode from "mavka-parser/src/ast/MockupObjectNode.js";
import EvalNode from "mavka-parser/src/ast/EvalNode.js";
import TakeModuleNode from "mavka-parser/src/ast/TakeModuleNode.js";
import TakeRemoteNode from "mavka-parser/src/ast/TakeRemoteNode.js";
import TakePakNode from "mavka-parser/src/ast/TakePakNode.js";
import TakeFileNode from "mavka-parser/src/ast/TakeFileNode.js";
import IdentifiersChainNode from "mavka-parser/src/ast/IdentifiersChainNode.js";
import { MavkaCompilationError } from "./error.js";
import semver from "semver";
import IdentifierNode from "mavka-parser/src/ast/IdentifierNode.js";

/**
 * @param {string} name
 * @returns {string}
 */
export const varname = (name) => `$${name}`;

/**
 * @param {string} pak
 * @returns {{name: string, version: string, url: string}|{name: string, local: boolean}}
 */
export function unpackPackName(pak) {
  if (pak.startsWith("https://")) {
    pak = pak.substring(8);
    const parts = pak.split("/");
    const domain = parts[0] === "пак.укр" ? "хмарний.пак.укр" : parts[0];
    const path = parts.slice(1).filter((p) => p);
    let moduleName;
    let versionName;
    let pakName;
    if (!path.length) {
      throw new MavkaCompilationError("Неправильний URL паку.");
    } else if (path.length === 1) {
      throw new MavkaCompilationError("Неправильний URL паку.");
    } else if (path.length === 2) {
      moduleName = path[0] + ".м";
      versionName = path[1];
      pakName = path[0];
    } else { // pak/version/module.m
      if (path[path.length - 1].endsWith(".м")) {
        moduleName = path[path.length - 1];
        versionName = path[path.length - 2];
        pakName = path[path.length - 3];
      } else {
        moduleName = path[path.length - 2] + ".м";
        versionName = path[path.length - 1];
        pakName = path[path.length - 2];
      }
    }
    if (semver.valid(versionName) === null) {
      throw new MavkaCompilationError("Неправильна версія паку.");
    }
    const newPath = path.slice(0, path.length - 3).concat([pakName, versionName, moduleName]).join("/");
    const newPathWithoutName = path.slice(0, path.length - 3).concat([pakName, versionName]).join("/");

    return {
      url: `https://${domain}/${newPath}`,
      dirUrl: `https://${domain}/${newPathWithoutName}`,
      name: pakName,
      version: versionName
    };
  } else {
    const parts = pak.split("/");
    if (parts.length === 1) {
      return {
        name: parts[0],
        local: true
      };
    } else if (parts.length === 2 && semver.valid(parts[1]) !== null) {
      return {
        url: `https://хмарний.пак.укр/${parts[0]}/${parts[1]}/${parts[0]}.м`,
        dirUrl: `https://хмарний.пак.укр/${parts[0]}/${parts[1]}`,
        name: parts[0],
        version: parts[1]
      };
    }
    const domain = parts[0] === "пак.укр" ? "хмарний.пак.укр" : parts[0];
    const path = parts.slice(1).filter((p) => p);
    let moduleName;
    let versionName;
    let pakName;
    if (!path.length) {
      throw new MavkaCompilationError("Неправильний URL паку.");
    } else if (path.length === 1) {
      throw new MavkaCompilationError("Неправильний URL паку.");
    } else if (path.length === 2) {
      moduleName = path[0] + ".м";
      versionName = path[1];
      pakName = path[0];
    } else { // пак.укр/pak/version
      if (path[path.length - 1].endsWith(".м")) {
        moduleName = path[path.length - 1];
        versionName = path[path.length - 2];
        pakName = path[path.length - 3];
      } else {
        moduleName = path[path.length - 2] + ".м";
        versionName = path[path.length - 1];
        pakName = path[path.length - 2];
      }
    }
    if (semver.valid(versionName) === null) {
      throw new MavkaCompilationError("Неправильна версія паку.");
    }
    const newPath = path.slice(0, path.length - (path[path.length - 1].endsWith(".м") ? 3 : 2)).concat([pakName, versionName, moduleName]).join("/");
    const newPathWithoutName = path.slice(0, path.length - (path[path.length - 1].endsWith(".м") ? 3 : 2)).concat([pakName, versionName]).join("/");

    return {
      url: `https://${domain}/${newPath}`,
      dirUrl: `https://${domain}/${newPathWithoutName}`,
      name: pakName,
      version: versionName
    };
  }
}

/**
 * @param {Scope} scope
 * @param {ASTNode[]} body
 */
export function processBody(mavka, scope, body) {
  const head = [];
  const result = [];

  for (const node of body) {
    if (node instanceof AssignSimpleNode) {
      if (node.symbol === "=") {
        scope.vars.set(node.name, true);
      }
    }

    if (node instanceof DiiaNode) {
      if (!node.structure) {
        scope.vars.set(node.name, true);
      }
      head.push(node);
    } else if (node instanceof StructureNode) {
      scope.vars.set(node.name, true);
      head.push(node);
    } else if (node instanceof ModuleNode) {
      if (node.name) {
        scope.vars.set(node.name, true);
        head.push(node);
      } else {
        result.push(node);
      }
    } else if (node instanceof TryNode) {
      if (node.catchName) {
        scope.vars.set(node.catchName, true);
      }
      result.push(node);
    } else if (node instanceof EachNode) {
      if (node.keyName) {
        scope.vars.set(node.keyName, true);
      }
      if (node.name) {
        scope.vars.set(node.name, true);
      }
      result.push(node);
    } else if (node instanceof TakeModuleNode) {
      if (node.id instanceof IdentifierNode) {
        scope.vars.set(node.as || node.id.name, true);
      } else if (node.id instanceof IdentifiersChainNode) {
        const chain = node.id.toFlatArray();
        const name = chain[chain.length - 1];
        scope.vars.set(node.as || name, true);
      }
      result.push(node);
    } else if (node instanceof TakeRemoteNode) {
      const { name } = unpackPackName(node.url);
      scope.vars.set(node.as || name, true);
      result.push(node);
    } else if (node instanceof TakePakNode) {
      // deprecated
    } else if (node instanceof TakeFileNode) {
      const debugInfoVarName = mavka.putDebugInfoVarName(node);
      const debugInfoVar = mavka.debugInfoVarNames.get(debugInfoVarName);
      throw new MavkaCompilationError(`"взяти файл" тимчасово недоступно.`, debugInfoVar);
    } else if (node instanceof EvalNode) {
      result.push(node);
    } else if (node instanceof MockupModuleNode) {
      scope.vars.set(node.name, false);
    } else if (node instanceof MockupDiiaNode) {
      scope.vars.set(node.name, false);
    } else if (node instanceof MockupObjectNode) {
      scope.vars.set(node.name, false);
    } else {
      result.push(node);
    }
  }

  return [...head, ...result];
}
