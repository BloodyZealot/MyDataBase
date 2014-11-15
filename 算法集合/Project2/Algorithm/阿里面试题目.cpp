#include<iostream>
#include<tuple>

using namespace std;

template<typename T>
tuple<bool, T, T, T> findABC(T* starter,T* ender)
{
	if (ender - starter < 3)
		return make_tuple(false, *starter, *starter, *starter);
	T* smaller, *bigger, *finder;
	T cmp;
	for (finder = starter; finder != ender; ++finder)
	{
		smaller = starter, bigger = ender-1;
		while (smaller != bigger)
		{
			cmp = *smaller - *finder + *bigger;
			if (cmp == 0)
			{
				if (smaller == finder)++smaller;
				else if (bigger == finder)--bigger;
				else return make_tuple(true, *smaller, *bigger, *finder);
			}
			else if (cmp < 0) ++smaller;
			else --bigger;
		}
	}
	return make_tuple(false, *starter, *starter, *starter);
}

int main()
{
	int arr[4] = { 0, 1, 7, 8 };
	auto result = findABC(arr, arr + 4);
	return 0;
}