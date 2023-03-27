import axios from "axios";
import { parse } from "mavka-parser";

class Loader {
  constructor(mavka) {
    this.mavka = mavka;

    this.loadedRemoteModules = {};
  }

  /**
   * Load a module.
   *
   * @param {Context} context
   * @param {string[]} pathElements
   * @param {boolean} absolute
   */
  async loadModule(context, pathElements, absolute = false) {
  }

  /**
   * Load a pak.
   *
   * @param {Context} context
   * @param {string[]} pathElements
   */
  async loadPak(context, pathElements) {
  }

  /**
   * Load remote file.
   *
   * @param {Context} context
   * @param {string} url
   * @param {Object} options
   */
  async loadRemote(context, url, options = {}) {
    const rawUrl = url;

    if (!url.startsWith("http://") && !url.startsWith("https://")) {
      url = `https://${url}`;
    }

    let module = this.loadedRemoteModules[url];

    if (!this.loadedRemoteModules[url]) {
      const moduleContext = new this.mavka.Context(this.mavka, context);
      moduleContext.setAsync(true);

      const moduleCode = await axios
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

      const moduleProgram = parse(moduleCode);

      module = this.mavka.makeModule("");
      moduleContext.setModule(module);

      this.loadedRemoteModules[url] = module;

      await this.mavka.run(moduleContext, moduleProgram.body);
    }

    Object.entries(module.properties).forEach(([key, value]) => {
      context.set(key, value);
    });
  }
}

export default Loader;
