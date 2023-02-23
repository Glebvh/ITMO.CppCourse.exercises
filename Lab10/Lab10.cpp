#include <iostream>
#include "dot.h"
using namespace std;


class Triangle {

public:


	Triangle(const Dot& a, const Dot& b, const Dot& c)
	{
		pointA = new Dot(a);
		pointB = new Dot(b);
		pointC = new Dot(c);
		
	}

	double getA() {
		return pointA->distanceTo(pointB);
	}
	double getB() {
		return  pointB->distanceTo(pointC);
	}
	double getC() {
		return  pointC->distanceTo(pointA);
	}

	void showSides() {
		cout << "First side: " << getA() << endl;
		cout << "Second side: " << getB() << endl;
		cout << "Third side: " << getC() << endl;
	}

	double triangleP() {
		
		double sideA = getA();
		double sideB = getB();
		double sideC = getC();
		double P  = sideA + sideB + sideC;

		return P;
	}

	double triangleS() {
		double p, k, S;
		double sideA = getA();
		double sideB = getB();
		double sideC = getC();

		p = (sideA + sideB + sideC) / 2;
		k = p * (p - sideA) * (p - sideB) * (p - sideC);
		S = pow(k, 1.0 / 2);

		return S;
	}

private:

	double S;
	Dot* pointA;
	Dot* pointB;
	Dot* pointC;
};


int main()
{
	double x1 = 1, y1 = 1;
	double x2 = 5, y2 = 5;
	double x3 = 2, y3 = 6;
	Dot a(x1, y1);
	Dot b(x2, y2);
	Dot c(x3, y3);
	Triangle* tri = new Triangle(a, b, c);
	tri->showSides();
	double S = tri->triangleS();
	cout << "Square is " << S << endl;
	double P = tri->triangleP();
	cout << "Perimetr is " << P << endl;

	delete tri;
	
	return 0;
}