#include <iostream>
#include <string>
#include <cmath>
#include <string>
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

//3.
string privet(string);

int main()
{
	//oneControl();
	
	//prime();
	//const string snils = "14343817049";
	//snils(snils);
	//coins();
	//target();

	//// 3.
	//string name;
	//cin >> name;
	//string nameOut = privet(name);
	//cout << nameOut;
}

//string privet(string name)
//{
//	string str = name + ", " + "hello!\n";
//	return str;
//}

// мишень

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

// монеты

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

// снилс

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

// суперпростое

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