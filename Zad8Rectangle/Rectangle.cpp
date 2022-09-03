#include "Rectangle.hpp"

Rectangle::Rectangle(int a, int b) : _a(a), _b(b)
{
}

Rectangle::Rectangle(const Rectangle& other)
{
    this->_a = other._a;
    this->_b = other._b;
}

int Rectangle::getArea() const
{
    return _a*_b;
}

bool Rectangle::isSquare() const
{
    return (_a == _b);
}

int Rectangle::getA() const
{
    return _a;
}

int Rectangle::getB() const
{
    return _b;
}

Rectangle& Rectangle::operator=(const Rectangle& other)
{
    this->_a = other._a;
    this->_b = other._b;
    return *this;
}

std::ostream& operator<<(std::ostream& stream, const Rectangle& rec)
{
    stream
        << "Bok a: " << rec.getA() << std::endl
        << "Bok b: " << rec.getB();
    return stream;
}
