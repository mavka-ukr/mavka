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
      throw `Не вдалось завантажити модуль "${name}"`;
    }

    if (this.loadedModules[name]) {
      return { name, result: this.loadedModules[name] };
    }

    const moduleContext = new Context(this.mavka, this.mavka.context);
    moduleContext.setAsync(true);

    const moduleCode = this.files[name];
    const moduleProgram = parse(moduleCode);

    const giveContext = new Context(this.mavka);
    moduleContext.set("__give_context__", giveContext);

    this.loadedModules[name] = giveContext;

    await this.mavka.run(moduleContext, moduleProgram.body);

    let result = giveContext;

    if (newPath.length) {
      let first = newPath.shift();
      while (first) {
        name = first;
        result = result.get(first);
        first = newPath.shift();
      }
    } else {
      result = this.mavka.makeModule(name, giveContext);
    }

    return { name, result };
  }
}

export default MemoryLoader;
