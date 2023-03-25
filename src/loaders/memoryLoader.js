import Loader from "./loader.js";
import Context from "../interpreter/contexts/context.js";
import { parse } from "mavka-parser";

class MemoryLoader extends Loader {
  constructor(mavka, files = {}) {
    super(mavka);

    this.files = files;
    this.loadedModules = {};
  }

  async load(context, path, pak = false, relative = false) {
    let name = path[0];
    const newPath = path.slice(1);

    if (!(name in this.files)) {
      throw `Не вдалось завантажити модуль "${name}."`;
    }

    let module;

    if (this.loadedModules[name]) {
      module = this.loadedModules[name];
    } else {
      const moduleContext = new Context(this.mavka, this.mavka.context);
      moduleContext.setAsync(true);

      const moduleCode = this.files[name];
      const moduleProgram = parse(moduleCode);

      module = this.mavka.makeModule(name);
      moduleContext.setModule(module);

      this.loadedModules[name] = module;

      await this.mavka.run(moduleContext, moduleProgram.body);
    }

    let result = module;

    if (newPath.length) {
      let first = newPath.shift();
      while (first) {
        name = first;
        if (result instanceof this.mavka.Context) {
          result = result.get(first);
        } else {
          result = result.get(context, first);
        }
        first = newPath.shift();
      }
    }

    return { name, result };
  }
}

export default MemoryLoader;
