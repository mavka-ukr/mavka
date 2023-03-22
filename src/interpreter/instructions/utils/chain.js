import IdentifierNode from "mavka-parser/src/ast/IdentifierNode.js";
import IdentifiersChainNode from "mavka-parser/src/ast/IdentifiersChainNode.js";

export function resolveIdentifier(mavka, main, id) {
  if (id instanceof IdentifierNode) {
    return main.get(id.name);
  }

  if (id instanceof IdentifiersChainNode) {
    const left = resolveIdentifier(mavka, main, id.left);

    return resolveIdentifier(mavka, left, id.right);
  }

  return mavka.emptyCellInstance;
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
