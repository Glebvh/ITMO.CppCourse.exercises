#include <iostream>
using namespace std;


class Time {

public:

	Time addTime(const Time& t1);

	Time(){
		hours = 0;
		minutes = 0;
		seconds = 0;
	}

	Time(int h, int m, int s)
	{
		if (s > 59) {
			m += s / 60;
			s = s % 60;
		}
		if (m > 59) {
			h += m / 60;
			m = m % 60;
		}
		hours = h;
		minutes = m;
		seconds = s;
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
	Time* time1 = new Time (1, 70, 70);
	time1->showTime();

	Time* time2 = new Time(1, 40, 50);
	time2->showTime();

	Time time3 = time2->addTime(*time1);
	time3.showTime();

	delete time1;
	delete time2;

	return 0;
}




