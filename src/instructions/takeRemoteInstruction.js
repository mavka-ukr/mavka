import Instruction from "./instruction.js";
import { unpackPackName } from "../utils.js";
import * as os from "os";
import md5 from "md5";
import fs from "fs";
import axios from "axios";

class TakeRemoteInstruction extends Instruction {
  /**
   * @param {Scope} scope
   * @param {TakeRemoteNode} node
   * @param {*}options
   * @returns {Promise<string>}
   */
  async compile(scope, node, options) {
    const diName = this.mavka.putDebugInfoVarName(node);
    const di = this.mavka.debugInfoVarNames.get(diName);
    let { url, dirUrl, name, version, local } = unpackPackName(node.url);

    if (local) {
      return await this.mavka.loadBuiltinModule(name, di, options);
    }

    const userHomeDir = os.homedir();
    const paksDir = `${userHomeDir}/.паки`;
    if (!fs.existsSync(paksDir)) {
      fs.mkdirSync(paksDir);
    }
    const dir = `${paksDir}/${md5(dirUrl)}`;
    if (!fs.existsSync(dir)) {
      fs.mkdirSync(dir);
    }
    const file = `${dir}/${name}.м`;
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
          this.mavka.onPakFailed(url, e);
        });
      this.mavka.onPakDone(url);
      fs.writeFileSync(file, result);
    }

    return await this.mavka.loadModule(
      `${dir}/${name}.м`,
      name,
      node.as || name,
      di,
      {
        rootModuleDirname: dir,
        currentModuleDirname: dir,
        remoteModuleDirUrl: dirUrl
      }
    );
  }
}

export default TakeRemoteInstruction;
