import { Cell } from "./interpreter/cells/cell.js";
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
import BooleanCell from "./interpreter/cells/booleanCell.js";
import NumberCell from "./interpreter/cells/numberCell.js";
import StringCell from "./interpreter/cells/stringCell.js";
import EmptyCell from "./interpreter/cells/emptyCell.js";
import DiiaCell from "./interpreter/cells/diiaCell.js";
import FunctionCell from "./interpreter/cells/functionCell.js";
import AsyncCell from "./interpreter/cells/asyncCell.js";
import WaitCell from "./interpreter/cells/waitCell.js";
import StructureCell, { StructureConstructorCell } from "./interpreter/cells/structureCell.js";
import ModuleCell from "./interpreter/cells/moduleCell.js";
import { JsFunctionCell, RangeCell, RangeDiiaCell } from "./interpreter/cells/stdCells.js";
import { parse } from "mavka-parser";
import BooleanInstruction from "./interpreter/instructions/booleanInstruction.js";
import LightContext from "./interpreter/contexts/lightContext.js";
import Context from "./interpreter/contexts/context.js";
import AnonymousDiiaCell from "./interpreter/cells/anonymousDiiaCell.js";
import AnonymousDiiaInstruction from "./interpreter/instructions/anonymousDiiaInstruction.js";
import AnonymousDiiaNode from "mavka-parser/src/ast/AnonymousDiiaNode.js";
import TryInstruction from "./interpreter/instructions/tryInstruction.js";
import ThrowInstruction from "./interpreter/instructions/throwInstruction.js";
import ThrowNode from "mavka-parser/src/ast/ThrowNode.js";
import TryNode from "mavka-parser/src/ast/TryNode.js";
import WhileNode from "mavka-parser/src/ast/WhileNode.js";
import WhileInstruction from "./interpreter/instructions/whileInstruction.js";
import ListCell from "./interpreter/cells/listCell.js";
import { makeAsyncFn, makeFn } from "./interpreter/cells/utils.js";
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

/**
 * @property {Context} context
 * @property {Loader} loader
 */
class Mavka {
  constructor(options = {}) {
    this.arithmeticInstruction = new ArithmeticInstruction(this);
    this.assignInstruction = new AssignInstruction(this);
    this.chainInstruction = new ChainInstruction(this);
    this.mavkaInstruction = new DiiaInstruction(this);
    this.anonymousDiiaInstruction = new AnonymousDiiaInstruction(this);
    this.eachInstruction = new EachInstruction(this);
    this.whileInstruction = new WhileInstruction(this);
    this.ifInstruction = new IfInstruction(this);
    this.functionInstruction = new FunctionInstruction(this);
    this.numberInstruction = new NumberInstruction(this);
    this.booleanInstruction = new BooleanInstruction(this);
    this.callInstruction = new CallInstruction(this);
    this.returnInstruction = new ReturnInstruction(this);
    this.stringInstruction = new StringInstruction(this);
    this.structureInstruction = new StructureInstruction(this);
    this.comparisonInstruction = new ComparisonInstruction(this);
    this.testInstruction = new TestInstruction(this);
    this.waitInstruction = new WaitInstruction(this);
    this.giveInstruction = new GiveInstruction(this);
    this.identifierInstruction = new IdentifierInstruction(this);
    this.identifiersChainInstruction = new IdentifiersChainInstruction(this);
    this.takeInstruction = new TakeInstruction(this);
    this.ternaryInstruction = new TernaryInstruction(this);
    this.tryInstruction = new TryInstruction(this);
    this.throwInstruction = new ThrowInstruction(this);
    this.moduleInstruction = new ModuleInstruction(this);

    this.Cell = Cell;
    this.NumberCell = NumberCell;
    this.StringCell = StringCell;
    this.BooleanCell = BooleanCell;
    this.EmptyCell = EmptyCell;
    this.diiaCell = DiiaCell;
    this.AnonymousDiiaCell = AnonymousDiiaCell;
    this.FunctionCell = FunctionCell;
    this.StructureCell = StructureCell;
    this.ListCell = ListCell;
    this.StructureConstructorCell = StructureConstructorCell;
    this.ModuleCell = ModuleCell;
    this.AsyncCell = AsyncCell;
    this.WaitCell = WaitCell;

    this.RangeCell = RangeCell;
    this.RangeDiiaCell = RangeDiiaCell;
    this.JsFunctionCell = JsFunctionCell;

    this.Context = Context;
    this.LambdaContext = LightContext;

    this.emptyCellInstance = new this.EmptyCell(this);
    this.trueCellInstance = new this.BooleanCell(this, true);
    this.falseCellInstance = new this.BooleanCell(this, false);

    this.tools = {};
    this.tools.fn = (context, fn) => makeFn(this, context, fn);
    this.tools.asyncFn = (context, fn) => makeAsyncFn(this, context, fn);

    this.context = options.buildGlobalContext(this);
    this.context.set("пусто", this.emptyCellInstance);
    this.loader = options.buildLoader(this);
    this.external = options.buildExternal ? options.buildExternal(this) : {};

    const code = `
дія з'єднати_рядки(рядки)
  результат = ""

  перебрати рядки як рядок
    якщо результат == ""
      результат = рядок
    інакше
      результат = результат + "\\n" + рядок
    кінець
  кінець

  вернути результат
кінець
    `;

    this.eval(code);
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
      return new this.StringCell(this, value);
    }

    if (typeof value === "number") {
      return new this.NumberCell(this, value);
    }

    if (typeof value === "boolean") {
      return value ? this.trueCellInstance : this.falseCellInstance;
    }

    if (Array.isArray(value)) {
      return new this.ListCell(this, value.map((v) => this.toCell(v)));
    }

    if (typeof value === "object") {
      const structureCell = new this.StructureCell(this, "Об'єкт");
      Object.entries(value).forEach(([k, v]) => {
        structureCell.set(k, this.toCell(v));
      });
      return structureCell;
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

    return context.isAsync() ? runAsync() : runSync();
  }

  runSync(context, node) {
    if (node instanceof AnonymousDiiaNode) {
      return this.anonymousDiiaInstruction.run(context, node);
    }

    if (node instanceof ArithmeticNode) {
      return this.arithmeticInstruction.run(context, node);
    }

    if (node instanceof AssignNode) {
      return this.assignInstruction.run(context, node);
    }

    if (node instanceof BooleanNode) {
      return this.booleanInstruction.run(context, node);
    }

    if (node instanceof CallNode) {
      return this.callInstruction.run(context, node);
    }

    if (node instanceof ChainNode) {
      return this.chainInstruction.run(context, node);
    }

    if (node instanceof ComparisonNode) {
      return this.comparisonInstruction.run(context, node);
    }

    if (node instanceof DiiaNode) {
      return this.mavkaInstruction.run(context, node);
    }

    if (node instanceof EachNode) {
      return this.eachInstruction.run(context, node);
    }

    if (node instanceof FunctionNode) {
      return this.functionInstruction.run(context, node);
    }

    if (node instanceof GiveNode) {
      return this.giveInstruction.run(context, node);
    }

    if (node instanceof IdentifierNode) {
      return this.identifierInstruction.run(context, node);
    }

    if (node instanceof IdentifiersChainInstruction) {
      return this.identifiersChainInstruction.run(context, node);
    }

    if (node instanceof IfNode) {
      return this.ifInstruction.run(context, node);
    }

    if (node instanceof ModuleNode) {
      return this.moduleInstruction.run(context, node);
    }

    if (node instanceof NumberNode) {
      return this.numberInstruction.run(context, node);
    }

    // todo: param node

    if (node instanceof ProgramNode) {
      return this.run(context, node.body);
    }

    if (node instanceof ReturnNode) {
      return this.returnInstruction.run(context, node);
    }

    if (node instanceof StringNode) {
      return this.stringInstruction.run(context, node);
    }

    if (node instanceof StructureNode) {
      return this.structureInstruction.run(context, node);
    }

    if (node instanceof TakeNode) {
      return this.takeInstruction.run(context, node);
    }


    if (node instanceof TernaryNode) {
      return this.ternaryInstruction.run(context, node);
    }

    if (node instanceof TestNode) {
      return this.testInstruction.run(context, node);
    }

    if (node instanceof ThrowNode) {
      return this.throwInstruction.run(context, node);
    }

    if (node instanceof TryNode) {
      return this.tryInstruction.run(context, node);
    }

    if (node instanceof WaitNode) {
      return this.waitInstruction.run(context, node);
    }

    if (node instanceof WhileNode) {
      return this.whileInstruction.run(context, node);
    }
  }

  async runAsync(context, node) {
    let value = await this.runSync(context, node);

    if (value instanceof this.WaitCell) {
      value = await value.getValue();

      if (value instanceof this.AsyncCell) {
        value = value.getPromise();

        // handle AsyncFunction
        if (!(value instanceof Promise)) {
          value = value();
        }

        value = await value;
      }
    }

    return value;
  }

  eval(code, context = null) {
    const ast = parse(code);

    return this.run(context || this.context, ast);
  }
}

export default Mavka;

