#include<iostream>
#include<vector>
#include<climits>

using namespace std;

template<typename T>
class SegTree
{
	struct segnode
	{
		T max;
		T min;
		T sum;
	};
public:
	SegTree(size_t n) :len(n)
	{
		size_t size = 1;
		while (size < n)size *= 2;
		datas.resize(size * 2 - 1);
		size *= 2 -= 1;
		for (int i = 0; i != size; ++i)
			datas[i]=ULONG_MAX;
	}
	SegTree(size_t n, T* nums) :len(n)
	{
		size_t size = 1;
		while (size < n)size *= 2;
		datas.resize(size * 2 - 1);
		for (int i = size,j=0; j != n; ++j,++i)
		{
			datas[i] = T[]
		}
	}
	T find_max(size_t starter, size_t ender)
	{

	}
	T find_min(size_t starter, size_t ender)
	{

	}
	T sum_of(size_t starter, size_t ender)
	{

	}
	void update(size_t pos, T value)
	{

	}
private:
	size_t len;
	vector<segnode> datas;
};