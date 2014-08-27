#include<iostream>
#include<string>
#include<sstream>
#include<ctime>
using namespace std;

template<typename T>
void quicksort(T a, T b)
{
	size_t size = b - a;
	if (size <= 1)
		return;
	swap(*a, *(a + size / 2));
	T start = a + 1, end = b - 1;
	while (start < end)
	{
		while (*start <= *a&&start < end)
			start++;
		swap(*start, *end);
		while (*end>=*a&&start < end)
			--end;
		swap(*start, *end);
	}
	if (*a>*start)
		swap(*a, *start);
	else
		swap(*a, *--start);
	quicksort(a, start);
	quicksort(start + 1, b);
}

template<typename T>
void stablesort(T start, T end)
{
	T a = start, b = end;
	if (++a == b--)
		return;
	while (a < b)
	{
		while (*a <= *start&&a<b)
			++a;
		swap(*a, *b);
		while (*b>=*start&&a < b)
			--b;
		swap(*a, *b);
	}
	if (*a>*start)
		swap(*--a, *start);
	else
		swap(*a, *start);
	if (a != start)
		stablesort(start, a);
	if (++a != end)
		stablesort(a, end);
}

int main()
{
	const size_t size = 1E6;
	int timer;
	int* test=new int[size];
	for (int i = 0; i != size; ++i)
	{
		test[i] = rand();
	}
	timer = clock();
	cout << "start!" << endl;
	stablesort(test, test + size);
	cout <<	clock()- timer<< endl;
	for (int i = 1; i !=size; ++i)
	{
		if (test[i] < test[i - 1])
			cout << "BOOM!" << endl;
	}
	return 0;
}