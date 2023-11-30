import ChainInstruction from "./instructions/chainInstruction.js";
import NumberInstruction from "./instructions/numberInstruction.js";
import StringInstruction from "./instructions/stringInstruction.js";
import ChainNode from "mavka-parser/src/ast/ChainNode.js";
import NumberNode from "mavka-parser/src/ast/NumberNode.js";
import StringNode from "mavka-parser/src/ast/StringNode.js";
import CallNode from "mavka-parser/src/ast/CallNode.js";
import CallInstruction from "./instructions/callInstruction.js";
import IdentifierInstruction from "./instructions/identifierInstruction.js";
import IdentifierNode from "mavka-parser/src/ast/IdentifierNode.js";
import IdentifiersChainInstruction from "./instructions/identifiersChainInstruction.js";
import IdentifiersChainNode from "mavka-parser/src/ast/IdentifiersChainNode.js";
import ArithmeticNode from "mavka-parser/src/ast/ArithmeticNode.js";
import ArithmeticInstruction from "./instructions/arithmeticInstruction.js";
import DiiaInstruction from "./instructions/diiaInstruction.js";
import DiiaNode from "mavka-parser/src/ast/DiiaNode.js";
import StructureInstruction from "./instructions/structureInstruction.js";
import StructureNode from "mavka-parser/src/ast/StructureNode.js";
import EachInstruction from "./instructions/eachInstruction.js";
import EachNode from "mavka-parser/src/ast/EachNode.js";
import ModuleInstruction from "./instructions/moduleInstruction.js";
import ModuleNode from "mavka-parser/src/ast/ModuleNode.js";
import GiveInstruction from "./instructions/giveInstruction.js";
import GiveNode from "mavka-parser/src/ast/GiveNode.js";
import ArrayInstruction from "./instructions/arrayInstruction.js";
import ArrayNode from "mavka-parser/src/ast/ArrayNode.js";
import IfInstruction from "./instructions/ifInstruction.js";
import IfNode from "mavka-parser/src/ast/IfNode.js";
import TestInstruction from "./instructions/testInstruction.js";
import TestNode from "mavka-parser/src/ast/TestNode.js";
import ComparisonInstruction from "./instructions/comparisonInstruction.js";
import ComparisonNode from "mavka-parser/src/ast/ComparisonNode.js";
import ReturnInstruction from "./instructions/returnInstruction.js";
import ReturnNode from "mavka-parser/src/ast/ReturnNode.js";
import DictionaryInstruction from "./instructions/dictionaryInstruction.js";
import DictionaryNode from "mavka-parser/src/ast/DictionaryNode.js";
import TryInstruction from "./instructions/tryInstruction.js";
import TryNode from "mavka-parser/src/ast/TryNode.js";
import ThrowInstruction from "./instructions/throwInstruction.js";
import ThrowNode from "mavka-parser/src/ast/ThrowNode.js";
import WaitInstruction from "./instructions/waitInstruction.js";
import WaitNode from "mavka-parser/src/ast/WaitNode.js";
import GetElementInstruction from "./instructions/getElementInstruction.js";
import GetElementNode from "mavka-parser/src/ast/GetElementNode.js";
import FunctionInstruction from "./instructions/functionInstruction.js";
import FunctionNode from "mavka-parser/src/ast/FunctionNode.js";
import EvalInstruction from "./instructions/evalInstruction.js";
import EvalNode from "mavka-parser/src/ast/EvalNode.js";
import WhileInstruction from "./instructions/whileInstruction.js";
import WhileNode from "mavka-parser/src/ast/WhileNode.js";
import AnonymousDiiaInstruction from "./instructions/anonymousDiiaInstruction.js";
import AnonymousDiiaNode from "mavka-parser/src/ast/AnonymousDiiaNode.js";
import AssignSimpleInstruction from "./instructions/assignSimpleInstruction.js";
import AssignComplexInstruction from "./instructions/assignComplexInstruction.js";
import AssignSimpleNode from "mavka-parser/src/ast/AssignSimpleNode.js";
import AssignComplexNode from "mavka-parser/src/ast/AssignComplexNode.js";
import BitwiseInstruction from "./instructions/bitwiseInstruction.js";
import BitwiseNotInstruction from "./instructions/bitwiseNotInstruction.js";
import BitwiseNotNode from "mavka-parser/src/ast/BitwiseNotNode.js";
import BitwiseNode from "mavka-parser/src/ast/BitwiseNode.js";
import BreakNode from "mavka-parser/src/ast/BreakNode.js";
import BreakInstruction from "./instructions/breakInstruction.js";
import ContinueNode from "mavka-parser/src/ast/ContinueNode.js";
import ContinueInstruction from "./instructions/continueInstruction.js";
import NegativeInstruction from "./instructions/negativeInstruction.js";
import NotInstruction from "./instructions/notInstruction.js";
import PositiveInstruction from "./instructions/positiveInstruction.js";
import PostDecrementInstruction from "./instructions/postDecrementInstruction.js";
import NegativeNode from "mavka-parser/src/ast/NegativeNode.js";
import NotNode from "mavka-parser/src/ast/NotNode.js";
import PositiveNode from "mavka-parser/src/ast/PositiveNode.js";
import PostDecrementNode from "mavka-parser/src/ast/PostDecrementNode.js";
import PostIncrementInstruction from "./instructions/postIncrementInstruction.js";
import PostIncrementNode from "mavka-parser/src/ast/PostIncrementNode.js";
import PreDecrementInstruction from "./instructions/preDecrementInstruction.js";
import PreIncrementInstruction from "./instructions/preIncrementInstruction.js";
import PreDecrementNode from "mavka-parser/src/ast/PreDecrementNode.js";
import PreIncrementNode from "mavka-parser/src/ast/PreIncrementNode.js";
import { processBody, varname } from "./utils.js";
import TypeValueInstruction from "./instructions/typeValueInstruction.js";
import TypeValueNode from "mavka-parser/src/ast/TypeValueNode.js";
import TypeValueSingleNode from "mavka-parser/src/ast/TypeValueSingleNode.js";
import TypeValueSingleInstruction from "./instructions/typeValueSingleInstruction.js";
import GodInstruction from "./instructions/godInstruction.js";
import GodNode from "mavka-parser/src/ast/GodNode.js";
import AsInstruction from "./instructions/asInstruction.js";
import AsNode from "mavka-parser/src/ast/AsNode.js";
import TakeModuleInstruction from "./instructions/takeModuleInstruction.js";
import TakeModuleNode from "mavka-parser/src/ast/TakeModuleNode.js";
import Scope from "./scope.js";
import TakeRemoteInstruction from "./instructions/takeRemoteInstruction.js";
import TakeRemoteNode from "mavka-parser/src/ast/TakeRemoteNode.js";
import md5 from "md5";
import { parse } from "mavka-parser";
import TernaryInstruction from "./instructions/ternaryInstruction.js";
import TernaryNode from "mavka-parser/src/ast/TernaryNode.js";
import { MavkaCompilationError } from "./error.js";
import { DiiaParserSyntaxError } from "mavka-parser/src/utils/errors.js";

let DEBUG_ID = 0;

class Mavka {
  static VERSION = "0.60.0";

  constructor(options = {}) {
    this.debugInfoVarNames = new Map();
    this.putDebugInfoVarName = (node) => {
      const debugInfoVarName = `D_${DEBUG_ID++}`;
      this.debugInfoVarNames.set(debugInfoVarName, [node.context.fileinfo.path, node.context.start.line, node.context.start.column]);
      return debugInfoVarName;
    };

    this.parse = parse;
    this.Scope = Scope;
    this.MavkaCompilationError = MavkaCompilationError;
    this.DiiaParserSyntaxError = DiiaParserSyntaxError;

    this.options = options;

    this.globalScope = new Scope(null, new Map([
      // head
      ["пусто", true],
      ["логічне", true],
      ["число", true],
      ["текст", true],
      ["список", true],
      ["словник", true],
      ["Дія", true],
      ["Структура", true],
      ["Модуль", true],
      ["так", true],
      ["ні", true],
      ["Помилка", true],
      ["байти", true],
      // std
      ["друк", true],
      ["вивести", true],
      ["читати", true],
      ["діапазон", true],
      ["___шлях_до_модуля___", true]
    ]));

    this.modules = new Map();

    this.anonymousDiiaInstruction = new AnonymousDiiaInstruction(this);
    this.arithmeticInstruction = new ArithmeticInstruction(this);
    // this.arrayDestructionInstruction = new ArrayDestructionInstruction(this);
    this.arrayInstruction = new ArrayInstruction(this);
    this.asInstruction = new AsInstruction(this);
    this.assignComplexInstruction = new AssignComplexInstruction(this);
    this.assignSimpleInstruction = new AssignSimpleInstruction(this);
    this.bitwiseInstruction = new BitwiseInstruction(this);
    this.bitwiseNotInstruction = new BitwiseNotInstruction(this);
    this.breakInstruction = new BreakInstruction(this);
    this.callInstruction = new CallInstruction(this);
    this.chainInstruction = new ChainInstruction(this);
    this.comparisonInstruction = new ComparisonInstruction(this);
    this.continueInstruction = new ContinueInstruction(this);
    this.diiaInstruction = new DiiaInstruction(this);
    this.eachInstruction = new EachInstruction(this);
    this.evalInstruction = new EvalInstruction(this);
    // this.fromtoInstruction = new FromtoInstruction(this);
    this.functionInstruction = new FunctionInstruction(this);
    this.getElementInstruction = new GetElementInstruction(this);
    this.giveInstruction = new GiveInstruction(this);
    this.godInstruction = new GodInstruction(this);
    this.identifierInstruction = new IdentifierInstruction(this);
    this.identifiersChainInstruction = new IdentifiersChainInstruction(this);
    this.ifInstruction = new IfInstruction(this);
    this.moduleInstruction = new ModuleInstruction(this);
    this.negativeInstruction = new NegativeInstruction(this);
    this.notInstruction = new NotInstruction(this);
    this.numberInstruction = new NumberInstruction(this);
    // this.objectDestructionInstruction = new ObjectDestructionInstruction(this);
    this.dictionaryInstruction = new DictionaryInstruction(this);
    this.positiveInstruction = new PositiveInstruction(this);
    this.postDecrementInstruction = new PostDecrementInstruction(this);
    this.postIncrementInstruction = new PostIncrementInstruction(this);
    this.preDecrementInstruction = new PreDecrementInstruction(this);
    this.preIncrementInstruction = new PreIncrementInstruction(this);
    this.dictionaryInstruction = new DictionaryInstruction(this);
    this.returnInstruction = new ReturnInstruction(this);
    this.stringInstruction = new StringInstruction(this);
    this.structureInstruction = new StructureInstruction(this);
    // this.takeFileInstruction = new TakeFileInstruction(this);
    this.takeModuleInstruction = new TakeModuleInstruction(this);
    // this.takePakInstruction = new TakePakInstruction(this);
    this.takeRemoteInstruction = new TakeRemoteInstruction(this);
    this.ternaryInstruction = new TernaryInstruction(this);
    this.testInstruction = new TestInstruction(this);
    this.throwInstruction = new ThrowInstruction(this);
    this.tryInstruction = new TryInstruction(this);
    this.typeValueInstruction = new TypeValueInstruction(this);
    this.typeValueSingleInstruction = new TypeValueSingleInstruction(this);
    this.waitInstruction = new WaitInstruction(this);
    this.whileInstruction = new WhileInstruction(this);
  }

  /**
   * @param {Scope} scope
   * @param {ASTNode} node
   * @param {Object} options
   * @return {Promise<string>}
   */
  async compileNode(scope, node, options = {}) {
    if (node instanceof AnonymousDiiaNode) {
      return await this.anonymousDiiaInstruction.compile(scope, node, options);
    }

    if (node instanceof ArithmeticNode) {
      return await this.arithmeticInstruction.compile(scope, node, options);
    }

    if (node instanceof ArrayNode) {
      return await this.arrayInstruction.compile(scope, node, options);
    }

    if (node instanceof AsNode) {
      return await this.asInstruction.compile(scope, node, options);
    }

    if (node instanceof AssignComplexNode) {
      return await this.assignComplexInstruction.compile(scope, node, options);
    }

    if (node instanceof AssignSimpleNode) {
      return await this.assignSimpleInstruction.compile(scope, node, options);
    }

    if (node instanceof BitwiseNode) {
      return await this.bitwiseInstruction.compile(scope, node, options);
    }

    if (node instanceof BitwiseNotNode) {
      return await this.bitwiseNotInstruction.compile(scope, node, options);
    }

    if (node instanceof BreakNode) {
      return await this.breakInstruction.compile(scope, node, options);
    }

    if (node instanceof CallNode) {
      return await this.callInstruction.compile(scope, node, options);
    }

    if (node instanceof ChainNode) {
      return await this.chainInstruction.compile(scope, node, options);
    }

    if (node instanceof ComparisonNode) {
      return await this.comparisonInstruction.compile(scope, node, options);
    }

    if (node instanceof ContinueNode) {
      return await this.continueInstruction.compile(scope, node, options);
    }

    if (node instanceof DiiaNode) {
      return await this.diiaInstruction.compile(scope, node, options);
    }

    if (node instanceof EachNode) {
      return await this.eachInstruction.compile(scope, node, options);
    }

    if (node instanceof EvalNode) {
      return await this.evalInstruction.compile(scope, node, options);
    }

    if (node instanceof FunctionNode) {
      return await this.functionInstruction.compile(scope, node, options);
    }

    if (node instanceof GetElementNode) {
      return await this.getElementInstruction.compile(scope, node, options);
    }

    if (node instanceof GiveNode) {
      return await this.giveInstruction.compile(scope, node, options);
    }

    if (node instanceof GodNode) {
      return await this.godInstruction.compile(scope, node, options);
    }

    if (node instanceof IdentifierNode) {
      return await this.identifierInstruction.compile(scope, node, options);
    }

    if (node instanceof IdentifiersChainNode) {
      return await this.identifiersChainInstruction.compile(scope, node, options);
    }

    if (node instanceof IfNode) {
      return await this.ifInstruction.compile(scope, node, options);
    }

    if (node instanceof ModuleNode) {
      return await this.moduleInstruction.compile(scope, node, options);
    }

    if (node instanceof NegativeNode) {
      return await this.negativeInstruction.compile(scope, node, options);
    }

    if (node instanceof NotNode) {
      return await this.notInstruction.compile(scope, node, options);
    }

    if (node instanceof NumberNode) {
      return await this.numberInstruction.compile(scope, node, options);
    }

    if (node instanceof PositiveNode) {
      return await this.positiveInstruction.compile(scope, node, options);
    }

    if (node instanceof PostDecrementNode) {
      return await this.postDecrementInstruction.compile(scope, node, options);
    }

    if (node instanceof PostIncrementNode) {
      return await this.postIncrementInstruction.compile(scope, node, options);
    }

    if (node instanceof PreDecrementNode) {
      return await this.preDecrementInstruction.compile(scope, node, options);
    }

    if (node instanceof PreIncrementNode) {
      return await this.preIncrementInstruction.compile(scope, node, options);
    }

    if (node instanceof DictionaryNode) {
      return await this.dictionaryInstruction.compile(scope, node, options);
    }

    if (node instanceof ReturnNode) {
      return await this.returnInstruction.compile(scope, node, options);
    }

    if (node instanceof StringNode) {
      return await this.stringInstruction.compile(scope, node, options);
    }

    if (node instanceof StructureNode) {
      return await this.structureInstruction.compile(scope, node, options);
    }

    if (node instanceof TakeModuleNode) {
      return await this.takeModuleInstruction.compile(scope, node, options);
    }

    if (node instanceof TakeRemoteNode) {
      return await this.takeRemoteInstruction.compile(scope, node, options);
    }

    if (node instanceof TernaryNode) {
      return await this.ternaryInstruction.compile(scope, node, options);
    }

    if (node instanceof TestNode) {
      return await this.testInstruction.compile(scope, node, options);
    }

    if (node instanceof ThrowNode) {
      return await this.throwInstruction.compile(scope, node, options);
    }

    if (node instanceof TryNode) {
      return await this.tryInstruction.compile(scope, node, options);
    }

    if (node instanceof TypeValueNode) {
      return await this.typeValueInstruction.compile(scope, node, options);
    }

    if (node instanceof TypeValueSingleNode) {
      return await this.typeValueSingleInstruction.compile(scope, node, options);
    }

    if (node instanceof WaitNode) {
      return await this.waitInstruction.compile(scope, node, options);
    }

    if (node instanceof WhileNode) {
      return await this.whileInstruction.compile(scope, node, options);
    }

    throw `${node.constructor} is not supported`;
  }

  /**
   * @param {Scope} scope
   * @param {ASTNode[]} body
   * @param {*} options
   * @returns {Promise<string>}
   */
  async compileBody(scope, body, options) {
    const lines = [];

    for (const node of body) {
      lines.push(await this.compileNode(scope, node, options));
    }

    return lines.map((l) => `${l};`).join("\n");
  }

  /**
   * @param {Scope} scope
   * @param {ASTNode[]} body
   * @param {*} options
   * @returns {Promise<string>}
   */
  async compileDiiaBody(scope, body, options) {
    const lines = [];

    for (let i = 0; i < body.length; i++) {
      const node = body[i];
      const value = await this.compileNode(scope, node, options);
      if (i === body.length - 1 && !(node instanceof ReturnNode) && !(node instanceof EachNode) && !(node instanceof WhileNode) && !(node instanceof IfNode) && !(node instanceof BreakNode) && !(node instanceof ContinueNode)) {
        lines.push(`return ${value}`);
      } else {
        lines.push(value);
      }
    }

    return lines.map((l) => `${l};`).join("\n");
  }

  /**
   * @param {Scope} scope
   * @param {ASTNode[]} body
   * @param {*} options
   * @returns {Promise<string>}
   */
  async compileModuleBody(scope, body, options) {
    const lines = [];

    for (const element of body) {
      lines.push(await this.compileNode(scope, element, options));
    }

    [...scope.setters]
      .map((v) => `var set${varname(v)} = (v) => { ${varname(v)} = v; }`)
      .forEach((v) => {
        lines.unshift(v);
      });

    [...scope.vars.entries()]
      .filter(([, value]) => value !== false)
      .map(([name]) => name)
      .forEach((v) => {
        lines.unshift(`var ${varname(v)}`);
      });

    return lines.map((l) => `${l};`).join("\n");
  }

  /**
   * @param {Scope} scope
   * @param {ASTNode[]} body
   * @param {*} options
   * @returns {Promise<string>}
   */
  async compileProgramBody(scope, body, options) {
    const lines = [];

    for (const element of body) {
      lines.push(await this.compileNode(scope, element, options));
    }

    [...scope.setters]
      .map((v) => `var set${varname(v)} = (v) => { ${varname(v)} = v; }`)
      .forEach((v) => {
        lines.unshift(v);
      });

    for (const [, v] of this.modules.entries()) {
      lines.unshift(v);
    }

    [...scope.vars.entries()]
      .filter(([, value]) => value !== false)
      .map(([name]) => name)
      .forEach((v) => {
        lines.unshift(`var ${varname(v)}`);
      });

    [...this.debugInfoVarNames.entries()].forEach(([name, value]) => {
      lines.unshift(`var ${name} = ${JSON.stringify(value)}`);
    });

    return lines.map((l) => `${l};`).join("\n");
  }

  async loadModule(relative, parts, as, di, options) {
    const moduleName = await this.options.getModuleName(relative, parts, di, options);
    const modulePath = await this.options.getModulePath(relative, parts, di, options);
    const tempModuleName = `${moduleName}_${md5(modulePath)}`;

    const initModuleCode = `
await init_${tempModuleName}();
${varname(as || moduleName)} = ${tempModuleName};
`.trim();

    if (this.modules.has(tempModuleName)) {
      return initModuleCode;
    }

    this.modules.set(tempModuleName, "");

    const moduleCode = await this.options.getModuleCode(relative, parts, di, options);
    const moduleAst = parse(moduleCode, {
      path: modulePath
    });
    const moduleScope = new Scope(this.globalScope);
    const moduleBody = await this.compileModuleBody(
      moduleScope,
      await processBody(this, moduleScope, moduleAst.body),
      {
        ...options,
        currentModulePath: modulePath
      }
    );

    const compiledModuleCode = `
var ${tempModuleName};
var init_${tempModuleName} = async function() {
  if (${tempModuleName}) {
    return;
  }
  var moduleValue = mavka_module("${moduleName}");
  ${tempModuleName} = moduleValue;
  await (async function() {
    var м____шлях_до_модуля___ = "${modulePath}";
    ${moduleBody}
  })();
};
`.trim();

    this.modules.set(tempModuleName, compiledModuleCode);

    return initModuleCode;
  }

  async loadBuiltinModule(parts, as, di, options) {
    const name = parts[parts.length - 1];
    const tempModuleName = `${name}_${md5(`вбудований-пак:${parts.join(".")}`)}`;

    const initModuleCode = `
await init_${tempModuleName}();
${varname(as || name)} = ${tempModuleName};
`.trim();

    if (this.modules.has(tempModuleName)) {
      return initModuleCode;
    }

    this.modules.set(tempModuleName, "");

    const moduleCode = await this.options.getBuiltinModuleCode(parts, di, options);

    const compiledModuleCode = `
var ${tempModuleName};
var init_${tempModuleName} = async function() {
  if (${tempModuleName}) {
    return;
  }
  var moduleValue = await ${moduleCode};
  ${tempModuleName} = moduleValue;
};
`.trim();

    this.modules.set(tempModuleName, compiledModuleCode);

    return initModuleCode;
  }

  async loadRemoteModule(parts, as, di, options) {
    const moduleName = await this.options.getRemoteModuleName(parts, di, options);
    const modulePath = await this.options.getRemoteModulePath(parts, di, options);
    const tempModuleName = `${moduleName}_${md5(modulePath)}`;

    const initModuleCode = `
await init_${tempModuleName}();
${varname(as || moduleName)} = ${tempModuleName};
`.trim();

    if (this.modules.has(tempModuleName)) {
      return initModuleCode;
    }

    this.modules.set(tempModuleName, "");

    const moduleCode = await this.options.getRemoteModuleCode(parts, di, options);
    const moduleAst = parse(moduleCode, {
      path: modulePath
    });
    const moduleScope = new Scope(this.globalScope);
    const moduleBody = await this.compileModuleBody(
      moduleScope,
      await processBody(this, moduleScope, moduleAst.body),
      {
        ...options,
        rootModulePath: modulePath,
        currentModulePath: modulePath
      }
    );

    const compiledModuleCode = `
var ${tempModuleName};
var init_${tempModuleName} = async function() {
  if (${tempModuleName}) {
    return;
  }
  var moduleValue = mavka_module("${moduleName}");
  ${tempModuleName} = moduleValue;
  await (async function() {
    var м____шлях_до_модуля___ = "${modulePath}";
    ${moduleBody}
  })();
};
`.trim();

    this.modules.set(tempModuleName, compiledModuleCode);

    return initModuleCode;
  }
}

export default Mavka;

