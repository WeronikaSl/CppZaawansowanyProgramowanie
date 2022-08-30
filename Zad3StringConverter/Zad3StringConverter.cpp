#include "StringConverterClass.hpp"
#include <iostream>

int main()
{
    StringConverter sc;
    std::cout << sc.toSnakeCase("camelCase") << std::endl;
    std::cout << sc.toCamelCase("snake_case") << std::endl;
    std::cout << sc.toSnakeCase("camelCase") << std::endl;


}