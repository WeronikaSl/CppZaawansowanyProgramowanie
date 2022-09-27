#include "RockPaperScissors2PlayersClass.hpp"

int RockPaperScissors2Players::whoGetsPoint(RPS player1Move, RPS player2Move)
{
	if (player2Move == RPS::PAPER && player1Move == RPS::ROCK)
	{
		_player2.addPoint();
		std::cout << "Graczka nr 2 zdobywa punkt" << std::endl;
		return 0;
	}
	if (player2Move == RPS::ROCK && player1Move == RPS::SCISSORS)
	{
		_player2.addPoint();
		std::cout << "Graczka nr 2 zdobywa punkt" << std::endl;
		return 0;
	}
	if (player2Move == RPS::SCISSORS && player1Move == RPS::PAPER)
	{
		_player2.addPoint();
		std::cout << "Graczka nr 2 zdobywa punkt" << std::endl;
		return 0;
	}


	if (player1Move == RPS::PAPER && player2Move == RPS::ROCK)
	{
		_player1.addPoint();
		std::cout << "Graczka nr 1 zdobywa punkt" << std::endl;
		return 0;
	}
	if (player1Move == RPS::ROCK && player2Move == RPS::SCISSORS)
	{
		_player1.addPoint();
		std::cout << "Graczka nr 1 zdobywa punkt" << std::endl;
		return 0;
	}
	if (player1Move == RPS::SCISSORS && player2Move == RPS::PAPER)
	{
		_player1.addPoint();
		std::cout << "Graczka nr 1 zdobywa punkt" << std::endl;
		return 0;
	}

	return isRemis(player1Move, player2Move);

	return 0;
}

void RockPaperScissors2Players::displayWhoWon(unsigned short player1Points, unsigned short player2Points) const
{
	if (player1Points == 3)
	{
		std::cout << "Wygrała graczka numer 1!" << std::endl;
	}
	else if (player2Points == 3)
	{
		std::cout << "Wygrała graczka numer 2!" << std::endl;
	}
}

void RockPaperScissors2Players::game()
{
	std::cout << std::endl << "Wygrywa ta graczka, która pierwsza zdobędzie 3 pkt :)" << std::endl << std::endl;

	while (_player1.hasWon() != true && _player2.hasWon() != true)
	{
		const RPS player1Move = static_cast<RPS>(_player1.move());
		system("CLS");
		const RPS player2Move = static_cast<RPS>(_player2.move());
		whoGetsPoint(player1Move, player2Move);
		displayWhoWon(_player1.getPoints(), _player2.getPoints());
		std::cout << std::endl;
	}
}
