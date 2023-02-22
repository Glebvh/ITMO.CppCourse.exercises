#include <iostream>
using namespace std;

class TimeError { 
public: 
	TimeError() : message("Enter time in range 0-59") { 
	} 
	void printMessage() const { 
		cout << message << endl; 
	} 
private: string message; 
};


class Time {

public:

	Time addTime(const Time& t1);

	Time() {
		hours = 0;
		minutes = 0;
		seconds = 0;
	}

	Time(int h, int m, int s)
	{
		Time t = timeTF(h, m, s);
		hours = t.hours;
		minutes = t.minutes;
		seconds = t.seconds;
	}

	Time timeTF(int h, int m, int s) {
		Time t;
		if (s > 59) {
			throw TimeError();
		}
		if (m > 59) {
			throw TimeError();
		}
		t.hours = h;
		t.minutes = m;
		t.seconds = s;

		return t;
	}

	void showTime() {
		cout << hours << ":" << minutes << ":" << seconds << endl;
	}

private:

	int hours;
	int	minutes;
	int seconds;
};

Time Time::addTime(const Time& t1) {

	Time t;

	t.hours = t1.hours + hours;
	t.minutes = t1.minutes + minutes;
	t.seconds = t1.seconds + seconds;

	if (t.seconds > 59) {
		t.minutes += t.seconds / 60;
		t.seconds = t.seconds % 60;
	}
	if (t.minutes > 59) {
		t.hours += t.minutes / 60;
		t.minutes = t.minutes % 60;
	}

	return t;
}


int main()
{
	try {
		Time* time1 = new Time(1, 40, 50);
		time1->showTime();

		Time* time2 = new Time(1, 40, 50);
		time2->showTime();
		Time time3 = time2->addTime(*time1);
		time3.showTime();

		delete time1;
		delete time2;
	}
	catch (TimeError error) {
		cout << "Error: ";
		error.printMessage();
		return 1;
	}

	return 0;
}