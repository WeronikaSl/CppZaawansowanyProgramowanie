#pragma once
#include <iostream>

class Rectangle
{
private:
	int _a = 0;
	int _b = 0;
public:
	Rectangle(int a, int b);
	Rectangle(const Rectangle& other);
	virtual ~Rectangle() = default;
	int getArea() const;
	bool isSquare() const;
	int getA() const;
	int getB() const;
	Rectangle& operator=(const Rectangle& other);

};

std::ostream& operator << (std::ostream& stream, const Rectangle& rec);