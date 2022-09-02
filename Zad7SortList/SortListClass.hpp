#pragma once
#include <list>
#include <random>
#include <iostream>
#include <algorithm>

class SortList
{
private:
	std::list<int> _list = {};
public:
	SortList();
	std::list<int> getList() const;
	std::list<int> sortList();
};

std::ostream& operator << (std::ostream& stream, SortList& object);