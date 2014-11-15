#include<iostream>
#include<string>

using namespace std;

template<char split,typename T,size_t size>
void printarray(T (&arr)[size])
{
	for (int i = 0; i != size; ++i)
		cout << arr[i] << split;
	cout << endl;
}

template<size_t size,typename T1,typename T2>
void outputarray(T1(&arr)[size],T2 split)
{
	for (int i = 0; i != size; ++i)
		cout << arr[i] << split;
	cout << endl;
}

template<size_t size,typename T1>
void outputarray(T1 (&arr)[size], string split)
{
	for (int i = 0; i != size; ++i)
		cout << arr[i] << split;
	cout << endl;
}

int main()
{
	int arr[10];
	for (int i = 0; i != 10; ++i)
		arr[i] = i;
	printarray<' '>(arr);
	outputarray(arr, ' ');
	outputarray(arr, 1.01);
	outputarray(arr, string("\n"));
	return 0;
}