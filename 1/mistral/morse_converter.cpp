/* Продолжение задания №Программа-телеграф */

#include "morse_converter.h"
#include <map>
#include <cctype>
#include <stdexcept>

// Словарь для хранения кодов Морзе
std::map<char, std::string> morseCodeMap = {
    {'А', ".-"}, {'Б', "-..."}, {'В', ".--"}, {'Г', "--."}, {'Д', "-.."}, {'Е', "."},
    {'Ж', "...-"}, {'З', "--.."}, {'И', ".."}, {'Й', ".---"}, {'К', "-.-"}, {'Л', ".-.."},
    {'М', "--"}, {'Н', "-."}, {'О', "---"}, {'П', ".--."}, {'Р', ".-."}, {'С', "..."},
    {'Т', "-"}, {'У', "..-"}, {'Ф', "..-."}, {'Х', "...."}, {'Ц', "-.-."}, {'Ч', "---."},
    {'Ш', "----"}, {'Щ', "--.-"}, {'Ъ', "--.--"}, {'Ы', "-.--"}, {'Ь', "-..-"}, {'Э', "..-.."},
    {'Ю', "..--"}, {'Я', ".-.-"}
};

std::string textToMorse(const std::string& text) {
    if (text.empty()) {
        throw std::invalid_argument("Входная строка не может быть пустой");
    }

    std::string morseCode;
    for (char ch : text) {
        // Преобразуем символ в верхний регистр
        char upperChar = toupper(static_cast<unsigned char>(ch));
        auto it = morseCodeMap.find(upperChar);
        if (it != morseCodeMap.end()) {
            morseCode += it->second + " ";
        } else {
            morseCode += " "; // Добавляем пробел для неизвестных символов
        }
    }
    return morseCode;
}
