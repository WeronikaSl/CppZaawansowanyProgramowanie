#include "CaesarCipherClass.hpp"

void CaesarCipher::isSecretValueCorrect(int sv)
{
    if (!(sv >= 1 && sv <= 26))
    {
        throw std::invalid_argument("Secret value musi być z przedziału 1-26!");
    }
}

std::string CaesarCipher::cypher(std::string text, int secretValue)
{
    isSecretValueCorrect(secretValue);
    auto lambda = [&secretValue](char& c)
    {
        if (c != ' ')
        {
            if (!(c >= 97 && c <= 122))
            {
                throw std::invalid_argument("Zakodowane mogą zostać tylko litery z przedziału a-z oraz spacja!");
            }
            else if ((c + secretValue) > 122)
            {
                int x = 122 - c;
                c = 97 + (secretValue - x - 1);
            }
            else
            {
                c += secretValue;
            }
        }
    };
    std::for_each(text.begin(), text.end(), lambda);
    return text;
}

std::string CaesarCipher::decepher(std::string text, int secretValue)
{
    auto lambda = [&secretValue](char& c)
    {
        if (c != ' ')
        {
            if (!(c >= 97 && c <= 122))
            {
                throw std::invalid_argument("Odkodowane mogą zostać tylko litery z przedziału a-z oraz spacja!");
            }
            else if ((c - secretValue) < 97)
            {
                int x = c - 97;
                c = 122 - (secretValue - x - 1);
            }
            else
            {
                c -= secretValue;
            }
        }
    };
    std::for_each(text.begin(), text.end(), lambda);
    return text;
}
