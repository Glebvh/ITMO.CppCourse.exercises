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

int main()
{
	Time t1 = InputTime();
	Time t2 = InputTime();
	Time tsum = t1.addTime(t2);
	showTime(tsum);
	Time tsub = t1.subTime(t2);
	showTime(tsub);

	//-------------------------------------------------------------
	return 0;
}


