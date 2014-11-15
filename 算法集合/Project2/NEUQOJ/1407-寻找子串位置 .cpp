#include<iostream>
#include<string>

using namespace std;

int main()
{
	string a, b;
	cin >> a >> b;
	cout << a.find_first_of(b) + 1;
	return 0;
}