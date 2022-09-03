#include "MorseCodeTranslator.hpp"
#include <iostream>

int main()
{
    MorseCodeTranslator mct;
    std::cout << mct.fromMorseCode(".- -... -.-. -..") << std::endl;
    std::cout << mct.toMorseCode("abcd") << std::endl;
}
