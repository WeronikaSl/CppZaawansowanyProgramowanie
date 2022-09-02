#include "PrimeAndNonprimeNumsClass.hpp"

PrimeAndNonprimeNums::PrimeAndNonprimeNums()
{
	_l.resize(1000);
	std::iota(_l.begin(), _l.end(), 1);
}

std::list<int> PrimeAndNonprimeNums::createListOfPrimeNums()
{
	std::list<int> l;
	int divisors = 0;
	auto lambda = [&](int& value)
	{
		if (value != 1)
		{
			for (size_t i = value; i > 0; --i)
			{
				if (value % i == 0)
				{
					++divisors;
				}
			}
		}

		if (2 == divisors)
		{
			l.push_back(value);
		}
		divisors = 0;
	};
	std::for_each(_l.begin(), _l.end(), lambda);
	return l;
}

std::list<int> PrimeAndNonprimeNums::createListOfNonprimeNums()
{
	std::list<int> l;
	int divisors = 0;
	auto lambda = [&](int& value)
	{
		if (value == 1)
		{
			l.push_back(value);
		}
		else
		{
			for (size_t i = value; i > 0; --i)
			{
				if (value % i == 0)
				{
					++divisors;
				}
			}

			if (divisors > 2)
			{
				l.push_back(value);
			}
			divisors = 0;
		}
	};
	std::for_each(_l.begin(), _l.end(), lambda);
	return l;
}
