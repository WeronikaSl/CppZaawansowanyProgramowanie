#include "RectangleGenerator.hpp"

Rectangle RectangleGenerator::generateRectangle()
{
	std::random_device r;
	std::default_random_engine e (r());
	std::uniform_int_distribution<int> distr(0, 10);
	Rectangle rec(distr(e), distr(e));
    return rec;
}
