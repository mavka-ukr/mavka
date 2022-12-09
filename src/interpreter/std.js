import { AsyncVal, DiiaVal, JsFunctionVal, NumberVal, RangeVal, StringVal } from "./val/index.js";
import promptSync from "prompt-sync";

class RangeDiiaVal extends DiiaVal {
    constructor() {
        super();
    }

    call(args) {
        if (Array.isArray(args)) {
            return new RangeVal(args[0], args[1], args[2] || new NumberVal(1));
        } else {
            return new RangeVal(args.from, args.to, args.step || new NumberVal(1));
        }
    }
}

export const rangeFnVal = new RangeDiiaVal();
export const printFnVal = new JsFunctionVal((...args) => console.log(
    ...args
        .map((arg) => arg.asString())
        .map((arg) => arg.properties['__value__'])
));
export const loadExtensionFileFnVal = new JsFunctionVal((path) => {
    return new AsyncVal(import(path));
});
export const httpGet = new JsFunctionVal((url) => {
    url = url.asString().asJsString();

    return new AsyncVal(fetch(url).then((r) => r.text()).then((text) => new StringVal(text)));
});
export const readInputFnVal = new JsFunctionVal((q = new StringVal('')) => {
    return new StringVal(promptSync({ sigint: true })(q.asString().asJsString()));
});
export const toNumberFnVal = new JsFunctionVal((value) => {
    return value.asNumber();
});
export const toStringFnVal = new JsFunctionVal((value) => {
    return value.asString();
});
