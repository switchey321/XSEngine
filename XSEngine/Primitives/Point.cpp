#include "../Primitives.hpp"

Point::Point() {}

Point::Point(int x, int y) {
	this->x = x;
	this->y = y;
}

int Point::getX() {
	return this->x;
}

int Point::getY() {
	return this->y;
}

void Point::setY(int y)
{
	this->y = y;
}

void Point::setX(int x)
{
	this->x = x;
}

void Point::set(int x, int y)
{
	this->x = x;
	this->y = y;
}

