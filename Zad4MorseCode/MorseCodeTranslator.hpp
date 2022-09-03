#pragma once
#include <map>
#include <string>
#include <algorithm>
#include <vector>



class MorseCodeTranslator
{
private:
	std::map<std::string, char> _morseToLetters = { {".-",'A'}, {"-...",'B'}, {"-.-.",'C'}, {"-..",'D'}, {".", 'E'}, {"..-.", 'F' }, {"--.", 'G' }, {"....", 'H'}, {"..", 'I'}, {".---", 'J' } };
	std::map<char, std::string> _lettersToMorse = {{'a' ,".-"}, {'b' ,"-..."}, {'c' ,"-.-."}, {'d' ,"-.."}, {'e' ,"."}, {'f' ,"..-."}, {'g' ,"--."}, {'h' ,"...."}, {'i' ,".."}, {'j' ,".---"} };
public:
	std::string fromMorseCode(std::string morse);
	std::string toMorseCode(std::string letters);

};
