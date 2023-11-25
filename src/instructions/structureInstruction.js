import Instruction from "./instruction.js";
import { varname } from "../utils.js";
import { buildParamsExtracting } from "../builders.js";

class StructureInstruction extends Instruction {
  /**
   * @param {Scope} scope
   * @param {StructureNode} node
   * @returns {*}
   */
  async compile(scope, node) {
    const name = node.name;

    const paramsExtracting = await buildParamsExtracting(this.mavka, scope, node.params);

    const paramsAssignments = (thisName = "this", nullValue = false) => node.params.map((param) => {
      const name = param.name;
      return `${thisName}.__m_props__.${name} = ${nullValue ? "null" : varname(name)};`;
    }).join("\n");

    const paramDefinitionsAssignments = (thisName = "this") => node.params.map((param) => {
      const name = param.name;
      return `${thisName}.${name} = null;`;
    }).join("\n");

    let parentString = "";
    if (node.parent) {
      const parent = await this.mavka.compileNode(scope, node.parent);
      parentString = `static __m_parent__ = ${parent};`;
    }

    return `
${varname(name)} = class {
  static __m_name__ = "${name}";
  static __m_type__ = "structure";
  static __m_prop_definitions__ = ((function () {
     const props = Object.create(null);
     ${paramDefinitionsAssignments("props")}
     return props;
  })());
  static __m_props__ = ((function () {
     const props = Object.create(null);
     props["чародія_викликати"] = function(params, callDi) {
       var value = new ${varname(name)}();
       if (value.__m_props__["чародія_створити"]) {
         value.__m_props__["чародія_створити"](params, callDi);
       } else {
         (function() {
           ${paramsExtracting}
           ${paramsAssignments("value")}
         })();
       }
       if (value.__m_props__["чародія_після_створення"]) {
         value.__m_props__["чародія_після_створення"](params, callDi);
       }
       return value;
     }
     return props;
  })());
  static __m_methods__ = Object.create(null);
  ${parentString}
  constructor() {
    this.__m_type__ = "object";
    this.__m_props__ = Object.create(null);
    ${paramsAssignments("this", true)}
    this.__m_props__["чародія_перетворення_на_текст"] = (params, di) => {
      let value = "${name}(";
      let entries = [];
      Object.entries(${varname(name)}.__m_prop_definitions__).forEach(([k]) => {
        entries.push(k + "=" + mavka_to_pretty_string(this.__m_props__[k], di));
      });
      value += entries.join(", ") + ")";
      return value;
    }
    var structure = ${varname(name)};
    while (structure) {
      for (const [k, v] of Object.entries(structure.__m_methods__)) {
        if (this.__m_props__[k]) {
          continue;
        }
        this.__m_props__[k] = (params, di) => {
          return v(this, params, di);
        }
      }
      
      structure = structure.__m_parent__;
    }
  }
}
`.trim();
  }
}

export default StructureInstruction;
