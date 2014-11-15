#include<iostream>
#include<algorithm>
#include<string>

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
	string a("a(b)c"), b("acd");
	return 0;
}