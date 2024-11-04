#include "../parser.h"

namespace mavka::parser {
  std::any MavkaASTVisitor::visitNumber(MavkaParser::NumberContext* context) {
    const auto створити_число_асд_дані = new СтворитиЧислоАСДДані();
    створити_число_асд_дані->значення = strdup(context->getText().c_str());
    return AV(this, context, АСДВидСтворитиЧисло, створити_число_асд_дані);
  }
} // namespace mavka::parser