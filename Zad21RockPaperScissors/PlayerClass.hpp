#pragma once
#include <iostream>

class Player
{
private:
	unsigned short _points = 0;
public:
	unsigned short move() const;
	bool hasWon() const;
	void addPoint();
	unsigned short getPoints() const;

};