#include "StringCensor.hpp"

void StringCensor::isCharToCensor(char& c)
{
	for_each(_lettersToCensor.begin(), _lettersToCensor.end(), [&](char character) {if (c == character) { c = '*'; }});
}

void StringCensor::addCensoredLetter(char c)
{
	_lettersToCensor.insert(c);
}

void StringCensor::censor(std::string& word)
{
	auto lambda = [&](char& c)
	{
		isCharToCensor(c);
	};
	std::for_each(word.begin(), word.end(), lambda);
}
