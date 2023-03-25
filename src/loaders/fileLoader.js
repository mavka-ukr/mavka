import Loader from "./loader.js";
import Context from "../interpreter/contexts/context.js";
import { parse } from "mavka-parser";

class FileLoader extends Loader {
  constructor(mavka) {
    super(mavka);

    this.loadedModules = {};
  }

  async load(context, path, pak = false, relative = false) {
    const fs = (await import("fs")).default;
    const jsPath = (await import("path")).default;

    const currentModuleDirname = relative
      ? context.get("__шлях_до_папки_модуля__").asJsValue(context)
      : context.get("__шлях_до_папки_кореневого_модуля__").asJsValue(context);

    let newModulePath = pak
      ? `${currentModuleDirname}/.паки` // todo: handle paks properly
      : `${currentModuleDirname}`;

    const newPath = [...path];

    const moduleStr = (relative ? "." : "") + path.join(".");

    for (const el of path) {
      const elPath = `${newModulePath}/${el}`;

      if (fs.existsSync(elPath)) {
        const elStat = fs.lstatSync(elPath);
        if (elStat.isDirectory()) {
          newModulePath = elPath;
          newPath.shift();
          if (!newPath.length) {
            throw `Не вдалось завантажити модуль "${moduleStr}."`;
          }
          continue;
        }
        if (elStat.isFile()) {
          throw `Не вдалось завантажити модуль "${moduleStr}."`;
        }
      }

      if (fs.existsSync(`${elPath}.м`)) {
        newModulePath = `${elPath}.м`;
        newPath.shift();
        break;
      }

      throw `Не вдалось завантажити модуль "${moduleStr}."`;
    }

    const newModuleDirname = jsPath.dirname(newModulePath);

    let name = path[path.length - newPath.length - 1];

    let module;

    if (this.loadedModules[newModulePath]) {
      module = this.loadedModules[newModulePath];
    } else {
      const moduleContext = new Context(this.mavka, this.mavka.context);
      moduleContext.set("__шлях_до_папки_кореневого_модуля__", context.get("__шлях_до_папки_кореневого_модуля__"));
      moduleContext.set("__шлях_до_кореневого_модуля__", context.get("__шлях_до_кореневого_модуля__"));
      moduleContext.set("__шлях_до_папки_модуля__", this.mavka.makeText(newModuleDirname));
      moduleContext.set("__шлях_до_модуля__", this.mavka.makeText(newModulePath));
      moduleContext.setAsync(true);

      const moduleCode = fs.readFileSync(newModulePath).toString();
      const moduleProgram = parse(moduleCode);

      module = this.mavka.makeModule(name);
      moduleContext.setModule(module);

      this.loadedModules[newModulePath] = module;

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

export default FileLoader;
