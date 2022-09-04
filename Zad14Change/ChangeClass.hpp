#pragma once
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <iomanip>

class Change
{
private:
	std::vector<int> _nominalValues = {20000, 10000, 5000, 2000, 1000, 500, 200, 100, 50, 20, 10, 5, 2, 1}; //w groszach
	void display(int amountOfNominals, int value) const;
public:
	void optimalChange(double change) const;
};