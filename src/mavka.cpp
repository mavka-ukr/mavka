#include "mavka.h"

namespace mavka {
  std::string cell_to_string(MaMa* M, MaValue cell, int depth) {
    if (cell.IsEmpty()) {
      return "пусто";
    }
    if (IS_NUMBER(cell)) {
      if (std::isinf(cell.AsNumber())) {
        return "нескінченність";
      }
      if (std::isnan(cell.AsNumber())) {
        return "невизначеність";
      }
      return ma_number_to_string(cell.v.number);
    }
    if (cell.IsYes()) {
      return "так";
    }
    if (cell.IsNo()) {
      return "ні";
    }
    if (IS_OBJECT(cell)) {
      if (cell.v.object->type == MA_OBJECT) {
        std::vector<std::string> items;
        for (const auto& param :
             cell.v.object->structure->d.structure->params) {
          const auto value = cell.v.object->GetProperty(M, param.name);
          items.push_back(param.name + "=" +
                          cell_to_string(M, value, depth + 1));
        }
        return cell.v.object->structure->d.structure->name + "(" +
               mavka::internal::tools::implode(items, ", ") + ")";
      }
      if (cell.v.object->type == MA_OBJECT_DIIA) {
        const auto name = cell.v.object->d.diia->name;
        if (name.empty()) {
          return "<дія>";
        }
        return "<дія " + name + ">";
      }
      if (cell.v.object->type == MA_OBJECT_NATIVE) {
        const auto name = cell.v.object->d.native->name;
        if (name.empty()) {
          return "<дія>";
        }
        return "<дія " + name + ">";
      }
      if (cell.v.object->type == MA_OBJECT_STRING) {
        if (depth > 0) {
          return "\"" + cell.v.object->d.text->data + "\"";
        }
        return cell.v.object->d.text->data;
      }
      if (cell.v.object->type == MA_OBJECT_LIST) {
        std::vector<std::string> items;
        for (const auto& item : cell.v.object->d.list->data) {
          items.push_back(cell_to_string(M, item, depth + 1));
        }
        return "[" + mavka::internal::tools::implode(items, ", ") + "]";
      }
      if (cell.v.object->type == MA_OBJECT_DICT) {
        std::vector<std::string> items;
        for (const auto& item : cell.v.object->d.dict->data) {
          items.push_back(cell_to_string(M, item.first, depth + 1) + "=" +
                          cell_to_string(M, item.second, depth + 1));
        }
        return "(" + mavka::internal::tools::implode(items, ", ") + ")";
      }
      if (cell.v.object->type == MA_OBJECT_STRUCTURE) {
        return "<структура " + cell.v.object->d.structure->name + ">";
      }
      if (cell.v.object->type == MA_OBJECT_MODULE) {
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
    }
    if (cell.IsArgs()) {
      return "<аргументи>";
    }
    if (cell.IsError()) {
      return "<помилка>";
    }
    return "<невідомо>";
  }
} // namespace mavka