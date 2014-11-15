#include<iostream>

using namespace std;

namespace MyNameSpace
{
	class Point
	{
	public:
		friend ostream& operator<<(ostream& out, const Point& p);
		Point() :x(0), y(0){}
		Point(int ix, int iy) :x(ix), y(iy){}
		Point(Point& p) :x(p.x), y(p.y){}
		const Point& operator=(const Point& p);
		const Point operator++(int);
		Point& operator++();
		Point& operator+=(const Point& p);
		const Point operator+(const Point& p);
	private:
		int x, y;
	};

	const Point& Point::operator=(const Point& p)
	{
		this->x = p.x;
		this->y = p.y;
		return *this;
	}

	const Point Point::operator++(int)
	{
		Point temp(*this);
		++this->x; ++this->y;
		return temp;
	}
	Point& Point::operator++()
	{
		++this->x; ++this->y;
		return *this;
	}

	Point& Point::operator+=(const Point& p)
	{
		this->x += p.x;
		this->y += p.y;
		return *this;
	}
	const Point Point::operator+(const Point& p)
	{
		return Point(this->x + p.x, this->y + p.y);
	}

	ostream& operator<<(ostream& out, const Point& p)
	{
		out << "X:" << p.x << " Y:" << p.y;
		return out;
	}
}

using MyNameSpace::Point;

int main()
{
	Point p1, p2(0, 0);
	Point p3(p2);
	cout << p1 << ' ' << p2 << ' ' << p3 << endl;
	cout << p1++ << ' ' << ++p2 << endl;
	p3 = p2 += p1;
	cout << p2 << ' ' << p3 << endl;
	cout << p2 + p3 << endl;
	return 0;
}