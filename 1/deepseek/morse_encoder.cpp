#include "morse_encoder.h"
#include <cctype>
#include <stdexcept>

MorseEncoder::MorseEncoder() {
	// Инициализация таблицы Морзе для русских букв
	morseAlphabet = {
		{'А', "·−"}, {'Б', "−···"}, {'В', "·−−"}, {'Г', "−−·"},
		{'Д', "−··"}, {'Е', "·"}, {'Ж', "···−"}, {'З', "−−··"},
		{'И', "··"}, {'Й', "·−−−"}, {'К', "−·−"}, {'Л', "·−··"},
		{'М', "−−"}, {'Н', "−·"}, {'О', "−−−"}, {'П', "·−−·"},
		{'Р', "·−·"}, {'С', "···"}, {'Т', "−"}, {'У', "··−"},
		{'Ф', "··−·"}, {'Х', "····"}, {'Ц', "−·−·"}, {'Ч', "−−−·"},
		{'Ш', "−−−−"}, {'Щ', "−−·−"}, {'Ъ', "·−−·−·"}, {'Ы', "−·−−"},
		{'Ь', "−··−"}, {'Э', "··−··"}, {'Ю', "··−−"}, {'Я', "·−·−"},
		{' ', " "}  // пробел
	};
}

std::string MorseEncoder::encodeToMorse(const std::string& text) const {
	std::string result;
	for (char c : text) {
		if (c == ' ') {
			result += "  ";
			continue;
		}

		char upperC = toupper(c);
		if (!isValidRussianChar(upperC)) {
			throw std::invalid_argument("Неподдерживаемый символ: " + std::string(1, c));
		}

		result += encodeChar(upperC) + " ";
	}

	// Удаляем последний пробел, если он есть
	if (!result.empty()) {
		result.pop_back();
	}

	return result;
}

std::string MorseEncoder::encodeChar(char c) const {
	auto it = morseAlphabet.find(c);
	if (it != morseAlphabet.end()) {
		return it->second;
	}
	return "";
}

bool MorseEncoder::isValidRussianChar(char c) const {
	return (c >= 'А' && c <= 'Я') || c == 'Ё' || c == ' ';
}
