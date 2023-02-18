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
		Time t = timeTF(h, m, s);
		hours = t.hours;
		minutes = t.minutes;
		seconds = t.seconds;
	}

	Time timeTF(int h, int m, int s) {
		Time t;
		if (s > 59) {
			m += s / 60;
			s = s % 60;
		}
		if (m > 59) {
			h += m / 60;
			m = m % 60;
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

	t = timeTF(t.hours, t.minutes, t.seconds);

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




