#include <iostream>
#include <istream>
#include <string>
#include <cmath>
#include <string>
#include <sstream>
#include <cstring>
#include <fstream>
#include <nlohmann/json.hpp>
using namespace std;

using json = nlohmann::json;

//Control 1
void poemToFile();

//Control 2
void sortArr(int Arr[], const int n);

int main()
{
	// Control 1
	//poemToFile();

	// Control 2
	const int N = 10;
	int a[N] = { 1, 25, 6, 32, 43, 5, 96, 23, 4, 55 };
	//ofstream fout("Array.txt");
	//fout << "Original:\n";
	//for (int i = 0; i < N; i++) {
	//	fout << a[i] << "\t";
	//}
	//fout << "\nSorted:\n";
	//sortArr(a, N);
	//for (int i = 0; i < N; i++) {
	//	fout << a[i] << "\t";
	//}
	//fout.close();

	//Control 3 json
	// Array to JSON
	json j;
	ofstream o("Arr1.json");
	for (auto i = 0; i < N; i++) {
		j[i] = a[i];
	}
	o << j;
	o.close();
	
	// Array from JSON
	ifstream i("Arr1.json");
	json arrJ;
	i >> arrJ;

	// Array from JSON to int
	int arrOrig[N];
	for (auto i = 0; i < N; i++) {
		arrOrig[i] = arrJ[i];
	}

	// Sorted array to another JSON
	sortArr(arrOrig, N);
	json arrSorted;
	ofstream o2("Arr2.json");
	for (auto i = 0; i < N; i++) {
		arrSorted[i] = arrOrig[i];
	}
	o2 << arrSorted;
	o2.close();

	//-------------------------------------------------------------
	return 0;
}

//Control 2
void sortArr(int Arr[], const int n) {
	int min = 0;
	int buf = 0;
	for (int i = 0; i < n; i++)
	{
		min = i;
		for (int j = i + 1; j < n; j++)
			min = (Arr[j] < Arr[min]) ? j : min;
		if (i != min)
		{
			buf = Arr[i];
			Arr[i] = Arr[min];
			Arr[min] = buf;
		}
	}
}

//Control 1
void poemToFile() {
	const int size = 255;
	char buffer[size];
	ofstream fout("poem.txt");
	cout << "Enter poem:\n";
	cin.get(buffer, size, '&');
	fout << buffer << endl;
	fout.close();
}
