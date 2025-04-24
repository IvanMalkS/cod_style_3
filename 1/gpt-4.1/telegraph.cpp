/* Продолжение задания №Телеграф */

#include "telegraph.h"
#include <map>

using namespace std;

// Таблица соответствия русских букв к азбуке Морзе
static map<wchar_t, wstring> morseCode = {
	{L'А', L"·−"}, {L'Б', L"−···"}, {L'В', L"·−−"}, {L'Г', L"−−·"},
	{L'Д', L"−··"}, {L'Е', L"·"}, {L'Ж', L"···−"}, {L'З', L"−−··"},
	{L'И', L"··"}, {L'Й', L"·−−−"}, {L'К', L"−·−"}, {L'Л', L"·−··"},
	{L'М', L"−−"}, {L'Н', L"−·"}, {L'О', L"−−−"}, {L'П', L"·−−·"},
	{L'Р', L"·−·"}, {L'С', L"···"}, {L'Т', L"−"}, {L'У', L"··−"},
	{L'Ф', L"··−·"}, {L'Х', L"····"}, {L'Ц', L"−·−·"}, {L'Ч', L"−−−·"},
	{L'Ш', L"−−−−"}, {L'Щ', L"−−·−"}, {L'Ъ', L"·−−·−·"}, {L'Ы', L"−·−−"},
	{L'Ь', L"−··−"}, {L'Э', L"··−··"}, {L'Ю', L"··−−"}, {L'Я', L"·−·"}
};

wchar_t toUpper(wchar_t ch) {
	if (ch >= L'а' && ch <= L'я') {
		return ch - L'а' + L'А';
	}
	if (ch == L'ё') {
		return L'Ё';
	}
	return ch;
}

wstring toMorse(const wstring& input) {
	wstring result;

	for (auto ch : input) {
		ch = toUpper(ch);

		if (ch == L' ') {
			result += L"  "; // двойной пробел между словами
			continue;
		}

		if (morseCode.count(ch) > 0) {
			result += morseCode[ch] + L" ";
		} else {
			result += L"? "; // неизвестный символ
		}
	}

	return result;
}
