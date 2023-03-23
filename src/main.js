import { Cell } from "./interpreter/cells/common/cell.js";
import AssignInstruction from "./interpreter/instructions/assignInstruction.js";
import ChainInstruction from "./interpreter/instructions/chainInstruction.js";
import DiiaInstruction from "./interpreter/instructions/diiaInstruction.js";
import EachInstruction from "./interpreter/instructions/eachInstruction.js";
import ArithmeticInstruction from "./interpreter/instructions/arithmeticInstruction.js";
import IfInstruction from "./interpreter/instructions/ifInstruction.js";
import FunctionInstruction from "./interpreter/instructions/functionInstruction.js";
import NumberInstruction from "./interpreter/instructions/numberInstruction.js";
import ReturnInstruction, { ReturnValue } from "./interpreter/instructions/returnInstruction.js";
import StringInstruction from "./interpreter/instructions/stringInstruction.js";
import StructureInstruction from "./interpreter/instructions/structureInstruction.js";
import ComparisonInstruction from "./interpreter/instructions/comparisonInstruction.js";
import WaitInstruction from "./interpreter/instructions/waitInstruction.js";
import GiveInstruction from "./interpreter/instructions/giveInstruction.js";
import TakeInstruction from "./interpreter/instructions/takeInstruction.js";
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
import TakeNode from "mavka-parser/src/ast/TakeNode.js";
import GiveNode from "mavka-parser/src/ast/GiveNode.js";
import AsyncCell from "./interpreter/cells/async/asyncCell.js";
import WaitCell from "./interpreter/cells/async/waitCell.js";
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
import { fillParameters, makeAsyncFn, makeFn } from "./std/tools.js";
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
import FileLoader from "./loaders/fileLoader.js";
import MemoryLoader from "./loaders/memoryLoader.js";
import NegativeInstruction from "./interpreter/instructions/negativeInstruction.js";
import NegativeNode from "mavka-parser/src/ast/NegativeNode.js";
import ArrayInstruction from "./interpreter/instructions/arrayInstruction.js";
import ArrayNode from "mavka-parser/src/ast/ArrayNode.js";
import DictionaryInstruction from "./interpreter/instructions/dictionaryInstruction.js";
import ArrayDestructionInstruction from "./interpreter/instructions/arrayDestructionInstruction.js";
import BreakInstruction from "./interpreter/instructions/breakInstruction.js";
import ContinueInstruction from "./interpreter/instructions/continueInstruction.js";
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
import AnonymousDiiaStructureCell from "./interpreter/cells/anonymousDiiaStructureCell.js";
import FunctionStructureCell from "./interpreter/cells/functionStructureCell.js";
import ProxyFunctionCell from "./interpreter/cells/portal/proxyFunctionCell.js";
import EmptyCell from "./interpreter/cells/common/emptyCell.js";

/**
 * @property {Context} context
 * @property {Loader} loader
 */
class Mavka {
  static VERSION = "0.9.31";

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
    this.booleanInstruction = new BooleanInstruction(this);
    this.breakInstruction = new BreakInstruction(this);
    this.callInstruction = new CallInstruction(this);
    this.chainInstruction = new ChainInstruction(this);
    this.comparisonInstruction = new ComparisonInstruction(this);
    this.continueInstruction = new ContinueInstruction(this);
    this.diiaInstruction = new DiiaInstruction(this);
    this.eachInstruction = new EachInstruction(this);
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
    this.takeInstruction = new TakeInstruction(this);
    this.ternaryInstruction = new TernaryInstruction(this);
    this.testInstruction = new TestInstruction(this);
    this.throwInstruction = new ThrowInstruction(this);
    this.tryInstruction = new TryInstruction(this);
    this.typeValueInstruction = new TypeValueInstruction(this);
    this.waitInstruction = new WaitInstruction(this);
    this.whileInstruction = new WhileInstruction(this);

    this.Cell = Cell;

    this.EmptyCell = EmptyCell;

    this.AsyncCell = AsyncCell;
    this.WaitCell = WaitCell;

    this.AnonymousDiiaStructureCell = AnonymousDiiaStructureCell;
    this.BooleanStructureCell = BooleanStructureCell;
    this.DictionaryStructureCell = DictionaryStructureCell;
    this.DiiaStructureCell = DiiaStructureCell;
    this.FunctionStructureCell = FunctionStructureCell;
    this.ListStructureCell = ListStructureCell;
    this.NumberStructureCell = NumberStructureCell;
    this.ObjectStructureCell = ObjectStructureCell;
    this.TextStructureCell = TextStructureCell;

    this.PortalCell = PortalCell;
    this.PortalFunctionCell = PortalFunctionCell;
    this.ProxyFunctionCell = ProxyFunctionCell;

    this.Context = Context;
    this.LightContext = LightContext;

    this.Loader = Loader;
    this.FileLoader = FileLoader;
    this.MemoryLoader = MemoryLoader;

    this.ThrowValue = ThrowValue;

    this.tools = {};
    this.tools.fn = (fn, options = {}) => makeFn(this, fn, options);
    this.tools.asyncFn = (fn, options = {}) => makeAsyncFn(this, fn, options);

    this.booleanStructureCellInstance = new this.BooleanStructureCell(this);
    this.dictionaryStructureCellInstance = new this.DictionaryStructureCell(this);
    this.diiaStructureCellInstance = new this.DiiaStructureCell(this);
    this.anonymousDiiaStructureCellInstance = new this.AnonymousDiiaStructureCell(this);
    this.functionStructureCellInstance = new this.FunctionStructureCell(this);
    this.listStructureCellInstance = new this.ListStructureCell(this);
    this.numberStructureCellInstance = new this.NumberStructureCell(this);
    this.textStructureCellInstance = new this.TextStructureCell(this);
    this.objectStructureCellInstance = new this.ObjectStructureCell(this, "обʼєкт", {}, null, [], {
      "виконати_перетворення_на_текст": this.tools.fn(
        (args, callContext, options) => {
          const properties = options.meValue.structure.getAllParameters()
            .map((p) => [p.name, options.meValue.get(callContext, p.name)])
            .map(([k, v]) => `${k}=${v.asText(callContext).asJsValue(callContext)}`)
            .join(", ");

          return this.toCell(`${options.meValue.name}(${properties})`);
        },
        { jsArgs: false }
      ),
      "виконати_перетворення_на_число": this.tools.fn(
        (args, callContext, options) => {
          return options.meValue.asText(callContext).asNumber(callContext);
        },
        { jsArgs: false }
      ),
      "виконати_перетворення_на_логічне": this.tools.fn(
        () => {
          return this.yesCellInstance;
        },
        { jsArgs: false }
      )
    });

    this.emptyCellInstance = new this.EmptyCell(this);

    this.yesCellInstance = new this.Cell(
      this,
      "логічне",
      {},
      this.booleanStructureCellInstance,
      () => true
    );
    this.noCellInstance = new this.Cell(
      this,
      "логічне",
      {},
      this.booleanStructureCellInstance,
      () => false
    );

    this.loader = options.buildLoader(this);

    this.context = options.buildGlobalContext(this);
    this.context.set("пусто", this.emptyCellInstance);
    this.context.set("обʼєкт", this.objectStructureCellInstance);
    this.context.set("список", this.listStructureCellInstance);
    this.context.set("словник", this.dictionaryStructureCellInstance);
    this.context.set("число", this.numberStructureCellInstance);
    this.context.set("текст", this.textStructureCellInstance);
    this.context.set("логічне", this.booleanStructureCellInstance);
    this.context.set("global", this.makePortal(this.global));

    this.external = options.buildExternal ? options.buildExternal(this) : {};
  }

  isEmpty(value) {
    return this.toCell(value) === this.emptyCellInstance;
  }

  toCell(value) {
    if (value == null) {
      return this.emptyCellInstance;
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
      return value ? this.yesCellInstance : this.noCellInstance;
    }

    if (Array.isArray(value)) {
      // todo: mb better make portal list now new list
      return this.makeList(value.map((v) => this.toCell(v)));
    }

    if (typeof value === "object") {
      return this.makePortal(value);
    }

    if (typeof value === "function") {
      return this.makePortalFunction(value);
    }

    return this.emptyCellInstance;
  }

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

        if (result instanceof ReturnValue) {
          return result;
        }
      }

      return result;
    };

    const runAsync = async () => {
      let result;

      for (const node of ast) {
        result = await this.runAsync(context, node);

        if (result instanceof ReturnValue) {
          return result;
        }
      }

      return result;
    };

    return context.isAsync ? runAsync() : runSync();
  }

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

    if (node instanceof ContinueInstruction) {
      return this.continueInstruction.run(context, node, options);
    }

    if (node instanceof DiiaNode) {
      return this.diiaInstruction.run(context, node, options);
    }

    if (node instanceof EachNode) {
      return this.eachInstruction.run(context, node, options);
    }

    if (node instanceof FunctionNode) {
      return this.functionInstruction.run(context, node, options);
    }

    if (node instanceof GetElementInstruction) {
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

    if (node instanceof PreIncrementInstruction) {
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

    if (node instanceof TakeNode) {
      return this.takeInstruction.run(context, node, options);
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

  async runAsync(context, node, options = {}) {
    let value = await this.runSync(context, node, options);

    if (value instanceof this.WaitCell) {
      value = await value.value;

      if (value instanceof this.AsyncCell) {
        value = value.promise;

        // handle AsyncFunction
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
   * @return {Promise<ReturnValue|*>|ReturnValue|*}
   */
  eval(code, context = null) {
    const ast = parse(code);

    return this.run(context || this.context, ast);
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
      {},
      this.textStructureCellInstance,
      () => value
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
   * @param {Record<string, Cell>} items
   * @return {Cell}
   */
  makeDictionary(items) {
    return new this.Cell(
      this,
      "словник",
      {},
      this.dictionaryStructureCellInstance,
      (context) => {
        const data = {};

        for (const [k, v] of Object.entries(items)) {
          data[this.toCell(k).asJsValue(context)] = v.asJsValue(context);
        }

        return data;
      },
      function* () {
        for (const [key, value] of Object.entries(items)) {
          yield { key, value };
        }
      }
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
      }
    );
  }

  /**
   * @param {string} name
   * @param {{ name: string, defaultValue: Cell|undefined }[]} parameters
   * @param {Class<Context>} contextClass
   * @param {Context} outerContext
   * @param {boolean} isAsync
   * @param {ASTNode[]} body
   * @param {StructureCell} structure
   * @return {Cell}
   */
  makeDiia(name,
           parameters = {},
           contextClass,
           outerContext,
           isAsync,
           body,
           structure) {
    return new this.Cell(
      this,
      name,
      {
        "виконати_виклик": this.tools.fn(
          (args, context, options) => {
            const diiaContext = new contextClass(this, outerContext);

            if (!this.isEmpty(options.meValue)) {
              diiaContext.set("я", options.meValue);
            }

            if (isAsync) {
              diiaContext.setAsync(true);
            }

            fillParameters(
              this,
              context,
              diiaContext,
              parameters,
              args
            );

            let result = this.run(diiaContext, body);

            if (result instanceof ReturnValue) {
              result = result.value;
            }

            return result;
          },
          { jsArgs: false }
        )
      },
      structure,
      () => null
    );
  }

  makeModule(name, context) {
    return new this.Cell(this, `<модуль ${name}>`, {
      "виконати_отримання": this.tools.fn(
        (args, callContext) => {
          return context.get(args[0].asText(callContext).asJsValue(callContext));
        },
        { jsArgs: false }
      )
    });
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
   * @param {function} fn
   * @return {ProxyFunctionCell}
   */
  makeProxyFunction(fn) {
    return new this.ProxyFunctionCell(this, fn);
  }
}

export default Mavka;

