#pragma once
#include <random>
#include <iostream>
#include <algorithm>

enum class sideOfCoin {O,R};

class Coin
{
private:
	std::vector<sideOfCoin> _drawnValues = {};
	sideOfCoin generateSideOfCoin();
	void printPercent(double percentOfO, double percentOfR) const;
public:
	Coin(int howManyDraws);
	std::vector<sideOfCoin> getDrawnValues() const;
	void printDraws() const;
	void countPercent();

};