#include "SortListClass.hpp"

SortList::SortList()
{
	std::random_device r;
	std::default_random_engine engine(r());
	std::uniform_int_distribution<int> distr(1, 50);
	for (size_t i = 0; i < 50; ++i)
	{
		_list.push_back(distr(engine));
	}
}

std::list<int> SortList::getList() const
{
	return _list;
}

std::list<int> SortList::sortList()
{
	std::list<int> evenNums = {};
	std::list<int> unevenNums = {};

	for (auto it = _list.begin(); it != _list.end(); ++it)
	{
		if (*it % 2 == 0)
		{
			evenNums.push_back(*it);
		}
		else
		{
			unevenNums.push_back(*it);
		}
	}

	evenNums.sort();
	unevenNums.sort(std::greater<int>());
	std::list<int> list = evenNums;
	evenNums.splice(evenNums.end(), unevenNums);
	return evenNums;
}

std::ostream& operator<<(std::ostream& stream, SortList& object)
{
	for (const auto& v : object.getList())
	{
		stream << v << ' ';
	}
	return stream;
}
