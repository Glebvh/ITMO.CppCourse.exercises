#include <iostream>
#include <istream>
#include <string>
#include <cmath>
#include <sstream>
#include <cstring>
#include <fstream>
#include <windows.h>
#include <tuple>
#include <vector>
using namespace std;

//Time

struct Time {

	int hours;
	int	minutes; 
	int seconds;

	Time addTime(const Time& t1) {
		
		Time t;
		int sum;

		t.hours = t1.hours + hours;
		t.minutes = t1.minutes + minutes;
		t.seconds = t1.seconds + seconds;

		sum = t.hours * 3600 + t.minutes * 60 + t.seconds;

		t.hours = sum / 3600;
		t.minutes = (sum % 3600) / 60;
		t.seconds = (sum % 3600) % 60;
		
		return t;
	}

	Time subTime(const Time& t1) {

		Time t;
		int sub, ttemp1, ttemp2;

		ttemp1 = t1.hours * 3600 + t1.minutes * 60 + t1.seconds;
		ttemp2 = hours * 3600 + minutes * 60 + seconds;
		sub = abs(ttemp1 - ttemp2);
		
		t.hours = sub / 3600;
		t.minutes = (sub % 3600) / 60;
		t.seconds = (sub % 3600) % 60;

		return t;
	}
};

Time InputTime()
{
	Time t;
	cout << "Insert hours: ";
	cin >> t.hours;
	cout << "Insert minutes: ";
	cin >> t.minutes;
	if (t.minutes < 0 || t.minutes > 60) {
		cout << "Insert minutes in interval 0-59: ";
		cin >> t.minutes;
	}
	cout << "Insert seconds: ";
	cin >> t.seconds;
	if (t.seconds < 0 || t.seconds > 60) {
		cout << "Insert seconds in interval 0-59: ";
		cin >> t.seconds;
	}

	cout << t.hours * 3600 + t.minutes * 60 + t.seconds << endl;

	return t;
}

void showTime(Time t) {
	cout << "Interval is " << t.hours << " hours "
		<< t.minutes << " minutes "
		<< t.seconds << " seconds." << endl;
}

// Roots Struct

struct Roots
{
	double x1;
	double x2;
	int flag;
};

Roots rootsCalc(int a, int b, int c) {
	Roots r;
	int d;
	d = b * b - 4 * a * c;
	if (d < 0)
		r.flag = -1;
	else if (d == 0) {
		r.x1 = (-b + pow(d, 0.5)) / (2 * a);
		r.x2 = (-b + pow(d, 0.5)) / (2 * a);
		r.flag = 0;
	}
	else if (d > 0) {
		r.x1 = (-b + pow(d, 1.0 / 2)) / (2 * a);
		r.x2 = (-b - pow(d, 0.5)) / (2 * a);
		r.flag = 1;
	}
	return r;
}

//Roots Tuple
using Tuple = tuple<double, double, int>;

Tuple rootsTuple(double a, double b, double c) {
	int d;
	double x1, x2;
	d = b * b - 4 * a * c;
	if (d < 0)
		return make_tuple(0, 0, -1);
	else if (d == 0) {
		x1 = (-b + pow(d, 0.5)) / (2 * a);
		x2 = (-b + pow(d, 0.5)) / (2 * a);
		return make_tuple(x1, x2, 0);
	}
	else if (d > 0) {
		x1 = (-b + pow(d, 1.0 / 2)) / (2 * a);
		x2 = (-b - pow(d, 0.5)) / (2 * a);
		return make_tuple(x1, x2, 1);
	}
}

int main()
{

	double a = 6;
	double b = 5;
	double c = 1;

	//Roots Tuple

	auto t = rootsTuple(a, b, c);
	if (get<2>(t) == -1)
		cout << "No roots" << endl;
	else if (get<2>(t) == 0) {

		cout << "x1 = x2 = " << get<0>(t) << endl;
	}
	else if (get<2>(t) == 1) {
		cout << "x1 = " << get<0>(t) << endl;
		cout << "x2 = " << get<1>(t) << endl;
	}

	//Roots Struct

	Roots r = rootsCalc(a, b, c);

	if (r.flag == -1)
		cout << "No roots" << endl;
	else if (r.flag == 0) {

		cout << "x1 = x2 =" << r.x1 << endl;
	}
	else if (r.flag == 1) {
		cout << "x1 = " << r.x1 << endl;
		cout << "x2 = " << r.x2 << endl;
	}


	//Time
	
	//Time t1 = InputTime();
	//Time t2 = InputTime();
	//Time tsum = t1.addTime(t2);
	//showTime(tsum);
	//Time tsub = t1.subTime(t2);
	//showTime(tsub);

	//-------------------------------------------------------------
	return 0;
}


