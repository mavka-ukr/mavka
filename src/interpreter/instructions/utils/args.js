function runArgs(mavka, context, args) {
  const runSync = () => {
    if (Array.isArray(args)) {
      return args.map((node) => mavka.runSync(context, node.value));
    } else {
      args = { ...args };

      for (const [k, v] of Object.entries(args)) {
        args[k] = mavka.runSync(context, v.value);
      }

      return args;
    }
  };

  const runAsync = async () => {
    if (Array.isArray(args)) {
      return await Promise.all(args.map((node) => mavka.runAsync(context, node.value)));
    } else {
      args = { ...args };

      for (const [k, v] of Object.entries(args)) {
        args[k] = await mavka.runAsync(context, v.value);
      }

      return args;
    }
  };

  return context.isAsync ? runAsync() : runSync();
}

export default runArgs;
