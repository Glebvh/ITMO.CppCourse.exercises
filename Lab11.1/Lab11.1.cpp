#include <iostream>
using namespace std;


class Time {

public:

	Time operator+ (const Time&) const;
	Time operator- (const Time&) const;

	Time() {
		hours = 0;
		minutes = 0;
		seconds = 0;
	}

	Time(int h, int m, int s)
	{
		Time t = timeTransform(h, m, s);
		hours = t.hours;
		minutes = t.minutes;
		seconds = t.seconds;
	}

	Time(int timeInSeconds) {
		hours = timeInSeconds / 3600;
		minutes = (timeInSeconds % 3600) / 60;
		seconds = (timeInSeconds % 3600) % 60;
	}

	Time timeTransform(int& h, int& m, int& s) {
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

Time Time::operator+ (const Time& t1) const {

	Time t;

	t.hours = t1.hours + hours;
	t.minutes = t1.minutes + minutes;
	t.seconds = t1.seconds + seconds;

	t.timeTransform(t.hours, t.minutes, t.seconds);

	return t;
}

Time Time::operator- (const Time& t1) const {

	int t1sec = t1.seconds + t1.minutes * 60 + t1.hours * 3600;
	int sec = seconds + minutes * 60 + hours * 3600;
	int tsec;

	Time t;
	if (sec >= t1sec) {
		tsec = sec - t1sec;
		t.hours = tsec / 3600;
		t.minutes = (tsec % 3600) / 60;
		t.seconds = (tsec % 3600) % 60;
	}
	else {
		cout << "Wrong subtraction\n";
	}

	return t;
}

int main()
{
	cout << "Time 1:\n";
	Time time1(1, 70, 70);
	time1.showTime();

	cout << "Time 2:\n";
	Time time2(1, 40, 50);
	time2.showTime();

	cout << "Time 3 = Time 1 + Time 2:\n";
	Time time3 = time1 + time2;
	time3.showTime();

	cout << "Time 3 =  Time 1 - Time 2:\n";
	time3 = time1 - time2;
	time3.showTime();

	cout << "Time 4 = 900 sec:\n";
	Time time4(900);
	time4.showTime();

	cout << "Time 3 = Time 1 + Time 4:\n";
	time3 = time1 + time4;
	time3.showTime();

	return 0;
}