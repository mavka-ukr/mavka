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
            throw `Не вдалось завантажити модуль "${moduleStr}"`;
          }
          continue;
        }
        if (elStat.isFile()) {
          throw `Не вдалось завантажити модуль "${moduleStr}"`;
        }
      }

      if (fs.existsSync(`${elPath}.м`)) {
        newModulePath = `${elPath}.м`;
        newPath.shift();
        break;
      }

      throw `Не вдалось завантажити модуль "${moduleStr}"`;
    }

    const newModuleDirname = jsPath.dirname(newModulePath);

    let name = path[path.length - newPath.length - 1];

    if (this.loadedModules[newModulePath]) {
      return { name, result: this.loadedModules[newModulePath] };
    }

    const moduleContext = new Context(this.mavka, this.mavka.context);
    moduleContext.set("__шлях_до_папки_кореневого_модуля__", context.get("__шлях_до_папки_кореневого_модуля__").asJsValue(context));
    moduleContext.set("__шлях_до_кореневого_модуля__", context.get("__шлях_до_кореневого_модуля__").asJsValue(context));
    moduleContext.set("__шлях_до_папки_модуля__", newModuleDirname);
    moduleContext.set("__шлях_до_модуля__", newModulePath);
    moduleContext.setAsync(true);

    const moduleCode = fs.readFileSync(newModulePath).toString();
    const moduleProgram = parse(moduleCode);

    const giveContext = new Context(this.mavka);
    giveContext.set("__шлях_до_папки_кореневого_модуля__", context.get("__шлях_до_папки_кореневого_модуля__").asJsValue(context));
    giveContext.set("__шлях_до_кореневого_модуля__", context.get("__шлях_до_кореневого_модуля__").asJsValue(context));
    giveContext.set("__шлях_до_папки_модуля__", newModuleDirname);
    giveContext.set("__шлях_до_модуля__", newModulePath);

    moduleContext.set("__give_context__", giveContext);

    this.loadedModules[newModulePath] = giveContext;

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
      result = new this.mavka.ModuleCell(this.mavka, name, giveContext);
    }

    return { name, result };
  }
}

export default FileLoader;
