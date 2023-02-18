import Loader from "./loader.js";
import Context from "../interpreter/contexts/context.js";
import { parse } from "mavka-parser";

class FileLoader extends Loader {
  constructor(mavka) {
    super(mavka);

    this.loadedModules = {};
  }

  async load(context, name, pak = false) {
    const currentModuleDirname = context.get("__module_dirname__");

    const newModulePath = pak
      ? `${currentModuleDirname}/.паки/${name}/${name}.дія`
      : `${currentModuleDirname}/${name}.дія`;

    if (this.loadedModules[newModulePath]) {
      return this.loadedModules[newModulePath];
    }

    const moduleContext = new Context(this.mavka, this.mavka.context);
    moduleContext.set("__module_dirname__", currentModuleDirname);
    moduleContext.set("__module_path__", newModulePath);
    moduleContext.setAsync(true);

    const fs = (await import("fs")).default;

    const moduleCode = fs.readFileSync(newModulePath).toString();
    const moduleProgram = parse(moduleCode);

    const giveContext = new Context(this.mavka);
    moduleContext.set("__give_context__", giveContext);

    this.loadedModules[newModulePath] = moduleContext;

    await this.mavka.run(moduleContext, moduleProgram.body);

    return moduleContext;
  }
}

export default FileLoader;
