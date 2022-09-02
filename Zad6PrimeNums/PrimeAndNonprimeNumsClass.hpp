#pragma once
#include <list>
#include <numeric>
#include <vector>
#include <algorithm>


class PrimeAndNonprimeNums
{
private:
	std::list<int> _l = {};
public:
	PrimeAndNonprimeNums();
	std::list<int> createListOfPrimeNums();
	std::list<int> createListOfNonprimeNums();

};