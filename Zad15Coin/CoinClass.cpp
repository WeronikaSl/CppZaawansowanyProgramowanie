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

void Coin::countPercent() 
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
    std::for_each(_drawnValues.begin(), _drawnValues.end(), lambda);
    
    double percentOfO = amountOfO/static_cast<double>(_drawnValues.size());
    double percentOfR = amountOfR / static_cast<double>(_drawnValues.size());
    printPercent(percentOfO, percentOfR);
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
            std::cout << "O";
        }
        else if (_drawnValues.at(i) == sideOfCoin::R)
        {
            std::cout << "R";
        }
    }
}
