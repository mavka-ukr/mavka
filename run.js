export async function run(code) {
  // todo: maybe use "vm" instead of eval
  await eval(code);
}