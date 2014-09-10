#include<iostream>
#include<string>
#include<vector>
#include<typeinfo>

using namespace std;

struct data
{
	float f;
};

int main()
{
	int a;
	data b;
	vector<int> c;
	string d;
	void* p = &c;
	cout << typeid(a).name() << "\n raw " << typeid(a).raw_name() << endl;
	cout << typeid(b).name() << "\n raw " << typeid(b).raw_name() << endl;
	cout << typeid(c).name() << "\n raw " << typeid(c).raw_name() << endl;
	cout << typeid(d).name() << "\n raw " << typeid(d).raw_name() << endl;
	cout << typeid(p).name() << "\n raw " << typeid(p).raw_name() << endl;
	return 0;
}