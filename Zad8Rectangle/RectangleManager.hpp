#pragma once
#include "Rectangle.hpp"
#include "RectangleGenerator.hpp"
#include<vector>
#include<algorithm>


class RectangleManager
{
private:
	std::vector<Rectangle> _vecOfRectangles = {};
public:
	RectangleManager();
	size_t countRectangleBiggerThan(int area);
	std::vector<Rectangle> copyRectangles();
	std::vector<Rectangle> getRectangles() const;
	void sortAreaDescending();
	void deleteInvalid();
};

void printRectangles(std::vector<Rectangle> v);