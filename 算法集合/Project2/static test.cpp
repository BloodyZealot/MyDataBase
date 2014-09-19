#include <stdio.h>
#include<iostream>

using namespace std;

class a
{
public:
	a():v(0){};
	a(int a) :v(a){};
	~a(){ cout << "~a" << endl; }
	const a& operator=(int v1)
	{
		v = v1;
		return *this;
	}
	int v;
};

int main()
{
		for (int i = 0; i != 10; ++i)
		{
			static a b(10);
			cout << b.v   << endl;
			b = i;
		}
	return 0;
}