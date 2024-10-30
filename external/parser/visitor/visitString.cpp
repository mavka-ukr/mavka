#include "../parser.h"

namespace mavka::parser {
  std::any MavkaASTVisitor::visitString(MavkaParser::StringContext* context) {
    std::string text;
    if (context->STRING()) {
      text = context->STRING()->getText();
      text = text.substr(1, text.length() - 2);
    } else {
      text = context->STRING_MULTILINE()->getText();
      text = text.substr(3, text.length() - 6);
    }
    mavka::parser::tools::replace_all(text, "\\0", "\0");
    mavka::parser::tools::replace_all(text, "\\n", "\n");
    mavka::parser::tools::replace_all(text, "\\r", "\r");
    mavka::parser::tools::replace_all(text, "\\t", "\t");
    mavka::parser::tools::replace_all(text, "\\\"", "\"");
    mavka::parser::tools::replace_all(text, "\\\\", "\\");
    const auto створити_текст_асд_дані = new СтворитиТекстАСДДані();
    створити_текст_асд_дані->значення = strdup(text.c_str());
    створити_текст_асд_дані->інтерпольовано = false;
    return AV(this, context, АСДВидСтворитиТекст, створити_текст_асд_дані);
  }

  std::any MavkaASTVisitor::visitCharacter(
      MavkaParser::CharacterContext* context) {
    std::string text;
    text = context->CHARACTER()->getText();
    text = text.substr(1, text.length() - 2);
    mavka::parser::tools::replace_all(text, "\\0", "\0");
    mavka::parser::tools::replace_all(text, "\\n", "\n");
    mavka::parser::tools::replace_all(text, "\\r", "\r");
    mavka::parser::tools::replace_all(text, "\\t", "\t");
    mavka::parser::tools::replace_all(text, "\\\"", "\"");
    mavka::parser::tools::replace_all(text, "\\\\", "\\");
    const auto створити_символ_асд_дані = new СтворитиСимволАСДДані();
    створити_символ_асд_дані->значення = strdup(text.c_str());
    return AV(this, context, АСДВидСтворитиСимвол, створити_символ_асд_дані);
  }
} // namespace mavka::parser