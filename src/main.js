import { Cell } from "./interpreter/cells/common/cell.js";
import AssignInstruction from "./interpreter/instructions/assignInstruction.js";
import ChainInstruction from "./interpreter/instructions/chainInstruction.js";
import DiiaInstruction from "./interpreter/instructions/diiaInstruction.js";
import EachInstruction from "./interpreter/instructions/eachInstruction.js";
import ArithmeticInstruction from "./interpreter/instructions/arithmeticInstruction.js";
import IfInstruction from "./interpreter/instructions/ifInstruction.js";
import FunctionInstruction from "./interpreter/instructions/functionInstruction.js";
import NumberInstruction from "./interpreter/instructions/numberInstruction.js";
import ReturnInstruction, { ReturnSignal } from "./interpreter/instructions/returnInstruction.js";
import StringInstruction from "./interpreter/instructions/stringInstruction.js";
import StructureInstruction from "./interpreter/instructions/structureInstruction.js";
import ComparisonInstruction from "./interpreter/instructions/comparisonInstruction.js";
import WaitInstruction from "./interpreter/instructions/waitInstruction.js";
import GiveInstruction from "./interpreter/instructions/giveInstruction.js";
import ChainNode from "mavka-parser/src/ast/ChainNode.js";
import ArithmeticNode from "mavka-parser/src/ast/ArithmeticNode.js";
import NumberNode from "mavka-parser/src/ast/NumberNode.js";
import StringNode from "mavka-parser/src/ast/StringNode.js";
import BooleanNode from "mavka-parser/src/ast/BooleanNode.js";
import DiiaNode from "mavka-parser/src/ast/DiiaNode.js";
import IfNode from "mavka-parser/src/ast/IfNode.js";
import TestNode from "mavka-parser/src/ast/TestNode.js";
import AssignNode from "mavka-parser/src/ast/AssignNode.js";
import ReturnNode from "mavka-parser/src/ast/ReturnNode.js";
import EachNode from "mavka-parser/src/ast/EachNode.js";
import StructureNode from "mavka-parser/src/ast/StructureNode.js";
import WaitNode from "mavka-parser/src/ast/WaitNode.js";
import GiveNode from "mavka-parser/src/ast/GiveNode.js";
import AwaitCell from "./interpreter/cells/async/awaitCell.js";
import { parse } from "mavka-parser";
import BooleanInstruction from "./interpreter/instructions/booleanInstruction.js";
import LightContext from "./interpreter/contexts/lightContext.js";
import Context from "./interpreter/contexts/context.js";
import AnonymousDiiaInstruction from "./interpreter/instructions/anonymousDiiaInstruction.js";
import AnonymousDiiaNode from "mavka-parser/src/ast/AnonymousDiiaNode.js";
import TryInstruction from "./interpreter/instructions/tryInstruction.js";
import ThrowInstruction, { ThrowValue } from "./interpreter/instructions/throwInstruction.js";
import ThrowNode from "mavka-parser/src/ast/ThrowNode.js";
import TryNode from "mavka-parser/src/ast/TryNode.js";
import WhileNode from "mavka-parser/src/ast/WhileNode.js";
import WhileInstruction from "./interpreter/instructions/whileInstruction.js";
import ModuleNode from "mavka-parser/src/ast/ModuleNode.js";
import ModuleInstruction from "./interpreter/instructions/moduleInstruction.js";
import ProgramNode from "mavka-parser/src/ast/ProgramNode.js";
import FunctionNode from "mavka-parser/src/ast/FunctionNode.js";
import CallNode from "mavka-parser/src/ast/CallNode.js";
import CallInstruction from "./interpreter/instructions/callInstruction.js";
import IdentifierInstruction from "./interpreter/instructions/identifierInstruction.js";
import IdentifierNode from "mavka-parser/src/ast/IdentifierNode.js";
import IdentifiersChainInstruction from "./interpreter/instructions/identifiersChainInstruction.js";
import ComparisonNode from "mavka-parser/src/ast/ComparisonNode.js";
import TestInstruction from "./interpreter/instructions/testInstruction.js";
import TernaryNode from "mavka-parser/src/ast/TernaryNode.js";
import TernaryInstruction from "./interpreter/instructions/ternaryInstruction.js";
import IdentifiersChainNode from "mavka-parser/src/ast/IdentifiersChainNode.js";
import PortalCell from "./interpreter/cells/portal/portalCell.js";
import Loader from "./loaders/loader.js";
import NegativeInstruction from "./interpreter/instructions/negativeInstruction.js";
import NegativeNode from "mavka-parser/src/ast/NegativeNode.js";
import ArrayInstruction from "./interpreter/instructions/arrayInstruction.js";
import ArrayNode from "mavka-parser/src/ast/ArrayNode.js";
import DictionaryInstruction from "./interpreter/instructions/dictionaryInstruction.js";
import ArrayDestructionInstruction from "./interpreter/instructions/arrayDestructionInstruction.js";
import BreakInstruction, { BreakSignal } from "./interpreter/instructions/breakInstruction.js";
import ContinueInstruction, { ContinueSignal } from "./interpreter/instructions/continueInstruction.js";
import NotInstruction from "./interpreter/instructions/notInstruction.js";
import ObjectDestructionInstruction from "./interpreter/instructions/objectDestructionInstruction.js";
import PositiveInstruction from "./interpreter/instructions/positiveInstruction.js";
import PostDecrementInstruction from "./interpreter/instructions/postDecrementInstruction.js";
import PostIncrementInstruction from "./interpreter/instructions/postIncrementInstruction.js";
import PreDecrementInstruction from "./interpreter/instructions/preDecrementInstruction.js";
import PreIncrementInstruction from "./interpreter/instructions/preIncrementInstruction.js";
import TypeValueInstruction from "./interpreter/instructions/typeValueInstruction.js";
import ArrayDestructionNode from "mavka-parser/src/ast/ArrayDestructionNode.js";
import BreakNode from "mavka-parser/src/ast/BreakNode.js";
import NotNode from "mavka-parser/src/ast/NotNode.js";
import ObjectDestructionNode from "mavka-parser/src/ast/ObjectDestructionNode.js";
import PositiveNode from "mavka-parser/src/ast/PositiveNode.js";
import PostDecrementNode from "mavka-parser/src/ast/PostDecrementNode.js";
import PostIncrementNode from "mavka-parser/src/ast/PostIncrementNode.js";
import PreDecrementNode from "mavka-parser/src/ast/PreDecrementNode.js";
import TypeValueNode from "mavka-parser/src/ast/TypeValueNode.js";
import GetElementInstruction from "./interpreter/instructions/getElementInstruction.js";
import DictionaryNode from "mavka-parser/src/ast/DictionaryNode.js";
import PortalFunctionCell from "./interpreter/cells/portal/portalFunctionCell.js";
import TextStructureCell from "./interpreter/cells/textStructureCell.js";
import BooleanStructureCell from "./interpreter/cells/booleanStructureCell.js";
import NumberStructureCell from "./interpreter/cells/numberStructureCell.js";
import DictionaryStructureCell from "./interpreter/cells/dictionaryStructureCell.js";
import ListStructureCell from "./interpreter/cells/listStructureCell.js";
import ObjectStructureCell from "./interpreter/cells/objectStructureCell.js";
import DiiaStructureCell from "./interpreter/cells/diiaStructureCell.js";
import ProxyFunctionCell from "./interpreter/cells/portal/proxyFunctionCell.js";
import EmptyCell from "./interpreter/cells/common/emptyCell.js";
import Method from "./interpreter/cells/common/method.js";
import PortalListCell from "./interpreter/cells/portal/portalListCell.js";
import PreIncrementNode from "mavka-parser/src/ast/PreIncrementNode.js";
import { fillParameters } from "./interpreter/instructions/utils/params.js";
import AsyncCell from "./interpreter/cells/async/asyncCell.js";
import ContinueNode from "mavka-parser/src/ast/ContinueNode.js";
import GetElementNode from "mavka-parser/src/ast/GetElementNode.js";
import StructureCell from "./interpreter/cells/common/structureCell.js";
import RangeStructureCell from "./library/rangeStructureCell.js";
import TakeRemoteNode from "mavka-parser/src/ast/TakeRemoteNode.js";
import TakePakNode from "mavka-parser/src/ast/TakePakNode.js";
import TakeModuleNode from "mavka-parser/src/ast/TakeModuleNode.js";
import TakeModuleInstruction from "./interpreter/instructions/takeModuleInstruction.js";
import TakePakInstruction from "./interpreter/instructions/takePakInstruction.js";
import TakeRemoteInstruction from "./interpreter/instructions/takeRemoteInstruction.js";
import ModuleStructureCell from "./interpreter/cells/moduleStructureCell.js";
import mitt from "mitt";
import TakeFileInstruction from "./interpreter/instructions/takeFileInstruction.js";
import TakeFileNode from "mavka-parser/src/ast/TakeFileNode.js";
import EvalInstruction from "./interpreter/instructions/evalInstruction.js";
import EvalNode from "mavka-parser/src/ast/EvalNode.js";
import MockupStructureCell from "./interpreter/cells/mockupStructureCell.js";
import BitwiseInstruction from "./interpreter/instructions/bitwiseInstruction.js";
import BitwiseNode from "mavka-parser/src/ast/BitwiseNode.js";
import BitwiseNotInstruction from "./interpreter/instructions/bitwiseNotInstruction.js";
import makeMathModule from "./library/mathModule.js";
import NanCell from "./interpreter/cells/common/nanCell.js";
import InfinityCell from "./interpreter/cells/common/infinityCell.js";
import BitwiseNotNode from "mavka-parser/src/ast/BitwiseNotNode.js";
import makeDidModule from "./library/didModule.js";

let extId = 0;

/**
 * @property {Context} context
 * @property {Loader} loader
 */
class Mavka {
  static VERSION = "0.11.1";

  constructor(options = {}) {
    if (!options.global) {
      options.global = global;
    }

    this.global = options.global;
    this.global.getMavka = () => this;

    this.anonymousDiiaInstruction = new AnonymousDiiaInstruction(this);
    this.arithmeticInstruction = new ArithmeticInstruction(this);
    this.arrayDestructionInstruction = new ArrayDestructionInstruction(this);
    this.arrayInstruction = new ArrayInstruction(this);
    this.assignInstruction = new AssignInstruction(this);
    this.bitwiseInstruction = new BitwiseInstruction(this);
    this.bitwiseNotInstruction = new BitwiseNotInstruction(this);
    this.booleanInstruction = new BooleanInstruction(this);
    this.breakInstruction = new BreakInstruction(this);
    this.callInstruction = new CallInstruction(this);
    this.chainInstruction = new ChainInstruction(this);
    this.comparisonInstruction = new ComparisonInstruction(this);
    this.continueInstruction = new ContinueInstruction(this);
    this.diiaInstruction = new DiiaInstruction(this);
    this.eachInstruction = new EachInstruction(this);
    this.evalInstruction = new EvalInstruction(this);
    this.functionInstruction = new FunctionInstruction(this);
    this.getElementInstruction = new GetElementInstruction(this);
    this.giveInstruction = new GiveInstruction(this);
    this.identifierInstruction = new IdentifierInstruction(this);
    this.identifiersChainInstruction = new IdentifiersChainInstruction(this);
    this.ifInstruction = new IfInstruction(this);
    this.moduleInstruction = new ModuleInstruction(this);
    this.negativeInstruction = new NegativeInstruction(this);
    this.notInstruction = new NotInstruction(this);
    this.numberInstruction = new NumberInstruction(this);
    this.objectDestructionInstruction = new ObjectDestructionInstruction(this);
    this.dictionaryInstruction = new DictionaryInstruction(this);
    this.positiveInstruction = new PositiveInstruction(this);
    this.postDecrementInstruction = new PostDecrementInstruction(this);
    this.postIncrementInstruction = new PostIncrementInstruction(this);
    this.preDecrementInstruction = new PreDecrementInstruction(this);
    this.preIncrementInstruction = new PreIncrementInstruction(this);
    this.returnInstruction = new ReturnInstruction(this);
    this.stringInstruction = new StringInstruction(this);
    this.structureInstruction = new StructureInstruction(this);
    this.takeFileInstruction = new TakeFileInstruction(this);
    this.takeModuleInstruction = new TakeModuleInstruction(this);
    this.takePakInstruction = new TakePakInstruction(this);
    this.takeRemoteInstruction = new TakeRemoteInstruction(this);
    this.ternaryInstruction = new TernaryInstruction(this);
    this.testInstruction = new TestInstruction(this);
    this.throwInstruction = new ThrowInstruction(this);
    this.tryInstruction = new TryInstruction(this);
    this.typeValueInstruction = new TypeValueInstruction(this);
    this.waitInstruction = new WaitInstruction(this);
    this.whileInstruction = new WhileInstruction(this);

    this.Cell = Cell;

    this.EmptyCell = EmptyCell;
    this.NanCell = NanCell;
    this.InfinityCell = InfinityCell;

    this.AsyncCell = AsyncCell;
    this.AwaitCell = AwaitCell;

    this.StructureCell = StructureCell;
    this.BooleanStructureCell = BooleanStructureCell;
    this.DictionaryStructureCell = DictionaryStructureCell;
    this.DiiaStructureCell = DiiaStructureCell;
    this.ListStructureCell = ListStructureCell;
    this.MockupStructureCell = MockupStructureCell;
    this.ModuleStructureCell = ModuleStructureCell;
    this.NumberStructureCell = NumberStructureCell;
    this.ObjectStructureCell = ObjectStructureCell;
    this.TextStructureCell = TextStructureCell;

    this.PortalCell = PortalCell;
    this.PortalFunctionCell = PortalFunctionCell;
    this.PortalListCell = PortalListCell;
    this.ProxyFunctionCell = ProxyFunctionCell;

    this.Context = Context;
    this.LightContext = LightContext;

    this.Loader = Loader;

    this.ThrowValue = ThrowValue;

    this.booleanStructureCellInstance = this.BooleanStructureCell.createInstance(this);
    this.dictionaryStructureCellInstance = this.DictionaryStructureCell.createInstance(this);
    this.diiaStructureCellInstance = this.DiiaStructureCell.createInstance(this);
    this.listStructureCellInstance = this.ListStructureCell.createInstance(this);
    this.mockupStructureCellInstance = this.MockupStructureCell.createInstance(this);
    this.moduleStructureCellInstance = this.ModuleStructureCell.createInstance(this);
    this.numberStructureCellInstance = this.NumberStructureCell.createInstance(this);
    this.textStructureCellInstance = this.TextStructureCell.createInstance(this);
    this.objectStructureCellInstance = this.ObjectStructureCell.createInstance(this);

    this.empty = new this.EmptyCell(this, null);
    this.undefined = new this.EmptyCell(this, undefined);
    this.nan = new this.NanCell(this, undefined);
    this.infinity = new this.InfinityCell(this, undefined);

    this.yes = new this.Cell(
      this,
      "логічне",
      {},
      this.booleanStructureCellInstance,
      () => true
    );
    this.no = new this.Cell(
      this,
      "логічне",
      {},
      this.booleanStructureCellInstance,
      () => false
    );

    this.loader = options.buildLoader(this);

    this.context = options.buildGlobalContext(this);
    this.context.set("число", this.numberStructureCellInstance);
    this.context.set("текст", this.textStructureCellInstance);
    this.context.set("логічне", this.booleanStructureCellInstance);
    this.context.set("список", this.listStructureCellInstance);
    this.context.set("словник", this.dictionaryStructureCellInstance);
    this.context.set("пусто", this.empty);
    // this.context.set("НеЧ", this.nan);
    // this.context.set("Нескінченність", this.infinity);
    this.context.set("undefined", this.undefined); // js fallback
    this.context.set("обʼєкт", this.objectStructureCellInstance);
    this.context.set("Дія", this.diiaStructureCellInstance);
    this.context.set("global", this.makePortal(this.global));
    this.context.set("діапазон", RangeStructureCell.getInstance(this));
    this.context.set("М", makeMathModule(this));
    this.context.set("Дід", makeDidModule(this));
    this.context.set("is_undefined", this.makeProxyFunction(([value]) => this.toCell(value === this.undefined)));
    this.context.set("отримати_тип", this.makeProxyFunction((args, context, { arg }) => arg(0, "значення")));

    this.external = options.buildExternal ? options.buildExternal(this) : {};

    // @deprecated
    this.tools = {};
    this.tools.asyncFn = (fn) => this.makeWrappedAsyncProxyFunction(fn);

    this.events = mitt();
  }

  /**
   * @param {Node} context
   * @param {ASTNode|ASTNode[]} ast
   * @return {Promise<ReturnSignal|Cell>|ReturnSignal|Cell}
   */
  run(context, ast) {
    if (ast instanceof ProgramNode) {
      ast = ast.body;
    }

    if (!Array.isArray(ast)) {
      ast = ast ? [ast] : [];
    }

    const runSync = () => {
      let result;

      for (const node of ast) {
        result = this.runSync(context, node);

        if (result instanceof ReturnSignal || result instanceof BreakSignal || result instanceof ContinueSignal) {
          return result;
        }
      }

      return result;
    };

    const runAsync = async () => {
      let result;

      for (const node of ast) {
        result = await this.runAsync(context, node);

        if (result instanceof ReturnSignal || result instanceof BreakSignal || result instanceof ContinueSignal) {
          return result;
        }
      }

      return result;
    };

    return context.isAsync ? runAsync() : runSync();
  }

  /**
   * @param {Context} context
   * @param {ASTNode} node
   * @param {Object} options
   * @return {ReturnSignal|Cell}
   */
  runSync(context, node, options = {}) {
    options.forceSync ??= false;

    if (node instanceof AnonymousDiiaNode) {
      return this.anonymousDiiaInstruction.run(context, node, options);
    }

    if (node instanceof ArithmeticNode) {
      return this.arithmeticInstruction.run(context, node, options);
    }

    if (node instanceof ArrayDestructionNode) {
      return this.arrayDestructionInstruction.run(context, node, options);
    }

    if (node instanceof ArrayNode) {
      return this.arrayInstruction.run(context, node, options);
    }

    if (node instanceof AssignNode) {
      return this.assignInstruction.run(context, node, options);
    }

    if (node instanceof BitwiseNode) {
      return this.bitwiseInstruction.run(context, node, options);
    }

    if (node instanceof BitwiseNotNode) {
      return this.bitwiseNotInstruction.run(context, node, options);
    }

    if (node instanceof BooleanNode) {
      return this.booleanInstruction.run(context, node, options);
    }

    if (node instanceof BreakNode) {
      return this.breakInstruction.run(context, node, options);
    }

    if (node instanceof CallNode) {
      return this.callInstruction.run(context, node, options);
    }

    if (node instanceof ChainNode) {
      return this.chainInstruction.run(context, node, options);
    }

    if (node instanceof ComparisonNode) {
      return this.comparisonInstruction.run(context, node, options);
    }

    if (node instanceof ContinueNode) {
      return this.continueInstruction.run(context, node, options);
    }

    if (node instanceof DiiaNode) {
      return this.diiaInstruction.run(context, node, options);
    }

    if (node instanceof EachNode) {
      return this.eachInstruction.run(context, node, options);
    }

    if (node instanceof EvalNode) {
      return this.evalInstruction.run(context, node, options);
    }

    if (node instanceof FunctionNode) {
      return this.functionInstruction.run(context, node, options);
    }

    if (node instanceof GetElementNode) {
      return this.getElementInstruction.run(context, node, options);
    }

    if (node instanceof GiveNode) {
      return this.giveInstruction.run(context, node, options);
    }

    if (node instanceof IdentifierNode) {
      return this.identifierInstruction.run(context, node, options);
    }

    if (node instanceof IdentifiersChainNode) {
      return this.identifiersChainInstruction.run(context, node, options);
    }

    if (node instanceof IfNode) {
      return this.ifInstruction.run(context, node, options);
    }

    if (node instanceof ModuleNode) {
      return this.moduleInstruction.run(context, node, options);
    }

    if (node instanceof NegativeNode) {
      return this.negativeInstruction.run(context, node, options);
    }

    if (node instanceof NotNode) {
      return this.notInstruction.run(context, node, options);
    }

    if (node instanceof NumberNode) {
      return this.numberInstruction.run(context, node, options);
    }

    if (node instanceof ObjectDestructionNode) {
      return this.objectDestructionInstruction.run(context, node, options);
    }

    if (node instanceof DictionaryNode) {
      return this.dictionaryInstruction.run(context, node, options);
    }

    if (node instanceof PositiveNode) {
      return this.positiveInstruction.run(context, node, options);
    }

    if (node instanceof PostDecrementNode) {
      return this.postDecrementInstruction.run(context, node, options);
    }

    if (node instanceof PostIncrementNode) {
      return this.postIncrementInstruction.run(context, node, options);
    }

    if (node instanceof PreDecrementNode) {
      return this.preDecrementInstruction.run(context, node, options);
    }

    if (node instanceof PreIncrementNode) {
      return this.preIncrementInstruction.run(context, node, options);
    }

    if (node instanceof ReturnNode) {
      return this.returnInstruction.run(context, node, options);
    }

    if (node instanceof StringNode) {
      return this.stringInstruction.run(context, node, options);
    }

    if (node instanceof StructureNode) {
      return this.structureInstruction.run(context, node, options);
    }

    if (node instanceof TakeFileNode) {
      return this.takeFileInstruction.run(context, node, options);
    }

    if (node instanceof TakeModuleNode) {
      return this.takeModuleInstruction.run(context, node, options);
    }

    if (node instanceof TakePakNode) {
      return this.takePakInstruction.run(context, node, options);
    }

    if (node instanceof TakeRemoteNode) {
      return this.takeRemoteInstruction.run(context, node, options);
    }

    if (node instanceof TernaryNode) {
      return this.ternaryInstruction.run(context, node, options);
    }

    if (node instanceof TestNode) {
      return this.testInstruction.run(context, node, options);
    }

    if (node instanceof ThrowNode) {
      return this.throwInstruction.run(context, node, options);
    }

    if (node instanceof TryNode) {
      return this.tryInstruction.run(context, node, options);
    }

    if (node instanceof TypeValueNode) {
      return this.typeValueInstruction.run(context, node, options);
    }

    if (node instanceof WaitNode) {
      return this.waitInstruction.run(context, node, options);
    }

    if (node instanceof WhileNode) {
      return this.whileInstruction.run(context, node, options);
    }

    if (node instanceof ProgramNode) {
      return this.run(context, node.body);
    }
  }

  /**
   * @param {Context} context
   * @param {ASTNode} node
   * @param {Object} options
   * @return {Promise<Cell>}
   */
  async runAsync(context, node, options = {}) {
    let value = await this.runSync(context, node, options);

    if (value instanceof this.AwaitCell) {
      value = await value.meta.cellToAwait;

      if (value instanceof this.AsyncCell) {
        value = value.meta.asyncOperation;

        // handle async functions
        if (!(value instanceof Promise)) {
          value = value();
        }

        value = await value;
      }
    }

    return value;
  }

  /**
   * @param {string} code
   * @param {Context|undefined|null} context
   * @return {Promise<ReturnSignal|*>|ReturnSignal|*}
   */
  eval(code, context = null) {
    const ast = parse(code);

    return this.run(context || this.context, ast);
  }

  /**
   * @param {Cell} value
   * @return {boolean}
   */
  isText(value) {
    return value.isInstanceOf(this.textStructureCellInstance);
  }

  /**
   * @param {Cell} value
   * @return {boolean}
   */
  isNumber(value) {
    return value.isInstanceOf(this.numberStructureCellInstance);
  }

  /**
   * @param {Cell} value
   * @return {boolean}
   */
  isBasic(value) {
    return this.isEmpty(value)
      || this.isText(value)
      || this.isNumber(value)
      || this.isBoolean(value);
  }

  /**
   * @param {Cell} value
   * @return {boolean}
   */
  isBoolean(value) {
    return value.isInstanceOf(this.booleanStructureCellInstance);
  }

  /**
   * @param {Cell} value
   * @return {boolean}
   */
  isList(value) {
    return value.isInstanceOf(this.listStructureCellInstance);
  }

  /**
   * @param {Cell} value
   * @return {boolean}
   */
  isDictionary(value) {
    return value.isInstanceOf(this.dictionaryStructureCellInstance);
  }

  /**
   * @param {Cell} value
   * @return {boolean}
   */
  isObject(value) {
    return value.isInstanceOf(this.objectStructureCellInstance);
  }

  /**
   * @param {Cell} value
   * @return {boolean}
   */
  isDiia(value) {
    return value.isInstanceOf(this.diiaStructureCellInstance);
  }

  /**
   * @param {Cell} value
   * @return {boolean}
   */
  isEmpty(value) {
    return value === this.empty || value === this.undefined;
  }

  /**
   * @param {Cell} value
   * @return {boolean}
   */
  isUndefined(value) {
    return value === this.undefined;
  }

  toCell(value) {
    if (value == null) {
      return this.empty;
    }

    if (value instanceof this.Cell) {
      return value;
    }

    if (typeof value === "string") {
      return this.makeText(value);
    }

    if (typeof value === "number") {
      return this.makeNumber(value);
    }

    if (typeof value === "boolean") {
      return value ? this.yes : this.no;
    }

    if (Array.isArray(value)) {
      return this.makePortalList(value);
    }

    if (typeof value === "object") {
      return this.makePortal(value);
    }

    if (typeof value === "function") {
      return this.makePortalFunction(value);
    }

    return this.empty;
  }

  /**
   * @param {Context} context
   * @param {Cell} value
   */
  fall(context, value) {
    throw new this.ThrowValue(context, value);
  }

  /**
   * @param {function} fn
   * @return {ProxyFunctionCell}
   */
  makeProxyFunction(fn) {
    return new this.ProxyFunctionCell(this, fn);
  }

  /**
   * @param {function} fn
   * @return {ProxyFunctionCell}
   */
  makeAsyncProxyFunction(fn) {
    return new this.ProxyFunctionCell(this, fn, true);
  }

  /**
   * @param {function} fn
   * @return {ProxyFunctionCell}
   */
  makeWrappedProxyFunction(fn) {
    return new this.ProxyFunctionCell(this, fn, false, true);
  }

  /**
   * @param {function} fn
   * @return {ProxyFunctionCell}
   */
  makeWrappedAsyncProxyFunction(fn) {
    return new this.ProxyFunctionCell(this, fn, true, true);
  }

  /**
   * @param {string} value
   * @return {Cell}
   */
  makeText(value) {
    value = String(value);

    return new this.Cell(
      this,
      "текст",
      {
        value
      },
      this.textStructureCellInstance,
      () => value,
      null,
      {
        value
      }
    );
  }

  /**
   * @param {number} value
   * @return {Cell}
   */
  makeNumber(value) {
    value = Number(value);

    return new this.Cell(
      this,
      "число",
      {},
      this.numberStructureCellInstance,
      () => value
    );
  }

  /**
   * @param {Cell[]} values
   * @return {Cell}
   */
  makeList(values) {
    return new this.Cell(
      this,
      "список",
      {},
      this.listStructureCellInstance,
      (context) => {
        return values
          .map((v) => v.asJsValue(context));
      },
      function* () {
        for (const [key, value] of Object.entries(values)) {
          yield { key, value };
        }
      },
      {
        values
      }
    );
  }

  /**
   * @param {Map<string|number|boolean|Cell, Cell>} items
   * @return {Cell}
   */
  makeDictionary(items) {
    const mavka = this;

    return new this.Cell(
      this,
      "словник",
      {},
      this.dictionaryStructureCellInstance,
      (context) => {
        const data = {};

        for (const [k, v] of items.entries()) {
          data[this.toCell(k).asJsValue(context)] = v.asJsValue(context);
        }

        return data;
      },
      function* () {
        for (const [key, value] of items.entries()) {
          yield { key: mavka.toCell(key), value };
        }
      },
      {
        items
      }
    );
  }

  /**
   * @param {string} name
   * @param {MockupMethod[]} methods
   * @return {Cell}
   */
  makeMockup(name, methods) {
    return new this.Cell(
      this,
      "макет",
      {},
      this.mockupStructureCellInstance,
      () => null,
      null,
      {
        name,
        methods
      }
    );
  }

  /**
   * @param {string|null} name
   * @param {{ name: string, defaultValue: Cell|undefined, spread: boolean }[]} parameters
   * @param {Class<Context>} contextClass
   * @param {Context|null} outerContext
   * @param {boolean} isAsync
   * @param {ASTNode[]|function} body
   * @param {StructureCell} diiaStructure
   * @param {Cell|null|undefined} meValue
   * @return {Cell}
   */
  makeDiia(name,
           parameters = [],
           contextClass,
           outerContext,
           isAsync,
           body,
           diiaStructure,
           meValue = null) {
    const cell = new this.Cell(
      this,
      "дія",
      {
        "виконати_виклик": this.makeProxyFunction(
          (args, context, options) => {
            const diiaContext = new contextClass(this, outerContext);

            if (meValue) {
              diiaContext.set("я", meValue);
            }

            if (isAsync) {
              diiaContext.setAsync(true);
            }

            if (parameters) {
              fillParameters(
                this,
                context,
                diiaContext,
                parameters,
                args
              );
            }

            let result;

            if (typeof body === "function") {
              result = body(args, context, { ...options, meValue });
            } else {
              result = this.run(diiaContext, body);
            }

            if (isAsync) {
              return new this.AsyncCell(this, async () => {
                result = await result;

                if (result instanceof ReturnSignal) {
                  result = result.value;
                }

                return result;
              });
            }

            if (result instanceof ReturnSignal) {
              result = result.value;
            }

            return result;
          }
        )
      },
      diiaStructure,
      (context) => (...args) => cell.doCall(context, args),
      null,
      {
        isAsync,
        name
      }
    );

    return cell;
  }

  /**
   * @param {string} name
   * @param {Record<string, Cell>} properties
   * @return {Cell}
   */
  makeModule(name, properties = {}) {
    return new this.Cell(
      this,
      "модуль",
      properties,
      this.moduleStructureCellInstance,
      () => properties,
      null,
      { name }
    );
  }

  /**
   * @param {Object} object
   * @return {PortalCell}
   */
  makePortal(object) {
    return new this.PortalCell(this, object);
  }

  /**
   * @param {function} fn
   * @return {PortalFunctionCell}
   */
  makePortalFunction(fn) {
    return new this.PortalFunctionCell(this, fn);
  }

  /**
   * @param {Array} values
   * @return {PortalListCell}
   */
  makePortalList(values) {
    return new this.PortalListCell(this, values);
  }

  /**
   * @param {string} name
   * @param {function|ASTNode[]} body
   * @return {Method}
   */
  makeMethod(name, body) {
    return new Method(
      name,
      null,
      body,
      false,
      null
    );
  }

  /**
   * @param {Context} context
   * @param {string} code
   * @return {Promise<void>}
   */
  async import(context, code) {
    extId++;

    const wrappedCode = `
getMavka().global.EXTENSION_EVAL_ASYNC_${extId} = async function() {
  ${code}
}
      `;

    const prevGetMavka = this.global.getMavka;
    const prevGetContext = this.global.getContext;

    this.global.getMavka = () => this;
    this.global.getContext = () => context;

    eval(wrappedCode);

    await this.global[`EXTENSION_EVAL_ASYNC_${extId}`]();
    delete this.global[`EXTENSION_EVAL_ASYNC_${extId}`];

    this.global.getMavka = prevGetMavka;
    this.global.getContext = prevGetContext;
  }
}

export default Mavka;

