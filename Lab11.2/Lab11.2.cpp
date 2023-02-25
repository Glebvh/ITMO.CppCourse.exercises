#include <iostream>
using namespace std;

#include <string>
#include <vector>
#include <algorithm> // для алгоритма сортировки


class Point
{
private:

	int x;
	float y;

public:

	Point(int x, int y) : x(x), y(y) { }

	double getDist() const {
		return pow((x * x + y * y), 0.5);
	}

	friend ostream& operator<< (std::ostream& out, const Point& p);
	friend bool operator< (const Point& p1, const Point& p2);
};

ostream& operator<< (ostream& out, const Point& p) {
	out << p.x << ", " << p.y;
	return out;
}

bool operator<(const Point& p1, const Point& p2) {
	return p1.getDist() < p2.getDist();
}

int main()
{
	std::vector<Point> v;
	v.push_back(Point(1, 2));
	v.push_back(Point(10, 12));
	v.push_back(Point(21, 7));
	v.push_back(Point(4, 8));
	std::sort(v.begin(), v.end()); // требуется перегрузка оператора < для // класса Point
	for (auto& point : v)
		std::cout << point << '\n'; // требуется перегрузка оператора << для // класса Point
	return 0;
}