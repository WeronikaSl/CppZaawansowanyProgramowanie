#include "RockPaperScissorsWIthComputerClass.hpp"

int RockPaperScissorsWithComputer::whoGetsPoint(RPS playerMove, RPS computerMove)
{
	if (playerMove == RPS::PAPER && computerMove == RPS::ROCK)
	{
		_player.addPoint();
		std::cout << "Zdobywasz 1 punkt" << std::endl;
		return 0;
	}
	if (playerMove == RPS::ROCK && computerMove == RPS::SCISSORS)
	{
		_player.addPoint();
		std::cout << "Zdobywasz 1 punkt" << std::endl;
		return 0;
	}
	if (playerMove == RPS::SCISSORS && computerMove == RPS::PAPER)
	{
		_player.addPoint();
		std::cout << "Zdobywasz 1 punkt" << std::endl;
		return 0;
	}


	if (computerMove == RPS::PAPER && playerMove == RPS::ROCK)
	{
		_computer.addPoint();
		return 0;
	}
	if (computerMove == RPS::ROCK && playerMove == RPS::SCISSORS)
	{
		_computer.addPoint();
		return 0;
	}
	if (computerMove == RPS::SCISSORS && playerMove == RPS::PAPER)
	{
		_computer.addPoint();
		return 0;
	}

	return isRemis(playerMove, computerMove);

	return 0;

}

void RockPaperScissorsWithComputer::displayWhoWon(unsigned short playersPoints, unsigned short computersPoints) const
{
	if (playersPoints == 3)
	{
		std::cout << "Gratulacje, wygrałaś!" << std::endl;
	}
	else if (computersPoints == 3)
	{
		std::cout << "Niestety, komputer wygrał :(" << std::endl;
	}
}

void RockPaperScissorsWithComputer::game()
{
	std::cout << std::endl << "Wygrywa ta strona, która pierwsza zdobędzie 3 pkt :)" << std::endl << std::endl;
	unsigned short computer = 0;
	while (_player.hasWon() != true && _computer.hasWon() != true)
	{
		computer = _computer.move();
		RPS playersMove = static_cast<RPS>(_player.move());
		RPS computersMove = static_cast<RPS>(computer);
		_computer.displayComputersMove(computer);
		whoGetsPoint(playersMove, computersMove);
		displayWhoWon(_player.getPoints(), _computer.getPoints());
		std::cout << std::endl;
	}
}
