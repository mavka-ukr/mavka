import Mavka from "./main.js";
import pkg from "./package.json" assert { type: "json" };

if (Mavka.VERSION !== pkg.version) {
  throw new Error(`Version mismatch: ${Mavka.VERSION} !== ${pkg.version}`);
}

console.log("Version is OK.");
