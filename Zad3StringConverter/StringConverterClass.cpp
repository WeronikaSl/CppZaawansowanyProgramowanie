#include "StringConverterClass.hpp"

std::string StringConverter::toSnakeCase(std::string str)
{
    std::list<char> l = {};
    std::for_each(str.cbegin(), str.cend(), [&l](char sign) {l.push_back(sign);});

    auto lambda = [&l](char& sign)
    {
        if ((sign >= 65) && (sign <= 90))
        {
            auto pos = (std::find(l.cbegin(), l.cend(), sign));
            sign += 32;
            l.emplace(pos, '_');
        }
    };
    std::for_each(l.begin(), l.end(), lambda);
    std::string s = {};
    std::for_each(l.begin(), l.end(), [&s](char sign) {s.push_back(sign);});

    return s;
}

std::string StringConverter::toCamelCase(std::string str)
{
    std::list<char> l = {};
    std::for_each(str.cbegin(), str.cend(), [&l](char sign) {l.push_back(sign); });

    auto lambda = [&l](char& sign)
    {
        if (sign == '_')
        {
            auto pos = (std::find(l.begin(), l.end(), sign));
            l.erase(remove(l.begin(), l.end(), sign), l.end());
            (*pos) -= 32;
            
        }
    };
    std::for_each(l.begin(), l.end(), lambda);
    std::string s = {};
    std::for_each(l.begin(), l.end(), [&s](char sign) {s.push_back(sign); });

    return s;
}
