/**
 * MIT License
 *
 * Copyright (c) 2024 Контрибутори Цілі
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#include <stdio.h>
#include <wchar.h>
#ifdef _WIN32
#include <windows.h>
#endif

#ifdef _WIN32
extern long ___біб__юнікод__ю8_в_ю16___(unsigned char *input, long input_size,
                                        unsigned short int *output);
#endif

extern void ___біб__друк_ю8___(unsigned char *value) {
#ifdef _WIN32
  long len = strlen((char *)value);
  unsigned short int *value16 = (unsigned short int *)malloc((len + 1) * 2);
  long outlen = ___біб__юнікод__ю8_в_ю16___(value, len, value16);
  value16[outlen] = 0;
  WriteConsoleW(GetStdHandle(STD_OUTPUT_HANDLE), value16, wcslen(value16), NULL,
                NULL);
  WriteConsoleW(GetStdHandle(STD_OUTPUT_HANDLE), L"\n", 1, NULL, NULL);
  free(value16);
#else
  printf("%s\n", (char *)value);
#endif
}

extern void ___біб__друк_ю16___(unsigned short int *value) {
#ifdef _WIN32
  WriteConsoleW(GetStdHandle(STD_OUTPUT_HANDLE), (wchar_t *)value,
                wcslen((wchar_t *)value), NULL, NULL);
  WriteConsoleW(GetStdHandle(STD_OUTPUT_HANDLE), L"\n", 1, NULL, NULL);
#else
  wprintf(L"%ls\n", value);
#endif
}

extern void ___біб__друк_ю32___(unsigned int *value) {
  //
}

extern void ___біб__друк_п8___(unsigned char value) {
  //
}

extern void ___біб__друк_п16___(unsigned short int value) {
  //
}

extern void ___біб__друк_п32___(unsigned int value) {
  //
}

extern void ___біб__друк_п64___(unsigned long value) {
  //
}

extern void ___біб__друк_позитивне___(unsigned long value) {
  printf("%lu\n", value);
}

extern void ___біб__друк_ц8___(char value) {
  //
}

extern void ___біб__друк_ц32___(int value) {
  //
}

extern void ___біб__друк_ц64___(long value) {
  //
}

extern void ___біб__друк_ціле___(long value) {
  //
}

extern void ___біб__друк_д32___(float value) {
  //
}

extern void ___біб__друк_д64___(double value) {
  //
}

extern void ___біб__друк_дійсне___(double value) {
  //
}

extern void ___біб__друк_комірку___(void *value) { printf("%p\n", value); }

extern void ___біб__вивести_ю8___(unsigned char *value) {
#ifdef _WIN32
  long len = strlen((char *)value);
  unsigned short int *value16 = (unsigned short int *)malloc((len + 1) * 2);
  long outlen = ___біб__юнікод__ю8_в_ю16___(value, len, value16);
  value16[outlen] = 0;
  WriteConsoleW(GetStdHandle(STD_OUTPUT_HANDLE), value16, wcslen(value16), NULL,
                NULL);
  free(value16);
#else
  printf("%s", (char *)value);
#endif
}

extern void ___біб__вивести_ю16___(unsigned short int *value) {
#ifdef _WIN32
  WriteConsoleW(GetStdHandle(STD_OUTPUT_HANDLE), (wchar_t *)value,
                wcslen((wchar_t *)value), NULL, NULL);
#else
  wprintf(L"%ls", value);
#endif
}

extern void ___біб__вивести_п8___(unsigned char value) {
  //
}

extern void ___біб__вивести_п32___(unsigned int value) {
  //
}

extern void ___біб__вивести_п64___(unsigned long value) {
  //
}

extern void ___біб__вивести_позитивне___(unsigned long value) {
  printf("%lu", value);
}

extern void ___біб__вивести_ц8___(char value) {
  //
}

extern void ___біб__вивести_ц32___(int value) {
  //
}

extern void ___біб__вивести_ц64___(long value) {
  //
}

extern void ___біб__вивести_ціле___(long value) {
  //
}

extern void ___біб__вивести_д32___(float value) {
  //
}

extern void ___біб__вивести_д64___(double value) {
  //
}

extern void ___біб__вивести_дійсне___(double value) {
  //
}

extern void ___біб__вивести_комірку___(void *value) { printf("%p", value); }
