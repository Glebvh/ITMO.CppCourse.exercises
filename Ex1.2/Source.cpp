#include <iostream>
using namespace std;
int main()
{
	system("chcp 1251");
	double a, b; 
	cout << "¬ведите a и b:\n";
	cin >> a; // ввод с клавиатуры значени€ a
	cin >> b; // ввод с клавиатуры значени€ b
	int x = a / b; // вычисление значени€ x
	cout << "\nx = " << x << endl; //вывод результата на экран
	cout << sizeof(a / b) << ends << sizeof(x) << endl;
	return 0;
}