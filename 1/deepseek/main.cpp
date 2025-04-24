/* Программа-телеграф, которая принимает от пользователя сообщение 
   и выводит его на экран в виде последовательности точек и тире */
#include <iostream>
#include <string>
#include <unordered_map>
#include "morse_encoder.h"

int main() {
    MorseEncoder encoder;
    std::string input;

    std::cout << "Введите сообщение для кодирования в азбуку Морзе: ";
    std::getline(std::cin, input);

    try {
        std::string morseCode = encoder.encodeToMorse(input);
        std::cout << "Закодированное сообщение: " << morseCode << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cerr << "Ошибка: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
