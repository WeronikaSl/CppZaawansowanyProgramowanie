#include "StringConverterClass.hpp"
#include <iostream>

int main()
{
    std::cout << StringConverter::toCamelCase("hello_s_d_a") << std::endl;
    std::cout << StringConverter::toSnakeCase("isThisFirstEntry") << std::endl;
}