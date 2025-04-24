/* Продолжение задания №Телеграф */

#ifndef TELEGRAPH_H
#define TELEGRAPH_H

#include <string>

using namespace std;

// Преобразует символ в верхний регистр (русские буквы)
wchar_t toUpper(wchar_t ch);

// Преобразует входную строку в последовательность Морзе
wstring toMorse(const wstring& input);

#endif  // TELEGRAPH_H
