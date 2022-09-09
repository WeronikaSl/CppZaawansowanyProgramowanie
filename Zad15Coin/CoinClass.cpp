#include "CoinClass.hpp"

sideOfCoin Coin::generateSideOfCoin()
{
    std::random_device r;
    std::default_random_engine e(r());
    std::uniform_int_distribution<int> distr (0, 1);

    return static_cast<sideOfCoin>(distr(e));
}

void Coin::printPercent(double percentOfO, double percentOfR) const
{
    std::cout << "Procent orłów: " << percentOfO * 100 << "%" << std::endl;
    std::cout << "Procent reszek: " << percentOfR * 100 << "%" << std::endl;

}

void Coin::printLongestRow(sideOfCoin RorO, unsigned int amount) const
{
    std::cout << "Najdłuższy ciąg " << RorO << " ma długość : " << amount << std::endl;

}

void Coin::countPercent() const
{
    int amountOfO = 0;
    int amountOfR = 0;

    auto lambda = [&](sideOfCoin s)
    {
        if (s == sideOfCoin::O)
        {
            amountOfO++;
        }
        else
        {
            amountOfR++;
        }
    };
    std::for_each(_drawnValues.cbegin(), _drawnValues.cend(), lambda);
    
    double percentOfO = amountOfO/static_cast<double>(_drawnValues.size());
    double percentOfR = amountOfR / static_cast<double>(_drawnValues.size());
    printPercent(percentOfO, percentOfR);
}

void Coin::longestRowOfO() const
{
    unsigned int amountOfO = 0;
    std::vector<unsigned int> vecOfAmounts = {};
    
    auto lambda = [&](sideOfCoin value)
    {
        if (sideOfCoin::O == value)
        {
            amountOfO++;
        }
        else
        {
            vecOfAmounts.push_back(amountOfO);
            amountOfO = 0;
        }
    };

    std::for_each(_drawnValues.cbegin(), _drawnValues.cend(), lambda);

    auto longestRow = std::max_element(vecOfAmounts.cbegin(), vecOfAmounts.cend());

    std::cout << "Najdłuższy ciąg orłów ma długość: " << *longestRow << std::endl;

}

void Coin::longestRowOfR() const
{
    {
        unsigned int amountOfR = 0;
        std::vector<unsigned int> vecOfAmounts = {};

        auto lambda = [&](sideOfCoin value)
        {
            if (sideOfCoin::R == value)
            {
                amountOfR++;
            }
            else
            {
                vecOfAmounts.push_back(amountOfR);
                amountOfR = 0;
            }
        };

        std::for_each(_drawnValues.cbegin(), _drawnValues.cend(), lambda);

        auto longestRow = std::max_element(vecOfAmounts.cbegin(), vecOfAmounts.cend());

        std::cout << "Najdłuższy ciąg reszek ma długość: " << *longestRow << std::endl;

    }
}

void Coin::longestRowOorR(sideOfCoin RorO) const
{
    unsigned int amountofValue = 0;
    std::vector<unsigned int> vecOfAmounts = {};

    auto lambda = [&](sideOfCoin value)
    {
        if (RorO == value)
        {
            amountofValue++;
        }
        else
        {
            vecOfAmounts.push_back(amountofValue);
            amountofValue = 0;
        }
    };

    std::for_each(_drawnValues.cbegin(), _drawnValues.cend(), lambda);
    auto longestRow = std::max_element(vecOfAmounts.cbegin(), vecOfAmounts.cend());

    printLongestRow(RorO, *longestRow);
}

void Coin::longestRowOfBoth() const
{
    unsigned int amountofValue = 0;
    std::vector<unsigned int> vecOfAmounts = {};

    for (size_t i = 1; i < _drawnValues.size(); ++i)
    {
        auto help = i;
        --help;
        if (_drawnValues.at(i) != _drawnValues.at(help))
        {
            ++amountofValue;
        }
        else
        {
            ++amountofValue;
            vecOfAmounts.push_back(amountofValue);
            amountofValue = 0;
        }
    }
    auto longestRow = std::max_element(vecOfAmounts.cbegin(), vecOfAmounts.cend());

    std::cout << "Najdłuższy ciąg OR wynosi " << *longestRow << std::endl;
}

Coin::Coin(int howManyDraws)
{
    for (size_t i = 0; i < howManyDraws; ++i)
    {
        _drawnValues.push_back(generateSideOfCoin());
    }
}

std::vector<sideOfCoin> Coin::getDrawnValues() const
{
    return _drawnValues;
}

void Coin::printDraws() const
{
    for (size_t i = 0; i < _drawnValues.size(); ++i)
    {
        if ((i!=0) && (i % 20 == 0))
        {
            std::cout << std::endl;
        }
        if (_drawnValues.at(i) == sideOfCoin::O)
        {
            std::cout << sideOfCoin::O;
        }
        else if (_drawnValues.at(i) == sideOfCoin::R)
        {
            std::cout << sideOfCoin::R;
        }
    }
}

std::ostream& operator<<(std::ostream& s, const sideOfCoin& val)
{
    if (sideOfCoin::O == val)
    {
        s << "O";
    }
    else if (sideOfCoin::R == val)
    {
        s << "R";
    }
    else
    {
        s << "Nie ma takiej wartości";
    }

    return s;
}
