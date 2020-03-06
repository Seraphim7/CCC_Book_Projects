#include <iostream>
#include <iomanip>
#include "shippingLiquids.h"

using namespace std;

int main()
{
	double radius;
	double height;
	double c;
	double a;
	double sa;
	double v;
	double shippingCost;
	double paintCost;

	cout << fixed << setprecision(2);

	cout << "What is the Radius of the container (in feet)?: ";
	cin >> radius;

	cout << "What is the Height of the container (in feet)?: ";
	cin >> height;

	cout << "What is the shipping cost per liter: ";
	cin >> shippingCost;

	cout << "How much does the paint cost (per square foot)?: ";
	cin >> paintCost;

	cout << endl;

	LiquidShipper Cylinder;
	Cylinder.circleType::circleType(radius);
	c = Cylinder.circumference();
	a = Cylinder.area();

	Cylinder.setHeight(height);

	Cylinder.CalculateVolume(a);
	Cylinder.CalculateSurfaceArea(c);
	v = Cylinder.GetVolume();
	sa = Cylinder.GetSurfaceArea();

	Cylinder.CalculateShippingCost(v, shippingCost);
	Cylinder.CalculatePaintCost(sa, paintCost);
	Cylinder.PrintShippingCost();
	Cylinder.PrintPaintCost();
}