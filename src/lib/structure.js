function mavka_structure(name, parent = null, params = {}, di = null) {
  var mergedParams = params;
  var mergedMethods = Object.create(null);
  if (parent && parent.__m_type__ !== "structure") {
    throw new MavkaError("Неможливо створити структуру.", di);
  }
  // todo: check for circular inheritance
  // todo: check for duplicate params and methods
  var currStructure = parent;
  while (currStructure != null && currStructure.__m_type__ === "structure") {
    for (const [k, v] of Object.entries(currStructure.__m_params__)) {
      if (mergedParams[k]) {
        continue;
      }
      mergedParams[k] = v;
    }
    for (const [k, v] of Object.entries(currStructure.__m_methods__)) {
      if (mergedMethods[k]) {
        continue;
      }
      mergedMethods[k] = v;
    }
    currStructure = currStructure.__m_parent__;
  }
  var structure = class {
    static __m_type__ = "structure";
    static __m_props__ = Object.create(null);
    static __m_name__ = name;
    // structure specific
    static __m_params__ = mergedParams;
    static __m_methods__ = mergedMethods;
    static __m_parent__ = parent;

    constructor() {
      this.__m_structure__ = structure;
      this.__m_type__ = "object";
      this.__m_props__ = Object.create(null);
      // fill props and attach methods
      for (const [k, v] of Object.entries(structure.__m_params__)) {
        if (this.__m_props__[k]) {
          continue;
        }
        this.__m_props__[k] = v.defaultValue ?? null;
      }
      for (const [k, v] of Object.entries(structure.__m_methods__)) {
        if (this.__m_props__[k]) {
          continue;
        }
        this.__m_props__[k] = mavka_diia(k, v.__m_params__, (args, callDi) => {
          return v(this, args, callDi);
        }, undefined, di);
      }
    }

    toJSON() {
      const result = Object.create(null);
      for (const [k, v] of Object.entries(structure.__m_params__)) {
        result[k] = this.__m_props__[k];
      }
      return result;
    }
  };
  structure.__m_props__["чародія_викликати"] = mavka_diia("чародія_викликати", {}, (args, callDi) => {
    var value = new structure();
    if (value.__m_props__["чародія_створити"]) {
      value.__m_props__["чародія_створити"](args, callDi);
    } else {
      for (const [k, v] of Object.entries(structure.__m_params__)) {
        value.__m_props__[k] = mavka_arg(
          args,
          v.get("позиція"),
          k,
          v.get("тип"),
          v.get("значення"),
          callDi
        );
      }
    }
    if (value.__m_props__["чародія_після_створення"]) {
      value.__m_props__["чародія_після_створення"](args, callDi);
    }
    return value;
  }, undefined, di);
  return structure;
}