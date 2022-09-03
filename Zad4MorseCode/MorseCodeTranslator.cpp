#include "MorseCodeTranslator.hpp"

std::string MorseCodeTranslator::fromMorseCode(std::string morse)
{
    std::vector<std::string> words = {};
    std::string line = {};
    for (auto it = morse.begin(); it < morse.end(); ++it)
    {
        if (*it != ' ')
        {
            line.push_back(*it);
        }
        else
        {
            words.push_back(line);
            line.clear();
        }
    }
    words.push_back(line);
    line.clear();

    auto lambda = [&](std::string lineInMorse)
    {
        line.push_back(_morseToLetters[lineInMorse]);
    };
    std::for_each(words.begin(), words.end(), lambda);


    return line;
}

std::string MorseCodeTranslator::toMorseCode(std::string letters)
{
    std::string inMorse = {};
    auto lambda = [&](char character)
    {
        inMorse.append(_lettersToMorse[character]);
        inMorse.append(" ");
    };
    std::for_each(letters.begin(), letters.end(), lambda);

    return inMorse;
}
