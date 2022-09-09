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
	void printLongestRow(sideOfCoin RorO, unsigned int amount) const;

public:
	Coin(int howManyDraws);
	std::vector<sideOfCoin> getDrawnValues() const;
	void printDraws() const;
	void countPercent() const;
	void longestRowOfO() const;
	void longestRowOfR() const;
	void longestRowOorR(sideOfCoin value) const;
	void longestRowOfBoth() const;

};

std::ostream& operator<< (std::ostream& s, const sideOfCoin& val);