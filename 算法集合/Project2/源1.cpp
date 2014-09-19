#include<iostream>
#include<string>
#include<vector>
#include<typeinfo>

using namespace std;

struct null
{
};

class number
{
public:
	number() :v(0){};
	number(int n) :v(n){};
	const number operator+(const number& n)
	{
		return number(v + n.v);
	}
	friend ostream& operator<<(ostream& out, const number& n);
private:
	int v;
};

ostream& operator<<(ostream& out, const number& n)
{
	out << n.v;
	return out;
}

int main()
{
	cout << typeid(int).name() << endl;
	cout << typeid(void *).name() << endl;
	cout << typeid(1.0 + 3).name() << endl;
	cout << typeid(number).name() << endl;
	cout << typeid(null).name() << endl;
	return 0;
}