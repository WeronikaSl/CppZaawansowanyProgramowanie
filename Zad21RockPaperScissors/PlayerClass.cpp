#include "PlayerClass.hpp"

unsigned short Player::move() const
{
    unsigned short move = 0;
    std::cout << "Wybierz numer (1.Kamień 2.Papier 3.Nożyce): ";
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

}

unsigned short Player::getPoints() const
{
    return _points;
}
