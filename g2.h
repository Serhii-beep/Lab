#pragma once


class Point 
{
public:
	Point();
	Point(double _x, double _y);
	double getX();
	double getY();
	bool operator == (const Point& object);
	bool operator != (const Point& object);

private:
	double x;
	double y;
};