/* Продолжение задания №Программа-телеграф */

#include <iostream>
#include "morse_converter.h"

int main() {
    std::string message;
    std::cout << "Введите сообщение: ";
    std::getline(std::cin, message);

    std::string morseMessage = textToMorse(message);
    std::cout << "Азбука Морзе: " << morseMessage << std::endl;

    return 0;
}
