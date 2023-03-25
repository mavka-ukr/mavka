import IdentifierNode from "mavka-parser/src/ast/IdentifierNode.js";
import IdentifiersChainNode from "mavka-parser/src/ast/IdentifiersChainNode.js";

export function resolveIdentifier(mavka, context, main, id) {
  if (id instanceof IdentifierNode) {
    if (main instanceof mavka.Context) {
      return main.get(id.name);
    }
    return main.get(context, id.name);
  }

  if (id instanceof IdentifiersChainNode) {
    const left = resolveIdentifier(mavka, context, main, id.left);

    return resolveIdentifier(mavka, context, left, id.right);
  }

  return mavka.empty;
}

export function lastIdentifierName(id) {
  if (id instanceof IdentifierNode) {
    return id.name;
  }

  if (id instanceof IdentifiersChainNode) {
    return id.right.name;
  }

  return null;
}
