#include "PlayerClass.hpp"

unsigned short Player::move() const
{
    unsigned short move = 0;
    std::cout << "Wybierz numer (0.Kamień 1.Papier 2.Nożyce): ";
    std::cin >> move;
    return move;
}

bool Player::hasWon() const
{
    return _points == 3;
}

void Player::addPoint()
{
    _points++;
    std::cout << "Zdobywasz 1 punkt" << std::endl;
}

unsigned short Player::getPoints() const
{
    return _points;
}
