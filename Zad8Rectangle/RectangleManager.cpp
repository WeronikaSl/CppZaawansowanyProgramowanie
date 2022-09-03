#include "RectangleManager.hpp"

RectangleManager::RectangleManager()
{
	RectangleGenerator rg;
	for (size_t i = 0; i < 100; ++i)
	{
		_vecOfRectangles.push_back(rg.generateRectangle());
	}
}


size_t RectangleManager::countRectangleBiggerThan(int area)
{
	size_t amount = count_if(_vecOfRectangles.cbegin(), _vecOfRectangles.cend(), [&area](Rectangle rec) {return rec.getArea() > area; });
	return amount;
}

std::vector<Rectangle> RectangleManager::copyRectangles()
{
	std::vector<Rectangle> vecOfSquares = {};
	auto lambda = [](Rectangle rec)
	{
		return rec.isSquare();
	};
	std::copy_if(_vecOfRectangles.cbegin(), _vecOfRectangles.cend(), std::back_inserter(vecOfSquares), lambda);
	return vecOfSquares;
}

std::vector<Rectangle> RectangleManager::getRectangles() const
{
	return _vecOfRectangles;
}

void RectangleManager::sortAreaDescending()
{
	std::sort(_vecOfRectangles.begin(), _vecOfRectangles.end(), [](Rectangle r1, Rectangle r2) {return (r1.getArea()) > (r2.getArea());});
}

void RectangleManager::deleteInvalid()
{
	auto lambda = [](Rectangle rec)
	{
		return 0 == rec.getArea();
	};
	_vecOfRectangles.erase(remove_if(_vecOfRectangles.begin(), _vecOfRectangles.end(), lambda), _vecOfRectangles.end());
}

void printRectangles(std::vector<Rectangle> v)
{
	std::for_each(v.begin(), v.end(), [](Rectangle rec) {std::cout << rec << std::endl << std::endl; });

}
