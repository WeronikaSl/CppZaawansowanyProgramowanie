#include <iostream>
#include <vector>
#include <list>

//pkt a
template <typename OutputIterator, typename SizeType, typename ValueType>
void iota_n(OutputIterator& dest, SizeType n, ValueType value)
{
    for (size_t i = 0; i < n; ++i)
    {
        dest.push_back(value);
        ++value;
    }

}

//pkt b

template <class InputIt, class Size, class UnaryFunction>
void for_each_n(InputIt first, InputIt last, Size n, UnaryFunction f)
{
    auto it = first;
    while (it != last)
    {
        f(*it);
        std::advance(it, n);
    }

}



int main()
{
//pkt a
    std::cout << "Pkt a: " << std::endl;
    std::vector<double> v = {};
    iota_n(v, 10, 10.5);

    for (const auto& element : v)
    {
        std::cout << element << std::endl;
    }

    std::cout << std::endl;

    std::list<int> l = {};
    iota_n(l, 5, 10);
    
    for (const auto& element : l)
    {
        std::cout << element << std::endl;
    }

//pkt b
    std::cout << std::endl << "Pkt b: " << std::endl;

    std::vector<int> vec = {1,2,3,4,5,6,7,8,9,10};
    auto lambda = [&](int value)
    {
        std::cout << value << std::endl;
    };
    
    for_each_n(vec.cbegin(), vec.cend(), 2, lambda);

    std::cout << std::endl;

    std::list<double> l2 = { 1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 9.9 };
    auto lambda2 = [&](double val)
    {
        val = val * 2;
        std::cout << val << std::endl;
    };
    for_each_n(l2.begin(), l2.end(), 5, lambda2);
}
