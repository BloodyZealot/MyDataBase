#include<iostream>
#include<algorithm>

using namespace std;

class base
{
public:
	base(){ cout << "a"; }
	~base(){ cout << "base"; }
};

class over :public base
{
public:
	over(){ cout << "b"; }
	~over(){ cout << "over"; }
};

template<typename T>
void fun(T a)
{
	cout << "T" << endl;
}

void fun(int a)
{
	cout << "int" << endl;
}

int main()
{
	int c(0);
	int a;
	a=++c;
	cout << a << c;
	a=c++;
	cout << a<<c;
	return 0;
}