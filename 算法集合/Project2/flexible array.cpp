#include<iostream>

using namespace std;

struct stru
{
	int v;
	int arr[];
};

int main()
{
	stru *s = static_cast<stru*>(malloc(sizeof(int) * 100));
	for (int i = 0; i != 100; ++i)
		s[i].v = i;
	for (int i = 0; i != 99;++i)
	cout << s[0].arr[i]<<' ';
	return 0;
}