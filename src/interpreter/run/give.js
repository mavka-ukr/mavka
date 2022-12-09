function runGiveNode(context, node) {
    const name = node.name;

    const givenContext = context.get('__given_context__');

    if (givenContext) {
        givenContext.set(node.as || name, context.get(name));
    }

    return node;
}

export default runGiveNode;
