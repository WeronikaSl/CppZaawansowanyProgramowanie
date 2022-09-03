#pragma once
#include <string>
#include <algorithm>
#include <stdexcept>

class CaesarCipher
{
	void isSecretValueCorrect(int sv);
public:
	std::string cypher(std::string text, int secretValue);
	std::string decepher(std::string text, int secretValue);
};