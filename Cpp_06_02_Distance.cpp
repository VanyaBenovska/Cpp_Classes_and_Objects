// Cpp_06_02_Distance.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<cmath>
#include <iomanip>

class Point2D
{
private:
	double x;
	double y;

public:
	Point2D(double x, double y) :
		x(x), y(y) {
	}

	double getFirstCoordinate()
	{
		return this->x;
	}

	double getSecondCoordinate()
	{
		return this->y;
	}
};

double CalculateDistance(Point2D p1, Point2D p2);


int main()
{
	double x1, y1, x2, y2;
	std::cin >> x1 >> y1 >> x2 >> y2;

	//CHECK:
	//std::cout << x1 << ", " << y1 << ", " << x2 << ", " << y2;

	Point2D p1(x1, y1);
	Point2D p2(x2, y2);

	//double distance = CalculateDistance(p1, p2);
	std::cout << std::fixed << std::setprecision(3) << CalculateDistance(p1, p2) << std::endl << std::endl;

	return 0;
}

double CalculateDistance(Point2D p1, Point2D p2)
{
	double xDistance = abs(p1.getFirstCoordinate() - p2.getFirstCoordinate());
	double yDistance = abs(p1.getSecondCoordinate() - p2.getSecondCoordinate());

	double distance = sqrt(xDistance * xDistance +
		yDistance * yDistance);
	return distance;
}