#include <iostream>
#include <string>
#include <cmath>
#include <string>
using namespace std;

//1.1
void oneOne();
//1.2
void oneTwo();
//1.3
void oneThree();
//1.Control
void oneControl();

//---------------------------

// 2.1.1
void twoOneOne();
// 2.1.2
void twoOneTwo();
// 2.2.1
void twoTwoOne();
// 2.2.2
void twoTwoTwo();
// 2.3
void twoThree();
// 2.4
void twoFour();
// 2.Control.1
int prime();
// 2.Control.2
int snils(string);
// 2.Control.3
void coins();
// 2.Control.4
void target();


int main()
{
	//oneOne();
	//oneTwo();
	//oneThree();

	//oneControl();

	//twoOneOne();
	//twoOneTwo();
	//twoTwoOne();
	//twoTwoTwo();
	//twoThree();
	//twoFour();

	//prime();
	//const string snils = "14343817049";
	//snils(snils);
	//coins();
	target();
}

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

// проверка на суперпростое

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

void twoFour() {
	int s = 0;
	int m, k;
	cout << "Enter k & m:\n";
	cin >> k;
	cin >> m;
	if (k < m) {
		for (int i = 1; i <= 100; i++)
		{
			if ((i > k) && (i < m))
				continue;
			s += i;
		}
	}
	else {
		for (int i = 1; i <= 100; i++)
		{
			if ((i > m) && (i < k))
				continue;
			s += i;
		}
	}
	cout << "Sum is:\n" << s << endl;
}

void twoThree() {
	srand(time(NULL));
	int a, b, c;
	int k = 0, n = 10;
	for (int i = 1; i <= n; i++)
	{
		a = rand() % 10 + 1;
		b = rand() % 10 + 1;
		cout << a << " * " << b << " = ";
		cin >> c;
		if (a * b != c)
		{
			k++;
			cout << "Error! ";
			cout << a << " * " << b << " = " << a * b << endl;
		}
	}
	cout << "Count error: " << k << endl;
}

void twoTwoTwo() {
	int a, b, temp;
	cout << "a = "; cin >> a;
	cout << "b = "; cin >> b;
	while (a != b)
	{
		if (a > b)
			a -= b;
		else
			b -= a;
	}
	cout << "NOD = " << a << endl;
}

void twoTwoOne() {
	double x, x1, x2, y;
	cout << "x1 = "; cin >> x1;
	cout << "x2 = "; cin >> x2;
	cout << "\tx\tsin(x)\n";
	x = x1;
	do
	{
		y = sin(x);
		cout << "\t" << x << "\t" << y << endl;
		x = x + 0.01;
	} while (x <= x2);
}

void twoOneTwo() {
	system("chcp 1251");
	char op;
	cout << "Сделай свой выбор, собери авто свой мечты: ";
	cin >> op;
	switch (op)
	{
	case 'S':
		cout << "Радио играть должно\n";
	case 'V':
		cout << "Кондиционер хочу\n";
	default:
		cout << "Колеса круглые\n";
		cout << "Мощный двигатель\n";
	}
}

void twoOneOne() {
	int x, y;
	cout << "Point:\n";
	cin >> x;
	cin >> y;
	if (x * x + y * y < 9 && y > 0)
		cout << "Inside" << endl;
	else if (x * x + y * y > 9 || y < 0)
		cout << "Outside" << endl;
	else
		cout << "Border" << endl;
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

void oneOne() {
	string name;
	cout << "What is your name? ";
	getline(cin, name);
	cout << "Hello, " << name << "!\n";
}

void oneTwo() {
	system("chcp 1251");
	cout.precision(3);
	string name;
	double a, b;
	cout << "Введите a и b:\n";
	cin >> a; // ввод с клавиатуры значения a
	cin >> name;
	cin >> b; // ввод с клавиатуры значения b
	double x = a / b; // вычисление значения x
	cout << "\nx = " << x << endl; //вывод результата на экран
	cout << sizeof(a / b) << "\n" << ends << sizeof(x) << endl;
	cout << "Привет, " << name << "!\n";
}

void oneThree() {
	system("chcp 1251");
	cout.precision(3);
	double x;
	cout << "enter side:\n";
	cin >> x;
	double y = x * 3;
	double s = sqrt(y * pow((y - x), 3));
	cout << "Сторона " << "Площадь\n" << endl;
	cout << x << "\t" << s << endl;
}
