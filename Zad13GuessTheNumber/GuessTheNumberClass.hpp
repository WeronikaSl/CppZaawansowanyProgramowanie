#pragma once
#include <random>
#include <iostream>

class GuessTheNumber
{
private:
	int _numberToGuess = 0;
	int generateNumberToGuess() const;
	int getUserInput() const;
	bool isGuessBigger(int guess); //?
	void isClose(int guess) const;
public:
	GuessTheNumber();
	void guess() const;
};