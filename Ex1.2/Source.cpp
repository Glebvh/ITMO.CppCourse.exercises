#include <iostream>
using namespace std;
int main()
{
	system("chcp 1251");
	double a, b; 
	cout << "������� a � b:\n";
	cin >> a; // ���� � ���������� �������� a
	cin >> b; // ���� � ���������� �������� b
	int x = a / b; // ���������� �������� x
	cout << "\nx = " << x << endl; //����� ���������� �� �����
	cout << sizeof(a / b) << ends << sizeof(x) << endl;
	return 0;
}