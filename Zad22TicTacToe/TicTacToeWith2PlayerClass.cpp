#include "TicTacToeWith2PlayerClass.hpp"


void TicTacToeWith2Player::game()
{
   
}

void TicTacToeWith2Player::printBoard()
{
}

std::ostream& operator<<(std::ostream& s, const TicTacToe& other)
{
    switch (other)
    {
    case TicTacToe::O:
        std::cout << "O";
        break;
    case TicTacToe::X:
        std::cout << "X";
        break;
    default:
        std::cout << "Error";
    }
}