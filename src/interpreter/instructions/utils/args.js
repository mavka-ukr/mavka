/**
 * @param {Mavka} mavka
 * @param {Context} context
 * @param {Record<string, ArgNode>|ArgNode[]} args
 * @returns {Promise<Awaited<unknown>[]|{}>|*|{}}
 */
function runArgs(mavka, context, args) {
  const runSync = () => {
    if (Array.isArray(args)) {
      return args.flatMap((node) => {
        if (node.spread) {
          const value = mavka.runSync(context, node.value);

          if (mavka.isList(value)) {
            return value.meta.values;
          } else {
            return value;
          }
        } else {
          return mavka.runSync(context, node.value);
        }
      });
    } else {
      const newArgs = {};

      for (const [k, v] of Object.entries(args)) {
        newArgs[k] = mavka.runSync(context, v.value);
      }

      return newArgs;
    }
  };

  const runAsync = async () => {
    if (Array.isArray(args)) {
      return (await Promise.all(args.map(async (node) => {
        return {
          value: await mavka.runAsync(context, node.value),
          node
        };
      }))).flatMap(({ value, node }) => {
        if (node.spread) {
          if (mavka.isList(value)) {
            return value.meta.values;
          }
        }

        return value;
      });
    } else {
      const newArgs = {};

      for (const [k, v] of Object.entries(args)) {
        newArgs[k] = await mavka.runAsync(context, v.value);
      }

      return newArgs;
    }
  };

  return context.isAsync ? runAsync() : runSync();
}

export default runArgs;
