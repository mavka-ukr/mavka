import fs from "fs";
import path from "path";

const driveLetterPattern = /^\/[A-Z]:\//;
let startupModuleDirectory = new URL("./", import.meta.url).pathname + "lib";
if (driveLetterPattern.test(startupModuleDirectory)) {
  startupModuleDirectory = startupModuleDirectory.substring(1);
}
startupModuleDirectory = startupModuleDirectory.replaceAll("\\", "/");
const startupModuleFiles = fs.readdirSync(startupModuleDirectory);

const allModules = [];

for (const moduleFileName of startupModuleFiles) {
  const moduleFilePath = path.join(startupModuleDirectory, moduleFileName).replaceAll("\\", "/");

  const moduleContent = fs.readFileSync(moduleFilePath).toString();

  allModules.push({
    name: moduleFileName,
    content: moduleContent
  });
}

export default allModules;