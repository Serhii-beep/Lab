#include "g2.h"

Point::Point() : x(0), y(0)
{}


Point::Point(double _x, double _y) : x(_x), y(_y)
{}


double Point::getX()
{
	return x;
}


double Point::getY()
{
	return y;
}


bool Point::operator==(const Point& object)
{
	return (x == object.x && y == object.y);
}

bool Point::operator!=(const Point& object)
{
	return (x != object.x || y != object.y);
}


