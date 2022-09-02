#include "StringCensor.hpp"
#include <iostream>

int main()
{
    StringCensor censor;
    censor.addCensoredLetter('a');
    std::string a = "HahA";
    std::cout << a << std::endl;
    censor.censor(a);
    std::cout << a << std::endl;

    censor.addCensoredLetter('d');
    censor.addCensoredLetter('o');
    std::string b = "Diodbdfa";
    std::cout << b << std::endl;
    censor.censor(b);
    std::cout << b << std::endl;





}

