#include <iostream>
#include <istream>
#include <string>
#include <cmath>
#include <string>
#include <sstream>
using namespace std;


int Myroot(double, double, double, double&, double&);

int Input(int&, int&);

int main()
{

	// Practice 4.1
	double a = 6;
	double b = 5;
	double c = 1;
	double x1; 
	double x2;

	if (Myroot(a, b, c, x1, x2) == -1)
		cout << "No roots" << endl;
	else if (Myroot(a, b, c, x1, x2) == 0) {

		cout << "x1 = x2 =" << x1 << endl;
	}
	else if (Myroot(a, b, c, x1, x2) == 1) {
		cout << "x1 = " << x1 << endl;
		cout << "x2 = " << x2 << endl;
	}

	// Practice 4.2
	int a, b;
	if (Input(a, b) == false) // if(!Input(a,b))
	{
		cerr << "error";
		return 1;
	}
	int s = a + b;
	cout << "Sum: " << s << endl;
	return 0;
}

int Input(int& a, int& b) {
	cout << "Enter nums:" << endl;
	cin >> a >> b;
	if (a > 5 || b > 7)
		return 0;
	else
		return 1;
}

int Myroot(double a, double b, double c, double& x1, double& x2) {
	double d;
	d = b * b - 4 * a * c;
	if (d < 0)
		return -1;
	else if (d == 0) {
		x1 = (-b + pow(d, 0.5)) / (2 * a);
		x2 = (-b + pow(d, 0.5)) / (2 * a);
		return 0;
	}
	else if (d > 0) {
		x1 = (-b + pow(d, 1.0/2)) / (2 * a);
		x2 = (-b - pow(d, 0.5)) / (2 * a);
		return 1;
	}
}

