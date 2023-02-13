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

	void addTime(const Time& t1, const Time& t2) {
		int sum;
		Time t;
		t.hours = t1.hours + t2.hours;
		t.minutes = t1.minutes + t2.minutes;
		t.seconds = t1.seconds + t2.seconds;

		sum = t.hours * 3600 + t.minutes * 60 + t.seconds;

		cout << "Sum of interval is " << sum / 3600 << " hours "
			<< (sum % 3600) / 60 << " minutes "
			<< ((sum % 3600) % 60) << " seconds." << endl;
	}

	void subTime(const Time& t1, const Time& t2) {

		int sub, ttemp1, ttemp2;

		ttemp1 = t1.hours * 3600 + t1.minutes * 60 + t1.seconds;
		ttemp2 = t2.hours * 3600 + t2.minutes * 60 + t2.seconds;

		sub = abs(ttemp1 - ttemp2);
		
		cout << "Sub of interval is " << sub / 3600 << " hours "
			<< (sub % 3600) / 60 << " minutes "
			<< ((sub % 3600) % 60) << " seconds." << endl;
	
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

int main()
{
	Time t1 = InputTime();
	Time t2 = InputTime();
	t1.addTime(t1, t2);
	t2.subTime(t1, t2);

	//-------------------------------------------------------------
	return 0;
}


