#include <iostream>
#include <istream>
#include <string>
#include <cmath>
#include <string>
#include <sstream>
#include <cstdio>
using namespace std;


//3.Control.1
int snilsCheck(string snils);
//3.Control.2
void cubeFirst(int);
void cubeSecond(int);
//3.Control.3
void triangleS(int x);
void triangleS(int x, int y, int z);
void triChoice(int x, int y, int z);
//3.Control.4
int recSum(int);
//3.Control.5
int DecToBin(int y);

int main()
{
	// Practice 3
	int x = 6;
	int y = 20;
	int z = 10;

	//cubeFirst(x);
	//cubeSecond(x);

	//triChoice(x, y, z);

	//cout << "Summ: " << recSum(x);
	//DecToBin(x);
	string snils = "14343817049";
	snilsCheck(snils);
}

// Practice 3

// To Binary by recursion

int DecToBin(int x) {
	if (x >= 1) {
		DecToBin(x / 2);
		cout << x % 2;
	}
	return 0;
}

// Summ by recursion

int recSum(int n) {
	if (n > 0) {
		return (5 * n + recSum(n - 1));
	}
	return 0;
}

// Triangls

void triChoice(int x, int y, int z) {
	int i;
	cout << "Please choose type of tri. 1 for equal, 2 for scalene\n";
	cin >> i;
	if (i == 1)
		triangleS(x);
	else if (i == 2)
		triangleS(x, y, z);
}

void triangleS(int x) {
	double s;
	s = x * x * pow(3, 1.0 / 3) * 0.25;
	cout << "Squre of equalTri with side " << x << " is: " << s << endl;
}

void triangleS(int x, int y, int z) {
	double s, p, k;
	p = (x + y + z) / 2;
	k = p * (p - x) * (p - y) * (p - z);
	s = pow(k, 1.0 / 2);
	cout << "Squre of triangle: " << s << endl;
}

// Cube root

void cubeFirst(int x) {
	double y;
	y = pow(x, 1.0 / 3);
	cout << "Cube root of " << x << " is: " << y << endl;
}
void cubeSecond(int x) {
	double y1, y0, k;
	k = 0.0001;
	y1 = 1;
	do {
		y0 = y1;
		y1 = (x / (y0 * y0) + 2 * y0) / 3;
	} while (abs(y1 - y0) >= k);

	cout << "Cube root of " << x << " is: " << y1 << endl;
}

// Practice 3 SNILS

int snilsCheck(string snils) {

	int sum = 0;

	// String clean
	snils.erase(remove(snils.begin(), snils.end(), '-'), snils.end());
	snils.erase(remove(snils.begin(), snils.end(), ' '), snils.end());

	// String to int array
	int snilsArr[11];
	int x = size(snilsArr);
	stringstream ss;

	for (int i = 0; i < x; i++) {
		ss << snils[i];
		ss >> snilsArr[i];
		ss.str("");
		ss.clear();
	}

	// Control Sum & 2 numbers check
	for (int i = x - 2, j = 0; i >= 1, j <= x - 3; i--, j++) {
		if (snilsArr[j] == snilsArr[j + 1] && j <= 7) {
			cout << "Wrong snils number!" << endl;
			return 0;
		}
		else {
			sum = sum + i * snilsArr[j];
		}
	}

	// Control number calc
	int contArr[2];
	if (sum < 100) {
		contArr[0] = sum / 10;
		contArr[1] = sum % 10;
	}
	else if (sum == 100 || sum == 101) {
		contArr[0] = 0;
		contArr[1] = 0;
	}
	else if (sum > 101) {
		sum = sum % 101;
		if (sum < 100) {
			contArr[0] = sum / 10;
			contArr[1] = sum % 10;
		}
		else if (sum == 100) {
			contArr[0] = 0;
			contArr[1] = 0;
		}
	}
	// Control number check
	if (snilsArr[9] == contArr[0] && snilsArr[10] == contArr[1]) {
		cout << "SNILS is true" << endl;
		return 0;
	}
	else {
		cout << "SNILS is false" << endl;
		return 0;
	}
}