/* Продолжение задания №Телеграф */

#include <iostream>
#include <locale>
#include "telegraph.h"

using namespace std;

int main() {
	// Устанавливаем локаль для корректного ввода/вывода русских символов
	setlocale(LC_ALL, "");

	wcout << L"Введите сообщение (русскими буквами): ";
	wstring input;
	getline(wcin, input);

	wstring morseMessage = toMorse(input);

	wcout << morseMessage << endl;

	return 0;
}
