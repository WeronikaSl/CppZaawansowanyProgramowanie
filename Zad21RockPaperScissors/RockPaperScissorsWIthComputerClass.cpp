#include "RockPaperScissorsWIthComputerClass.hpp"

void RockPaperScissorsWithComputer::whoGetsPoint(RPS playerMove, RPS computerMove)
{
	if (computerMove == RPS::PAPER && playerMove == RPS::PAPER)
	{
		std::cout << "Remis, nikt nie dostaje punktu" << std::endl; //zrobić funkcję
	}
	if (computerMove == RPS::ROCK && playerMove == RPS::ROCK)
	{
		std::cout << "Remis, nikt nie dostaje punktu" << std::endl; //zrobić funkcję
	}
	if (computerMove == RPS::SCISSORS && playerMove == RPS::SCISSORS)
	{
		std::cout << "Remis, nikt nie dostaje punktu" << std::endl; //zrobić funkcję
	}

	if (playerMove == RPS::PAPER && computerMove == RPS::ROCK)
	{
		_player.addPoint();
	}
	if (playerMove == RPS::ROCK && computerMove == RPS::SCISSORS)
	{
		_player.addPoint();
	}
	if (playerMove == RPS::SCISSORS && computerMove == RPS::PAPER)
	{
		_player.addPoint();
	}


	if (computerMove == RPS::PAPER && playerMove == RPS::ROCK)
	{
		_computer.addPoint();
	}
	if (computerMove == RPS::ROCK && playerMove == RPS::SCISSORS)
	{
		_computer.addPoint();
	}
	if (computerMove == RPS::SCISSORS && playerMove == RPS::PAPER)
	{
		_computer.addPoint();
	}


}

void RockPaperScissorsWithComputer::displayWhoWon(unsigned short playersPoints, unsigned short computersPoints)
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
	unsigned short computer = 0;
	while (_player.hasWon() != true && _computer.hasWon() != true)
	{
		computer = _computer.move();
		RPS playersMove = static_cast<RPS>(_player.move());
		RPS computersMove = static_cast<RPS>(computer);
		_computer.displayComputersMove(computer);
		whoGetsPoint(playersMove, computersMove);
		displayWhoWon(_player.getPoints(), _computer.getPoints());
	}
}
