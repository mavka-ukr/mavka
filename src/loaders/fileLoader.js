import Loader from "./loader.js";
import { parse } from "mavka-parser";

import fs from "fs";
import path from "path";
import axios from "axios";

class FileLoader extends Loader {
  constructor(mavka) {
    super(mavka);

    this.loadedModules = {};
  }

  async loadFile(context, modulePath) {
    if (this.loadedModules[modulePath]) {
      return this.loadedModules[modulePath];
    }

    const modulePathDirname = path.dirname(modulePath);

    const fileName = modulePath.split("/").pop();
    const name = fileName.substring(0, fileName.length - 2);

    const moduleContext = new this.mavka.Context(this.mavka, this.mavka.context);
    moduleContext.set("__шлях_до_папки_модуля__", this.mavka.makeText(modulePathDirname));
    moduleContext.setAsync(true);

    const moduleCode = fs.readFileSync(modulePath).toString();
    const moduleProgram = parse(moduleCode);

    const module = this.mavka.makeModule(name);
    moduleContext.setModule(module);

    this.loadedModules[modulePath] = module;

    await this.mavka.run(moduleContext, moduleProgram.body);

    return module;
  }

  async loadModule(context,
                   pathElements,
                   absolute = false) {
    const prettyModulePath = `${absolute ? "." : ""}${pathElements.join(".")}`;

    let moduleToLoad = absolute
      ? context.get("__шлях_до_папки_кореневого_модуля__").asJsValue(context)
      : context.get("__шлях_до_папки_модуля__").asJsValue(context);
    let tailPath = [...pathElements];

    for (const fileOrFolder of pathElements) {
      const fileOrFolderPath = `${moduleToLoad}/${fileOrFolder}`;

      if (fs.existsSync(fileOrFolderPath)) {
        if (tailPath.length <= 1) {
          this.mavka.fall(context, this.mavka.makeText(`Не вдалось завантажити модуль "${prettyModulePath}".`));
        }

        moduleToLoad = fileOrFolderPath;
        tailPath.shift();
      }

      if (fs.existsSync(`${fileOrFolderPath}.м`)) {
        moduleToLoad = `${fileOrFolderPath}.м`;
        tailPath.shift();
        break;
      }
    }

    let module = await this.loadFile(context, moduleToLoad);

    let name = pathElements[pathElements.length - tailPath.length - 1];

    let result = module;

    if (tailPath.length) {
      let first = tailPath.shift();
      while (first) {
        name = first;
        if (result instanceof this.mavka.Context) {
          result = result.get(first);
        } else {
          result = result.get(context, first);
        }
        first = tailPath.shift();
      }
    }

    return { name, result };
  }

  async loadPak(context, pathElements) {
    let name = pathElements[0];
    pathElements = pathElements.slice(1);

    const pathToPak = `${context.get("__шлях_до_папки_паків__").asJsValue(context)}/${name}`;

    const pakModuleContext = new this.mavka.Context(this.mavka, this.mavka.context);
    pakModuleContext.set("__шлях_до_папки_кореневого_модуля__", this.mavka.makeText(pathToPak));
    pakModuleContext.set("__шлях_до_папки_модуля__", this.mavka.makeText(pathToPak));
    pakModuleContext.setAsync(true);

    let module;

    if (fs.existsSync(`${pathToPak}/${name}.м`)) {
      // load file with same name as main module
      const { name: resultName, result } = await this.loadModule(pakModuleContext, [name, ...pathElements]);
      name = resultName;
      module = result;
    } else if (pathElements.length) {
      // load file module
      const { name: resultName, result } = await this.loadModule(pakModuleContext, [...pathElements]);
      name = resultName;
      module = result;
    } else {
      // load all files
      module = this.mavka.makeModule(name);

      for (const file of fs.readdirSync(pathToPak)) {
        if (file.endsWith(".м")) {
          const loadedModule = await this.loadFile(pakModuleContext, `${pathToPak}/${file}`);

          module.set(context, loadedModule.meta.name, loadedModule);
        }
      }
    }

    return { name, result: module };
  }

  async loadRemote(context, url, options = {}) {
    const rawUrl = url;

    if (!url.startsWith("http://") && !url.startsWith("https://")) {
      url = `https://${url}`;
    }

    let module = this.loadedRemoteModules[rawUrl];

    if (!this.loadedRemoteModules[rawUrl]) {
      const moduleContext = new this.mavka.Context(this.mavka, this.mavka.context);
      moduleContext.setAsync(true);

      let moduleCode;

      const rootPath = context.get("__шлях_до_папки_кореневого_модуля__").asJsValue(context);
      const cleanUrl = rawUrl.replaceAll("/", "__").replaceAll(".", "_");
      const cloudPaksPath = `${rootPath}/.хмарні_паки`;
      const modulePath = `${cloudPaksPath}/${cleanUrl}.м`;

      if (!fs.existsSync(cloudPaksPath)) {
        fs.mkdirSync(cloudPaksPath);
      }

      if (fs.existsSync(modulePath)) {
        moduleCode = fs.readFileSync(modulePath).toString();
      } else {
        moduleCode = await axios
          .get(url, {
            onDownloadProgress: (progressEvent) => {
              if (options.onProgress) {
                options.onProgress(Math.floor(progressEvent.progress * 100));
              }
            },
            responseType: "text"
          })
          .then((r) => String(r.data))
          .catch((e) => {
            if (options.onFailed) {
              options.onFailed(e);
            }

            this.mavka.fall(context, this.mavka.makeText(`Не вдалось завантажити "${rawUrl}".`));
          });

        fs.writeFileSync(modulePath, moduleCode);
      }

      const moduleProgram = parse(moduleCode);

      module = this.mavka.makeModule("");
      moduleContext.setModule(module);

      this.loadedRemoteModules[rawUrl] = module;

      await this.mavka.run(moduleContext, moduleProgram.body);
    }

    Object.entries(module.properties).forEach(([key, value]) => {
      context.set(key, value);
    });
  }
}

export default FileLoader;
