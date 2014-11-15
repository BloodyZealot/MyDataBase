#include<iostream>
#include<vector>
#include<thread>
#include<mutex>

using namespace std;

mutex SumMutex;
long long result;

template<typename SumT, typename T>
void Sum(T begptr, T endptr)
{
	SumT sum(0);
	for (; begptr != endptr; ++begptr)
		sum += *begptr;
	lock_guard<mutex> guard(SumMutex);
	result += sum;
}

int main()
{
	vector<int> v(10000);
	for (int i = 0; i != 10000; ++i)
		v[i] = i;
	function<void(vector<int>::iterator, vector<int>::iterator)> 
								fun(Sum<long long, vector<int>::iterator>);
	thread t1(fun, v.begin(), v.begin() + 5000);
	thread t2(fun, v.begin() + 5000, v.end());
	t1.join();
	t2.join();
	cout << (result == (0 + 9999) * 5000) << endl << result << endl;
	return 0;
}