#pragma once

#include <iostream>

using namespace std;

class circleType
{
public:
	void setRadius(double r)
	{
		if (r >= 0)
		{
			radius = r;
		}
		else
		{
			radius = 0;
		}
	}
	double getRadius()
	{
		return radius;
	}
	double circumference()
	{
		return 2 * 3.1416 * radius;
	}
	double area()
	{
		return 3.1416 * pow(radius, 2);
	}
	circleType(double r = 0)
	{
		setRadius(r);
	}
	void PrintCircleProperties(double r, double c, double a)
	{
		cout << "The radius of the circle is " << r << endl;
		cout << "The circumference of the circle is " << c << endl;
		cout << "The area of the circle is " << a << endl;
	}
private:
	double radius;
};

class cylinderType : public circleType
{
public:
	using circleType::circleType;
	void setHeight(double h)
	{
		height = h;
	}
	void CalculateSurfaceArea(double c)
	{
		surfaceArea = c * height;
	}
	void CalculateVolume(double a)
	{
		volume = a * height;
	}
	void PrintCylinderProperties()
	{
		cout << "The surface area of the Cylinder is " << surfaceArea << endl;
		cout << "The volume of the Cylinder is " << volume << endl;
	}
	double GetSurfaceArea()
	{
		return surfaceArea;
	}
	double GetVolume()
	{
		return volume;
	}
private:
	double height;
	double surfaceArea;
	double volume;
};

class LiquidShipper : public cylinderType
{
public:
	void CalculateShippingCost(double v, double shippingCostPerLiter)
	{
		shippingCost = (v * CubicFeetToLiterRatio) * shippingCostPerLiter;
	}
	void CalculatePaintCost(double a, double paintCostPerSquareFoot)
	{
		paintCost = a * paintCostPerSquareFoot;
	}
	void PrintShippingCost()
	{
		cout << "Shipping costs: $" << shippingCost << endl;
	}
	void PrintPaintCost()
	{
		cout << "Paint costs: $" << paintCost << endl;
	}
private:
	const double CubicFeetToLiterRatio = 28.32;
	double shippingCost;
	double paintCost;
};