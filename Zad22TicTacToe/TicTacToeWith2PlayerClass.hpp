#pragma once
#include "PlayerClass.hpp"
#include <iostream>
#include <array>

class Player;

enum class TicTacToe {O, X};

class TicTacToeWith2Player
{
private:
	std::array<std::array<TicTacToe, 3>, 3> _board = {};
	Player _p1 (TicTacToe TicTacToe::O);
	void game();
	void printBoard();
};

std::ostream& operator<< (std::ostream& s, const TicTacToe& other);