import { fileURLToPath } from "url";
import path from "path";
import fs from "fs";

const binPath = path.dirname(fileURLToPath(import.meta.url));
const packageJson = JSON.parse(fs.readFileSync(path.join(binPath, "/package.json"), "utf8"));

export default packageJson.version;