#ifndef MORSE_ENCODER_H
#define MORSE_ENCODER_H

#include <string>
#include <unordered_map>

class MorseEncoder {
public:
	MorseEncoder();
	std::string encodeToMorse(const std::string& text) const;

private:
	std::unordered_map<char, std::string> morseAlphabet;
	std::string encodeChar(char c) const;
	bool isValidRussianChar(char c) const;
};

#endif // MORSE_ENCODER_H
