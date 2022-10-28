import promptSync from "prompt-sync";
import fs from "fs";

class DiiaArray extends Array {
    constructor(...args) {
        super(...args);
    }

    toString() {
        return 'масив(' + this.map((v) => v.toString()).join(', ') + ')';
    }
}

class DiiaObject {
    constructor(args) {
        Object.assign(this, args)
    }
}

global.DiiaArray = DiiaArray;
global.DiiaObject = DiiaObject;

function diia_read(question = '') {
    if (!global.__diia_prompt__) {
        global.__diia_prompt__ = promptSync({ sigint: true });
    }

    return global.__diia_prompt__(question);
}

function* diia_range(start = 0, end = Infinity, step = 1) {
    let iterationCount = 0;

    for (let i = start; i < end; i += step) {
        iterationCount++;
        yield i;
    }

    return iterationCount;
}

function* diia_eval(start = 0, end = Infinity, step = 1) {
    let iterationCount = 0;

    for (let i = start; i < end; i += step) {
        iterationCount++;
        yield i;
    }

    return iterationCount;
}

global.diia_read = diia_read;
global.diia_range = diia_range;

global.diia_node_fs = fs;
