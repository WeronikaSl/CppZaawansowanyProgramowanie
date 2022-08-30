#include "MyStringStruct.hpp"

std::string MyString::reverseString(std::string str)
{
    std::stack<char> s;
    for_each(str.begin(), str.end(), [&s](char sign) {s.push(sign); });
    str.clear();
    while (!s.empty())
    {
        str.push_back(s.top());
        s.pop();
    }

    return str;
}

