#include <iostream>
using namespace std;

class TriangleError {
public:
	TriangleError() : message("Sides is not correct") {
	}
	void printMessage() const {
		cout << message << endl;
	}
private: string message;
};

class Triangle {

public:	

	Triangle triangleS(int x, int y, int z) {
		double p, k;
		Triangle t;
		p = (x + y + z) / 2;
		k = p * (p - x) * (p - y) * (p - z);
		t.S = pow(k, 1.0 / 2);
		return t;
	}
	void showS() {
		cout << "Squre of triangle: " << S << endl;
	}

private:
	double S;
};


int main()
{
	try {
		double a, b, c;
		cout << "first side: ";
		cin >> a;
		cout << "second side: ";
		cin >> b;
		cout << "third side: ";
		cin >> c;

		if (a + b < c || a + c < b || b + c < a) {
			throw TriangleError();
		}
		Triangle tri;
		tri.triangleS(a, b, c);
		tri.showS();
	}
	catch (TriangleError error) {
		cout << "Error: ";
		error.printMessage();
		return 1;
	}

	return 0;
}