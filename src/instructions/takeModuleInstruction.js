import Instruction from "./instruction.js";
import IdentifierNode from "mavka-parser/src/ast/IdentifierNode.js";
import IdentifiersChainNode from "mavka-parser/src/ast/IdentifiersChainNode.js";
import os from "os";
import fs from "fs";
import md5 from "md5";
import axios from "axios";
import { MavkaCompilationError } from "../error.js";

class TakeModuleInstruction extends Instruction {
  /**
   * @param {Scope} scope
   * @param {TakeModuleNode} node
   * @param {*} options
   * @returns {Promise<string>}
   */
  async compile(scope, node, options) {
    const rootModuleDirname = options.rootModuleDirname;
    const diName = this.mavka.putDebugInfoVarName(node);
    const di = this.mavka.debugInfoVarNames.get(diName);

    if (node.id instanceof IdentifierNode) {
      const moduleName = node.id.name;

      if (options.remoteModuleDirUrl) {
        const url = `${options.remoteModuleDirUrl}/${moduleName}.м`;
        const userHomeDir = os.homedir();
        const paksDir = `${userHomeDir}/.паки`;
        if (!fs.existsSync(paksDir)) {
          fs.mkdirSync(paksDir);
        }
        const dir = `${paksDir}/${md5(options.remoteModuleDirUrl)}`;
        if (!fs.existsSync(dir)) {
          fs.mkdirSync(dir);
        }
        const file = `${dir}/${moduleName}.м`;
        if (!fs.existsSync(file)) {
          this.mavka.onPakStarted(url);
          const result = await axios
            .get(url, {
              onDownloadProgress: (progressEvent) => {
                this.mavka.onPakProgress(url, Math.floor(progressEvent.progress * 100 || 0));
              },
              responseType: "text"
            })
            .then((r) => String(r.data))
            .catch((e) => {
              this.mavka.onPakDone(url);
              throw new MavkaCompilationError(`Помилка завантаження модуля "${url}": ${e.message}`, di);
            });
          this.mavka.onPakDone(url);
          fs.writeFileSync(file, result);
        }
        return await this.mavka.loadModule(
          `${dir}/${moduleName}.м`,
          moduleName,
          node.as || moduleName,
          di,
          options
        );
      }

      return await this.mavka.loadModule(
        `${options.rootModuleDirname}/${node.id.name}.м`,
        moduleName,
        node.as || moduleName,
        di,
        options
      );
    } else if (node.id instanceof IdentifiersChainNode) {
      const path = `${node.id.toFlatArray().join("/")}.м`;
      const moduleName = path.split("/").pop().replace(".м", "");

      if (options.remoteModuleDirUrl) {
        const url = `${options.remoteModuleDirUrl}/${path}`;
        const userHomeDir = os.homedir();
        const paksDir = `${userHomeDir}/.паки`;
        if (!fs.existsSync(paksDir)) {
          fs.mkdirSync(paksDir);
        }
        const dir = `${paksDir}/${md5(options.remoteModuleDirUrl)}`;
        if (!fs.existsSync(dir)) {
          fs.mkdirSync(dir);
        }
        const file = `${dir}/${path}`;
        if (!fs.existsSync(file)) {
          this.mavka.onPakStarted(url);
          const result = await axios
            .get(url, {
              onDownloadProgress: (progressEvent) => {
                this.mavka.onPakProgress(url, Math.floor(progressEvent.progress * 100 || 0));
              },
              responseType: "text"
            })
            .then((r) => String(r.data))
            .catch((e) => {
              this.mavka.onPakDone(url);
              throw new MavkaCompilationError(`Помилка завантаження модуля "${url}": ${e.message}`, di);
            });
          this.mavka.onPakDone(url);
          fs.writeFileSync(file, result);
        }
        return await this.mavka.loadModule(
          `${dir}/${path}`,
          moduleName,
          node.as || moduleName,
          di,
          options
        );
      }

      return await this.mavka.loadModule(
        `${rootModuleDirname}/${path}`,
        moduleName,
        node.as || moduleName,
        di,
        options
      );
    }

    return "";
  }
}

export default TakeModuleInstruction;
