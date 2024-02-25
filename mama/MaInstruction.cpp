#include "mama.h"

namespace mavka::mama {
  std::string getopname(const MaV v) {
    switch (v) {
      case VConstant:
        return "VConstant";
      case VAdd:
        return "VAdd";
      case VSub:
        return "VSub";
      case VMul:
        return "VMul";
      case VDiv:
        return "VDiv";
      case VMod:
        return "VMod";
      case VDivDiv:
        return "VDivDiv";
      case VPow:
        return "VPow";
      case VStore:
        return "VStore";
      case VLoad:
        return "VLoad";
      case VGet:
        return "VGet";
      case VSet:
        return "VSet";
      case VXor:
        return "VXor";
      case VBor:
        return "VBor";
      case VBand:
        return "VBand";
      case VShl:
        return "VShl";
      case VShr:
        return "VShr";
      case VBnot:
        return "VBnot";
      case VJumpIfFalse:
        return "VJumpIfFalse";
      case VJumpIfTrue:
        return "VJumpIfTrue";
      case VEJumpIfFalse:
        return "VEJumpIfFalse";
      case VEJumpIfTrue:
        return "VEJumpIfTrue";
      case VJump:
        return "VJump";
      case VThrow:
        return "VThrow";
      case VEq:
        return "VEq";
      case VLt:
        return "VLt";
      case VLe:
        return "VLe";
      case VContains:
        return "VContains";
      case VGt:
        return "VGt";
      case VGe:
        return "VGe";
      case VCall:
        return "VCall";
      case VReturn:
        return "VReturn";
      case VPop:
        return "VPop";
      case VList:
        return "VList";
      case VListAppend:
        return "VListAppend";
      case VNegative:
        return "VNegative";
      case VPositive:
        return "VPositive";
      case VDiia:
        return "VDiia";
      case VDict:
        return "VDict";
      case VDictSet:
        return "VDictSet";
      case VStruct:
        return "VStruct";
      case VGive:
        return "VGive";
      case VModule:
        return "VModule";
      case VTry:
        return "VTry";
      case VTryDone:
        return "VTryDone";
      case VNot:
        return "VNot";
      case VInitargs:
        return "VInitargs";
      case VDiiaParam:
        return "VDiiaParam";
      case VStructParam:
        return "VStructParam";
      case VStructMethod:
        return "VStructMethod";
      case VModuleDone:
        return "VModuleDone";
      case VStoreArg:
        return "VStoreArg";
      case VNumber:
        return "VNumber";
      case VEmpty:
        return "VEmpty";
      case VYes:
        return "VYes";
      case VNo:
        return "VNo";
      case VKeepModule:
        return "VKeepModule";
      case VIs:
        return "VIs";
      case VTake:
        return "VTake";
      case VLoadModule:
        return "VLoadModule";
      case VModuleLoad:
        return "VModuleLoad";
      case VPushArg:
        return "VPushArg";
      default:
        break;
    }
    return std::to_string(v);
  }
  MaInstruction MaInstruction::pop() {
    return MaInstruction{VPop};
  }
  MaInstruction MaInstruction::constant(size_t index) {
    return MaInstruction{VConstant, {.constant = index}};
  }
  MaInstruction MaInstruction::number(double value) {
    return MaInstruction{VNumber, {.number = value}};
  }
  MaInstruction MaInstruction::empty() {
    return MaInstruction{VEmpty};
  }
  MaInstruction MaInstruction::yes() {
    return MaInstruction{VYes};
  }
  MaInstruction MaInstruction::no() {
    return MaInstruction{VNo};
  }
  MaInstruction MaInstruction::initargs(MaInitArgsInstructionArgs* args) {
    return MaInstruction{VInitargs, {.initargs = args}};
  }
  MaInstruction MaInstruction::pusharg() {
    return MaInstruction{VPushArg};
  }
  MaInstruction MaInstruction::storearg(MaStoreArgInstructionArgs* args) {
    return MaInstruction{VStoreArg, {.storearg = args}};
  }
  MaInstruction MaInstruction::call(MaInstructionLocation* location) {
    return MaInstruction{VCall, {}, location};
  }
  MaInstruction MaInstruction::return_() {
    return MaInstruction{VReturn};
  }
  MaInstruction MaInstruction::diia(MaDiiaInstructionArgs* args) {
    return MaInstruction{VDiia, {.diia = args}};
  }
  MaInstruction MaInstruction::diiaparam(MaDiiaParamInstructionArgs* args) {
    return MaInstruction{VDiiaParam, {.diiaparam = args}};
  }
  MaInstruction MaInstruction::store(MaStoreInstructionArgs* args) {
    return MaInstruction{VStore, {.store = args}};
  }
  MaInstruction MaInstruction::load(MaLoadInstructionArgs* args) {
    return MaInstruction{VLoad, {.load = args}};
  }
  MaInstruction MaInstruction::jump(size_t index) {
    return MaInstruction{VJump, {.jump = index}};
  }
  MaInstruction MaInstruction::jumpiftrue(size_t index) {
    return MaInstruction{VJumpIfTrue, {.jumpiftrue = index}};
  }
  MaInstruction MaInstruction::jumpiffalse(size_t index) {
    return MaInstruction{VJumpIfFalse, {.jumpiffalse = index}};
  }
  MaInstruction MaInstruction::get(MaGetInstructionArgs* args) {
    return MaInstruction{VGet, {.get = args}};
  }
  MaInstruction MaInstruction::set(MaSetInstructionArgs* args) {
    return MaInstruction{VSet, {.set = args}};
  }
  MaInstruction MaInstruction::try_(MaTryInstructionArgs* args) {
    return MaInstruction{VTry, {.try_ = args}};
  }
  MaInstruction MaInstruction::trydone(MaTryDoneInstructionArgs* args) {
    return MaInstruction{VTryDone, {.trydone = args}};
  }
  MaInstruction MaInstruction::throw_(MaThrowInstructionArgs* args) {
    return MaInstruction{VThrow, {.throw_ = args}};
  }
  MaInstruction MaInstruction::list() {
    return MaInstruction{VList};
  }
  MaInstruction MaInstruction::listappend() {
    return MaInstruction{VListAppend};
  }
  MaInstruction MaInstruction::dict() {
    return MaInstruction{VDict};
  }
  MaInstruction MaInstruction::dictset(MaDictSetInstructionArgs* args) {
    return MaInstruction{VDictSet, {.dictset = args}};
  }
  MaInstruction MaInstruction::struct_(MaStructInstructionArgs* args) {
    return MaInstruction{VStruct, {.struct_ = args}};
  }
  MaInstruction MaInstruction::structparam(MaStructParamInstructionArgs* args) {
    return MaInstruction{VStructParam, {.structparam = args}};
  }
  MaInstruction MaInstruction::structmethod() {
    return MaInstruction{VStructMethod};
  }
  MaInstruction MaInstruction::module(MaModuleInstructionArgs* args) {
    return MaInstruction{VModule, {.module = args}};
  }
  MaInstruction MaInstruction::give(MaGiveInstructionArgs* args) {
    return MaInstruction{VGive, {.give = args}};
  }
  MaInstruction MaInstruction::moduledone() {
    return MaInstruction{VModuleDone};
  }
  MaInstruction MaInstruction::keepmodule() {
    return MaInstruction{VKeepModule};
  }
  MaInstruction MaInstruction::loadmodule() {
    return MaInstruction{VLoadModule};
  }
  MaInstruction MaInstruction::moduleload(MaModuleLoadInstructionArgs* args) {
    return MaInstruction{VModuleLoad, {.moduleload = args}};
  }
  MaInstruction MaInstruction::take(MaTakeInstructionArgs* args) {
    return MaInstruction{VTake, {.take = args}};
  }
  MaInstruction MaInstruction::eq() {
    return MaInstruction{VEq};
  }
  MaInstruction MaInstruction::gt() {
    return MaInstruction{VGt};
  }
  MaInstruction MaInstruction::ge() {
    return MaInstruction{VGe};
  }
  MaInstruction MaInstruction::lt() {
    return MaInstruction{VLt};
  }
  MaInstruction MaInstruction::le() {
    return MaInstruction{VLe};
  }
  MaInstruction MaInstruction::contains() {
    return MaInstruction{VContains};
  }
  MaInstruction MaInstruction::is() {
    return MaInstruction{VIs};
  }
  MaInstruction MaInstruction::not_() {
    return MaInstruction{VNot};
  }
  MaInstruction MaInstruction::negative() {
    return MaInstruction{VNegative};
  }
  MaInstruction MaInstruction::positive() {
    return MaInstruction{VPositive};
  }
  MaInstruction MaInstruction::bnot() {
    return MaInstruction{VBnot};
  }
  MaInstruction MaInstruction::add(MaInstructionLocation* location) {
    return MaInstruction{VAdd, {}, location};
  }
  MaInstruction MaInstruction::sub(MaInstructionLocation* location) {
    return MaInstruction{VSub, {}, location};
  }
  MaInstruction MaInstruction::mul(MaInstructionLocation* location) {
    return MaInstruction{VMul, {}, location};
  }
  MaInstruction MaInstruction::div(MaInstructionLocation* location) {
    return MaInstruction{VDiv, {}, location};
  }
  MaInstruction MaInstruction::mod(MaInstructionLocation* location) {
    return MaInstruction{VMod, {}, location};
  }
  MaInstruction MaInstruction::divdiv(MaInstructionLocation* location) {
    return MaInstruction{VDivDiv, {}, location};
  }
  MaInstruction MaInstruction::pow(MaInstructionLocation* location) {
    return MaInstruction{VPow, {}, location};
  }
  MaInstruction MaInstruction::xor_() {
    return MaInstruction{VXor};
  }
  MaInstruction MaInstruction::bor() {
    return MaInstruction{VBor};
  }
  MaInstruction MaInstruction::band() {
    return MaInstruction{VBand};
  }
  MaInstruction MaInstruction::shl() {
    return MaInstruction{VShl};
  }
  MaInstruction MaInstruction::shr() {
    return MaInstruction{VShr};
  }
} // namespace mavka::mama