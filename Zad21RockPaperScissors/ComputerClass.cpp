#include "ComputerClass.hpp"

void Computer::displayComputersMove(unsigned short move) const
{
    switch (move)
    {
    case 1:
        std::cout << "Komputer wybrał kamień" << std::endl;
        break;
    case 2:
        std::cout << "Komputer wybrał papier" << std::endl;
        break;
    case 3:
        std::cout << "Komputer wybrał nożyce" << std::endl;
        break;
    }
}

unsigned short Computer::getPoints() const
{
    return _points;
}

unsigned short Computer::move() const
{
    std::random_device r;
    std::default_random_engine e(r());
    std::uniform_int_distribution<int> distr(1, 3);
    return distr(e);
}

bool Computer::hasWon() const
{
    return _points == 3;
}

void Computer::addPoint()
{
    _points++;
    std::cout << "Komputer zdobywa 1 punkt" << std::endl;
}
