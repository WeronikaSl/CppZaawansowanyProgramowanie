#include "PrimeAndNonprimeNumsClass.hpp"
#include <iostream>
#include <list>


int main()
{
    PrimeAndNonprimeNums nums;

    std::list<int> list = nums.createListOfPrimeNums();
    for (const auto& n : list)
    {
        std::cout << n << std::endl;
    }

    std::list<int> list2 = nums.createListOfNonprimeNums();
    for (const auto& value : list2)
    {
        std::cout << value << std::endl;
    }

}
