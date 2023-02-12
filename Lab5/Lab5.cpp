#include <iostream>
#include <istream>
#include <string>
#include <cmath>
#include <string>
#include <sstream>
#include <cstring>
using namespace std;

//Control 1.1
void sumAll(int Arr[], const int n);
void sumInd(int Arr[], const int n);
void sumDiff(int Arr[], const int n);
void minMax(int Arr[], const int n);
void arrayFirst(int Arr[], const int n);


//Control_1.2
void show_array(const int Arr[], const int N);
bool from_min(const int a, const int b);
bool from_max(const int a, const int b);
void bubble_sort(int Arr[], const int N, bool (*compare)(int a, int b));
void sortArr(int Arr[], const int N);

//control 2
int* max_vect(int kc, int a[], int b[]);

//control 3
int trSearch(int* Arr, int n, int key, int& index);

//Control 4
int result(string flag, int a, int b);
int check(const char*[], int);

int main()
{	
	const int n = 10;
	int Arr[n] = { 9,8,-7,6,1,-1,-7,5,4,9 };

	//Control 1.1
	
	//arrayFirst(Arr, n);
	
	//Control 1.2
	
	//sortArr(Arr, n);

	//Control 2

	//int a[] = { 1,2,3,4,5,6,7,2 };
	//int b[] = { 7,6,5,4,3,2,1,3 };
	//int kc = sizeof(a) / sizeof(a[0]); //Количество элементов массива
	//int* c; //Указатель на результирующий массив
	//c = max_vect(kc, a, b); //вызов функции для создания массива
	//for (int i = 0; i < kc; i++) //Вывод результата.
	//	cout << c[i] << " ";
	//cout << endl;
	//delete []c; //Возврат памяти.

	//Control 3

	//int key = 4;
	//int index = 0;
	//trSearch(Arr, n, key, index);
	//cout << "Key index is: " << index << endl; //Key index is: 8
	//trSearch(Arr, n, key, index);
	//cout << "Key index is: " << index << endl; //Key index is: 7

	//control 4

	const char* argc[] = { "result" , "-m", "4", "5" };
	int sz = sizeof(argc) / sizeof(argc[0]);
	check(argc, sz);

	//-------------------------------------------------------------
	return 0;
}
// 4
int check(const char* argc[], int sz) {
	int a, b, x, y;
	if (sz < 4) {
		cout << "Wrong size" << endl;
	}
	else {
		x = strncmp(argc[1], "-a", 2);
		y = strncmp(argc[1], "-m", 2);
		if (x == 0) {
			a = atoi(argc[2]);
			b = atoi(argc[3]);
			cout << "Sum is: " << result(argc[1], a, b) << endl;
		}
		else if (y == 0) {
			a = atoi(argc[2]);
			b = atoi(argc[3]);
			result(argc[2], a, b);
			cout << "Mult is: " << result(argc[1], a, b) << endl;
		}
		else
			cout << "Wrong flag" << endl;		
	}
	return 0;
}

int result(string flag, int a, int b) {
	if (flag == "-a")
		return a + b;
	else if (flag == "-m")
		return a * b;
}

// 3
int trSearch(int* Arr, int n, int key, int& index) {
	for (int i = 0; i < n; i++) {
		if (Arr[i] == key && i != 0) {
			index = i;
			swap(Arr[i], Arr[i - 1]);
		}
	}
	return index;
}
// 2
int* max_vect(int kc, int a[], int b[]) {
	int* c = new int[kc];
	for (int i = 0; i < kc; i++) {
		if (a[i] > b[i]) {
			c[i] = a[i];
		}
		else c[i] = b[i];
	}
	return c;
}

// 1.1
void arrayFirst(int Arr[], const int n) {
	sumAll(Arr, n);
	sumInd(Arr, n);
	sumDiff(Arr, n);
	minMax(Arr, n);
}

void minMax(int Arr[], const int n) {

	int max = Arr[0];
	int imax = 0;
	int min = Arr[0];
	int imin = 0;
	int summ = 0;

	for (int i = 0; i < n; i++)
	{

		if (Arr[i] >= Arr[i + 1] && Arr[i] > max) {
			max = Arr[i];
			imax = i;
		}
		else if (Arr[i] == max) {
			max = Arr[i];
			imax = i;
		}
		else if (Arr[i] < Arr[i + 1] && Arr[i] < min) {
			min = Arr[i];
			imin = i;
		}
		else if (Arr[i] == min) {
			min = Arr[i];
			imin = i;
		}
	}

	if (imin < imax) {
		for (int i = imin + 1; i < imax; i++) {
			summ += Arr[i];
		}
	}
	else if (imin > imax) {
		for (int i = imax + 1; i < imin; i++) {
			summ += Arr[i];
		}
	}
	cout << "Last max item " << max << " has position " << imax << endl;
	cout << "Last min item " << min << " has position " << imin << endl;
	cout << "Sum between items is " << summ << endl;
}

void sumDiff(int Arr[], const int n) {
	int spos = 0;
	int sneg = 0;

	for (int i = 0; i < n; i++)
	{	
		if (Arr[i] > 0)
			spos += Arr[i];
		else if (Arr[i] < 0)
			sneg += Arr[i];
	}
	cout << "Sum of positive items: " << spos << endl;
	cout << "Sum of negative items: " << sneg << endl;
}

void sumInd(int Arr[], const int n) {
	int sodd = 0;
	int seven = 0;
	for (int i = 0; i < n; i++)
	{
		if (i != 0 && i % 2 == 0)
			sodd += Arr[i];
		else if (i % 2 != 0)
			seven += Arr[i];
	}
	cout << "Sum of odd position items: " << sodd << endl;
	cout << "Sum of even position items: " << seven << endl;
}


void sumAll(int Arr[], const int n) {
	int s = 0;
	for (int i = 0; i < n; i++)
	{
		s += Arr[i];
	}
	cout << "Sum of all items: " << s << endl;
}

// 1.2

void sortArr(int Arr[], const int n) {
	bool (*from_f[2])(int, int) = { from_min,from_max };
	int my_choose = 0;
	cout << "1. From min to max\n";
	cout << "2. From max to min\n";
	cin >> my_choose;
	cout << "Array to sort: ";
	show_array(Arr, n);
	bubble_sort(Arr, n, from_f[my_choose - 1]);
	show_array(Arr, n);
}

void show_array(const int Arr[], const int N)
{
	for (int i = 0; i < N; i++)
			cout << Arr[i] << " ";
	cout << "\n";
}

bool from_min(const int a, const int b)
{
	return a > b;
}
bool from_max(const int a, const int b)
{
	return a < b;
}

void bubble_sort(int Arr[], const int N, bool (*compare)(int a, int b))
{
	for (int i = 1; i < N; i++)
	{
		for (int j = 0; j < N - 1; j++)
		{
			if ((*compare)(Arr[j], Arr[j + 1])) swap(Arr[j], Arr[j + 1]);
		}
	}
}
