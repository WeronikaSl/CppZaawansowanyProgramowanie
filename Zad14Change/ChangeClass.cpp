#include "ChangeClass.hpp"

void Change::display(int amountOfEachNominal, int value) const
{
	std::string toDisplay = {};
	toDisplay.append(std::to_string(amountOfEachNominal));
	toDisplay.append(" nominał/nominałów o wartości ");
	std::cout << toDisplay << std::setprecision(4) << (value / 100.0) << std::endl;
}

void Change::optimalChange(double change) const
{
	change *= 100;
	int amountOfEachNominal = 0;

	auto lambda = [&](int value)
	{
		while (change >= value)
		{
			change -= value;
			amountOfEachNominal++;
		}
		if (amountOfEachNominal > 0)
		{
			display(amountOfEachNominal, value);
		}
		amountOfEachNominal = 0;
	};

	std::for_each(_nominalValues.cbegin(), _nominalValues.cend(), lambda);
}
