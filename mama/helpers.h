#ifndef HELPERS_H
#define HELPERS_H

std::string gettypename(size_t type);

std::string getcelltypename(MaCell cell);

std::string getcellstructurename(MaCell cell);

std::string cell_to_string(MaCell cell, int depth = 0);

void print_cell(MaCell* cell);

void print_instruction_with_index(MaCode* code,
                                  int index,
                                  MaInstruction instruction);

void print_code(MaCode* code);

#endif // HELPERS_H