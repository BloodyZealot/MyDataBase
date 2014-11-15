#include<iostream>

using namespace std;

union IntOrDouble
{
	long long integer;
	double floater;
};

IntOrDouble function(bool flag)
{
	IntOrDouble temp;
	if (flag)
		temp.integer = 102400;
	else
		temp.floater = 2048.123;
	return temp;
}

int main()
{
	IntOrDouble temp;
	temp = function(true);
	cout << temp.integer << endl << temp.floater << endl;
	temp = function(false);
	cout << temp.floater << endl << temp.integer << endl;
	return 0;
}