#include "CoinClass.hpp"
#include <iostream>
#include <vector>


int main()
{
    Coin c(80);
    std::vector<sideOfCoin> v = c.getDrawnValues();
    c.printDraws();
    std::cout << std::endl;
    c.countPercent();
}
