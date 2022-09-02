#pragma once
#include <unordered_set>
#include <algorithm>


class StringCensor
{
private:
	std::unordered_set<char> _lettersToCensor = {};
	void isCharToCensor(char& c);
public:
	void addCensoredLetter(char c);
	void censor(std::string& word);

};