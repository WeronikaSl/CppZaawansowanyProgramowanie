#include "SortListClass.hpp"
#include <iostream>

int main()
{
    SortList sl;
    std::cout << sl << std::endl;
    std::list<int> l = sl.sortList();
    for (const auto& v : l)
    {
        std::cout << v << ' ';
    }


}
