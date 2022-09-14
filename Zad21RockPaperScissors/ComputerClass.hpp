#pragma once
#include <iostream>
#include <random>

class Computer
{
private:
	unsigned short _points = 0;
public:
	unsigned short move() const;
	bool hasWon() const;
	void addPoint();
	void displayComputersMove(unsigned short move) const;
	unsigned short getPoints() const;
};