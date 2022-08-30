#include "LettersInStringStruct.hpp"

unsigned int LettersInString::findCommonLetters(std::string s1, std::string s2)
{
    std::unordered_set<char> s = {};
    auto lambda = [&s2, &s](char sign) 
    {
        for (auto it = s2.begin(); it < s2.end(); ++it)
        {
            if ((*it) == sign)
            {
                s.insert(sign);
            }
        }
    };
    std::for_each(s1.begin(), s1.end(), lambda);

    return s.size();
}
