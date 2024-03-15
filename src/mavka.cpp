#include "mavka.h"

namespace mavka {
  std::string cell_to_string(MaMa* M, MaValue cell, int depth) {
    if (cell.isEmpty()) {
      return "пусто";
    }
    if (cell.isNumber()) {
      if (std::isinf(cell.asNumber())) {
        return "нескінченність";
      }
      if (std::isnan(cell.asNumber())) {
        return "невизначеність";
      }
      return ma_number_to_string(cell.v.number);
    }
    if (cell.isYes()) {
      return "так";
    }
    if (cell.isNo()) {
      return "ні";
    }
    if (cell.isObject()) {
      if (cell.asObject()->isDiia(M)) {
        const auto name = cell.v.object->d.diia->name;
        if (name.empty()) {
          return "<дія>";
        }
        return "<дія " + name + ">";
      }
      if (cell.asObject()->isList(M)) {
        if (depth > 0) {
          return "\"" + cell.v.object->d.text->data + "\"";
        }
        return cell.v.object->d.text->data;
      }
      if (cell.asObject()->isList(M)) {
        std::vector<std::string> items;
        for (const auto& item : cell.v.object->d.list->data) {
          items.push_back(cell_to_string(M, item, depth + 1));
        }
        return "[" + mavka::internal::tools::implode(items, ", ") + "]";
      }
      if (cell.asObject()->isDict(M)) {
        std::vector<std::string> items;
        for (const auto& item : cell.v.object->d.dict->data) {
          items.push_back(cell_to_string(M, item.first, depth + 1) + "=" +
                          cell_to_string(M, item.second, depth + 1));
        }
        return "(" + mavka::internal::tools::implode(items, ", ") + ")";
      }
      if (cell.asObject()->isStructure(M)) {
        return "<структура " + cell.v.object->d.structure->name + ">";
      }
      if (cell.asObject()->isModule(M)) {
        const auto name = cell.v.object->d.module->name;
        std::vector<std::string> items;
        for (const auto& [k, v] : cell.v.object->properties) {
          if (k != "назва") {
            items.push_back(k);
          }
        }
        return "<модуль " + name + "[" +
               mavka::internal::tools::implode(items, ", ") + "]>";
      }
      if (cell.asObject()->isBytes(M)) {
        return "<байти " + std::to_string(cell.v.object->d.bytes->data.size()) +
               ">";
      }
      std::vector<std::string> items;
      for (const auto& param : cell.v.object->type->d.structure->params) {
        const auto value = cell.v.object->getProperty(M, param.name);
        items.push_back(param.name + "=" + cell_to_string(M, value, depth + 1));
      }
      return cell.v.object->type->d.structure->name + "(" +
             mavka::internal::tools::implode(items, ", ") + ")";
    }
    if (cell.isArgs()) {
      return "<аргументи>";
    }
    if (cell.isError()) {
      return "<помилка>";
    }
    return "<невідомо " + std::to_string(cell.type) + ">";
  }
} // namespace mavka