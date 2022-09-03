#include "CaesarCipherClass.hpp"
#include <iostream>

int main()
{
    try 
    {
        CaesarCipher cipher;
        std::string line = { "hello world" };
        std::cout << cipher.cypher(line, 29) << std::endl;
        std::string line2 = { "khoor zruog" };
        std::cout << cipher.decepher(line2, 3) << std::endl;

    }
    catch (const std::invalid_argument& error)
    {
        std::cout << error.what() << std::endl;
    }


}
