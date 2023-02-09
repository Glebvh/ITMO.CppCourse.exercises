#include <iostream>
#include <istream>
#include <string>
#include <cmath>
#include <string>
#include <sstream>
using namespace std;

//1.Control
void oneControl();

//---------------------------

// 2.Control.1
int prime();
// 2.Control.2
int snils(string);
// 2.Control.3
void coins();
// 2.Control.4
void target();

//-------------

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
	//oneControl();
	
	//prime();
	//const string snils = "14343817049";
	//snils(snils);
	//coins();
	//target();

	// Practice 3
	int x = 6;
	int y = 20;
	int z = 10;

	//cubeFirst(x);
	//cubeSecond(x);

	//triChoice(x, y, z);

	//cout << "Summ: " << recSum(x);
	//DecToBin(x);
	string snils =  "143-438-170 49";
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
		return (5*n + recSum(n - 1));
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
		triangleS(x, y , z);
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
	s = pow(k, 1.0/2);
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


// Practice 2

// target

void target() {
	double x, y;
	int scores = 0;
	int counter = 0;
	while (scores < 50) {
		cout << "Enter x and y of shot:\n";
		cin >> x;
		cin >> y;
		if (x * x + y * y <= 1)
			scores += 10;
		else if (x * x + y * y > 1 && x * x + y * y <= 2)
			scores += 5;
		else if (x * x + y * y > 2 && x * x + y * y <= 3)
			scores += 1;
		cout << "Scores: " << scores << "\n" << endl;
		counter++;
	}
	if (counter <= 5)
		cout << "Sniper" << endl;
	if (counter > 5 && counter <= 10)
		cout << "Middle sniper" << endl;
	if (counter > 10)
		cout << "Junior sniper" << endl;
}

// Coins

void coins() {
	unsigned short summ;
	cout << "Enter sum: ";
	cin >> summ;

	int Arr[4] = { 10,5,2,1 };

	for (int i = 0; i < sizeof(Arr); i++) {
		int count = summ / Arr[i];
		if (count > 0) {
			cout << "Count of " << Arr[i] << ": " << count << endl;
			summ = summ % Arr[i];
		}
	}
}

// SNILS

int snils(string snils) {
	int x = snils.length();
	//char charArray[11];
	//snils.copy(charArray, x);

	int sArr[11] = { 1,4,3,4,3,8,1,7,0,4,9 };
	int sum = 0;
	// вычисление контрольной суммы и проверка на два подряд числа в массиве
	for (int i = x - 2, j = 0; i >= 1, j <= x - 3; i--, j++) {
		if (sArr[j] == sArr[j + 1] && j <= 7) {
			cout << "Wrong snils number!" << endl;
			return 0;
		}
		else {
			sum = sum + i * sArr[j];
		}
	}
	// вычисление контрольного числа
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
	// проверка равенства контрольных чисел
	if (sArr[9] == contArr[0] && sArr[10] == contArr[1]) {
		cout << "SNILS is true" << endl;
		return 0;
	}
	else {
		cout << "SNILS is false" << endl;
		return 0;
	}
}

// Superprime

int prime() {

	unsigned int x, y, k;
	cout << "Enter number: ";
	cin >> x;
	y = sqrt(x);
	int count = 0;

	// проверка на простоту числа
	for (int i = 2; i <= y; i++) { 
		if (x % i == 0 && x < 2) {
			cout << "Its not a prime number" << endl;
			return 0;
		}
	}
	cout << "\nIt is a Prime number ";
	
	//поиск индекса числа
	for (int i = 2; i <= x; i++) {
		count++;
		for (int j = 2; j <= sqrt(i); j++) {
			if (i % j == 0) {
				count--;
				break;
			}
		}
	}
	cout << "with position: " << count << endl;

	//провка на простоту индекса числа
	k = sqrt(count);
	for (int i = 2; i <= k; i++) {
		if (count % i == 0) {
			cout << "\nSo its not a Super-prime number" << endl;
			return 0;
		}
	}
	cout << "\nSo it is a Super-prime number!" << endl;
	return 0;
}

void oneControl() {
	unsigned int x1, y1, x2, y2, x3, y3, x4, y4, x5, y5;
	cout << "First point:\n";
	cin >> x1;
	cin >> y1;
	cout << "Second point:\n";
	cin >> x2;
	cin >> y2;
	cout << "Third point:\n";
	cin >> x3;
	cin >> y3;
	cout << "Fourth point:\n";
	cin >> x4;
	cin >> y4;
	cout << "Fifth point:\n";
	cin >> x5;
	cin >> y5;
	int s = ((x1 + x2) * (y2 - y1) + (x2 + x3) * (y3 - y2) + (x3 + x4) * (y4 - y3)
		+ (x4 + x5) * (y5 - y4) + (x5 + x1) * (y1 - y5)) / 2;
	cout << "Square is: " << s << endl;
}