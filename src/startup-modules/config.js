const driveLetterPattern = /^\/[A-Z]:\//;
let startupModuleDirectory = new URL("./", import.meta.url).pathname;

if (driveLetterPattern.test(startupModuleDirectory)) {
  startupModuleDirectory = startupModuleDirectory.substring(1);
}

startupModuleDirectory = startupModuleDirectory.replaceAll("\\", "/");

export default startupModuleDirectory;
