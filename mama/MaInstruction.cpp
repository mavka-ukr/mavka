#include "mama.h"

namespace mavka::mama {
  std::string getopname(const OP op) {
    switch (op) {
      case OP_CONSTANT:
        return "OP_CONSTANT";
      case OP_ADD:
        return "OP_ADD";
      case OP_SUB:
        return "OP_SUB";
      case OP_MUL:
        return "OP_MUL";
      case OP_DIV:
        return "OP_DIV";
      case OP_MOD:
        return "OP_MOD";
      case OP_DIVDIV:
        return "OP_DIVDIV";
      case OP_POW:
        return "OP_POW";
      case OP_STORE:
        return "OP_STORE";
      case OP_LOAD:
        return "OP_LOAD";
      case OP_GET:
        return "OP_GET";
      case OP_SET:
        return "OP_SET";
      case OP_XOR:
        return "OP_XOR";
      case OP_BOR:
        return "OP_BOR";
      case OP_BAND:
        return "OP_BAND";
      case OP_SHL:
        return "OP_SHL";
      case OP_SHR:
        return "OP_SHR";
      case OP_BNOT:
        return "OP_BNOT";
      case OP_JUMP_IF_FALSE:
        return "OP_JUMP_IF_FALSE";
      case OP_JUMP_IF_TRUE:
        return "OP_JUMP_IF_TRUE";
      case OP_E_JUMP_IF_FALSE:
        return "OP_E_JUMP_IF_FALSE";
      case OP_E_JUMP_IF_TRUE:
        return "OP_E_JUMP_IF_TRUE";
      case OP_JUMP:
        return "OP_JUMP";
      case OP_THROW:
        return "OP_THROW";
      case OP_EQ:
        return "OP_EQ";
      case OP_LT:
        return "OP_LT";
      case OP_LE:
        return "OP_LE";
      case OP_CONTAINS:
        return "OP_CONTAINS";
      case OP_GT:
        return "OP_GT";
      case OP_GE:
        return "OP_GE";
      case OP_CALL:
        return "OP_CALL";
      case OP_RETURN:
        return "OP_RETURN";
      case OP_POP:
        return "OP_POP";
      case OP_LIST:
        return "OP_LIST";
      case OP_LIST_APPEND:
        return "OP_LIST_APPEND";
      case OP_NEGATIVE:
        return "OP_NEGATIVE";
      case OP_POSITIVE:
        return "OP_POSITIVE";
      case OP_DIIA:
        return "OP_DIIA";
      case OP_DICT:
        return "OP_DICT";
      case OP_DICT_SET:
        return "OP_DICT_SET";
      case OP_STRUCT:
        return "OP_STRUCT";
      case OP_GIVE:
        return "OP_GIVE";
      case OP_MODULE:
        return "OP_MODULE";
      case OP_TRY:
        return "OP_TRY";
      case OP_TRY_DONE:
        return "OP_TRY_DONE";
      case OP_NOT:
        return "OP_NOT";
      case OP_INITCALL:
        return "OP_INITCALL";
      case OP_DIIA_PARAM:
        return "OP_DIIA_PARAM";
      case OP_STRUCT_PARAM:
        return "OP_STRUCT_PARAM";
      case OP_STRUCT_METHOD:
        return "OP_STRUCT_METHOD";
      case OP_MODULE_DONE:
        return "OP_MODULE_DONE";
      case OP_STORE_ARG:
        return "OP_STORE_ARG";
      case OP_NUMBER:
        return "OP_NUMBER";
      case OP_EMPTY:
        return "OP_EMPTY";
      case OP_YES:
        return "OP_YES";
      case OP_NO:
        return "OP_NO";
      case OP_KEEP_MODULE:
        return "OP_KEEP_MODULE";
      case OP_IS:
        return "OP_IS";
      case OP_TAKE:
        return "OP_TAKE";
      case OP_LOAD_MODULE:
        return "OP_LOAD_MODULE";
      case OP_MODULE_LOAD:
        return "OP_MODULE_LOAD";
      case OP_PUSH_ARG:
        return "OP_PUSH_ARG";
      default:
        break;
    }
    return std::to_string(op);
  }
  MaInstruction MaInstruction::pop() {
    return MaInstruction{OP_POP};
  }
  MaInstruction MaInstruction::constant(size_t index) {
    return MaInstruction{OP_CONSTANT, {.constant = index}};
  }
  MaInstruction MaInstruction::number(double value) {
    return MaInstruction{OP_NUMBER, {.number = value}};
  }
  MaInstruction MaInstruction::empty() {
    return MaInstruction{OP_EMPTY};
  }
  MaInstruction MaInstruction::yes() {
    return MaInstruction{OP_YES};
  }
  MaInstruction MaInstruction::no() {
    return MaInstruction{OP_NO};
  }
  MaInstruction MaInstruction::initcall(MaInitCallInstructionArgs* args) {
    return MaInstruction{OP_INITCALL, {.initcall = args}};
  }
  MaInstruction MaInstruction::pusharg() {
    return MaInstruction{OP_PUSH_ARG};
  }
  MaInstruction MaInstruction::storearg(MaStoreArgInstructionArgs* args) {
    return MaInstruction{OP_STORE_ARG, {.storearg = args}};
  }
  MaInstruction MaInstruction::call() {
    return MaInstruction{OP_CALL};
  }
  MaInstruction MaInstruction::return_() {
    return MaInstruction{OP_RETURN};
  }
  MaInstruction MaInstruction::diia(MaDiiaInstructionArgs* args) {
    return MaInstruction{OP_DIIA, {.diia = args}};
  }
  MaInstruction MaInstruction::diiaparam(MaDiiaParamInstructionArgs* args) {
    return MaInstruction{OP_DIIA_PARAM, {.diiaparam = args}};
  }
  MaInstruction MaInstruction::store(MaStoreInstructionArgs* args) {
    return MaInstruction{OP_STORE, {.store = args}};
  }
  MaInstruction MaInstruction::load(MaLoadInstructionArgs* args) {
    return MaInstruction{OP_LOAD, {.load = args}};
  }
  MaInstruction MaInstruction::jump(size_t index) {
    return MaInstruction{OP_JUMP, {.jump = index}};
  }
  MaInstruction MaInstruction::jumpiftrue(size_t index) {
    return MaInstruction{OP_JUMP_IF_TRUE, {.jumpiftrue = index}};
  }
  MaInstruction MaInstruction::jumpiffalse(size_t index) {
    return MaInstruction{OP_JUMP_IF_FALSE, {.jumpiffalse = index}};
  }
  MaInstruction MaInstruction::get(MaGetInstructionArgs* args) {
    return MaInstruction{OP_GET, {.get = args}};
  }
  MaInstruction MaInstruction::set(MaSetInstructionArgs* args) {
    return MaInstruction{OP_SET, {.set = args}};
  }
  MaInstruction MaInstruction::try_(MaTryInstructionArgs* args) {
    return MaInstruction{OP_TRY, {.try_ = args}};
  }
  MaInstruction MaInstruction::trydone(MaTryDoneInstructionArgs* args) {
    return MaInstruction{OP_TRY_DONE, {.trydone = args}};
  }
  MaInstruction MaInstruction::throw_(MaThrowInstructionArgs* args) {
    return MaInstruction{OP_THROW, {.throw_ = args}};
  }
  MaInstruction MaInstruction::list() {
    return MaInstruction{OP_LIST};
  }
  MaInstruction MaInstruction::listappend() {
    return MaInstruction{OP_LIST_APPEND};
  }
  MaInstruction MaInstruction::dict() {
    return MaInstruction{OP_DICT};
  }
  MaInstruction MaInstruction::dictset(MaDictSetInstructionArgs* args) {
    return MaInstruction{OP_DICT_SET, {.dictset = args}};
  }
  MaInstruction MaInstruction::struct_(MaStructInstructionArgs* args) {
    return MaInstruction{OP_STRUCT, {.struct_ = args}};
  }
  MaInstruction MaInstruction::structparam(MaStructParamInstructionArgs* args) {
    return MaInstruction{OP_STRUCT_PARAM, {.structparam = args}};
  }
  MaInstruction MaInstruction::structmethod() {
    return MaInstruction{OP_STRUCT_METHOD};
  }
  MaInstruction MaInstruction::module(MaModuleInstructionArgs* args) {
    return MaInstruction{OP_MODULE, {.module = args}};
  }
  MaInstruction MaInstruction::give(MaGiveInstructionArgs* args) {
    return MaInstruction{OP_GIVE, {.give = args}};
  }
  MaInstruction MaInstruction::moduledone() {
    return MaInstruction{OP_MODULE_DONE};
  }
  MaInstruction MaInstruction::keepmodule() {
    return MaInstruction{OP_KEEP_MODULE};
  }
  MaInstruction MaInstruction::loadmodule() {
    return MaInstruction{OP_LOAD_MODULE};
  }
  MaInstruction MaInstruction::moduleload(MaModuleLoadInstructionArgs* args) {
    return MaInstruction{OP_MODULE_LOAD, {.moduleload = args}};
  }
  MaInstruction MaInstruction::take(MaTakeInstructionArgs* args) {
    return MaInstruction{OP_TAKE, {.take = args}};
  }
  MaInstruction MaInstruction::eq() {
    return MaInstruction{OP_EQ};
  }
  MaInstruction MaInstruction::gt() {
    return MaInstruction{OP_GT};
  }
  MaInstruction MaInstruction::ge() {
    return MaInstruction{OP_GE};
  }
  MaInstruction MaInstruction::lt() {
    return MaInstruction{OP_LT};
  }
  MaInstruction MaInstruction::le() {
    return MaInstruction{OP_LE};
  }
  MaInstruction MaInstruction::contains() {
    return MaInstruction{OP_CONTAINS};
  }
  MaInstruction MaInstruction::is() {
    return MaInstruction{OP_IS};
  }
  MaInstruction MaInstruction::not_() {
    return MaInstruction{OP_NOT};
  }
  MaInstruction MaInstruction::negative() {
    return MaInstruction{OP_NEGATIVE};
  }
  MaInstruction MaInstruction::positive() {
    return MaInstruction{OP_POSITIVE};
  }
  MaInstruction MaInstruction::bnot() {
    return MaInstruction{OP_BNOT};
  }
  MaInstruction MaInstruction::add() {
    return MaInstruction{OP_ADD};
  }
  MaInstruction MaInstruction::sub() {
    return MaInstruction{OP_SUB};
  }
  MaInstruction MaInstruction::mul() {
    return MaInstruction{OP_MUL};
  }
  MaInstruction MaInstruction::div() {
    return MaInstruction{OP_DIV};
  }
  MaInstruction MaInstruction::mod() {
    return MaInstruction{OP_MOD};
  }
  MaInstruction MaInstruction::divdiv() {
    return MaInstruction{OP_DIVDIV};
  }
  MaInstruction MaInstruction::pow() {
    return MaInstruction{OP_POW};
  }
  MaInstruction MaInstruction::xor_() {
    return MaInstruction{OP_XOR};
  }
  MaInstruction MaInstruction::bor() {
    return MaInstruction{OP_BOR};
  }
  MaInstruction MaInstruction::band() {
    return MaInstruction{OP_BAND};
  }
  MaInstruction MaInstruction::shl() {
    return MaInstruction{OP_SHL};
  }
  MaInstruction MaInstruction::shr() {
    return MaInstruction{OP_SHR};
  }
} // namespace mavka::mama