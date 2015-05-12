//C++ Program to calculate the area and perimeter of rectangles using concept of inheritance.

#include <iostream>
using namespace std;
class Rectangle
{
protected:
	float length, breadth;
public:
	Rectangle() : length(0.0), breadth(0.0)
	{
		cout << "Enter length: ";
		cin >> length;
		cout << "Enter breadth: ";
		cin >> breadth;
	}

};

/* Area class is derived from base class Rectangle. */
class Area : public Rectangle
{
public:
	float calc()
	{
		return length*breadth;
	}

};

/* Perimeter class is derived from base class Rectangle. */
class Perimeter : public Rectangle
{
public:
	float calc()
	{
		return 2 * (length + breadth);
	}
};

int main()
{
	cout << "Enter data for first rectangle to find area.\n";
	Area a;
	cout << "Area = " << a.calc() << " square meter\n\n";

	cout << "Enter data for second rectangle to find perimeter.\n";
	Perimeter p;
	cout << "\nPerimeter = " << p.calc() << " meter";
	cin.get();
	return 0;
}





