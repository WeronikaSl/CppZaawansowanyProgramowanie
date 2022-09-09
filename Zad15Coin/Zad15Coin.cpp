#include "CoinClass.hpp"
#include <iostream>
#include <vector>


int main()
{
    Coin c(10);
    std::vector<sideOfCoin> v = c.getDrawnValues();
    c.printDraws();
    std::cout << std::endl;
    c.countPercent();
    std::cout << std::endl;
    c.longestRowOfO();
    c.longestRowOfR();
    std::cout << std::endl;
    c.longestRowOorR(sideOfCoin::O);
    c.longestRowOorR(sideOfCoin::R);
    std::cout << std::endl;
    c.longestRowOfBoth();
}
