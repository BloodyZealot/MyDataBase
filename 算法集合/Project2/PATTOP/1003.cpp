#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

template<typename T>
class LineTree {
public:
	T calFromStartTo(size_t end);
	T calToEndFrom(size_t start);
	T calBetween(size_t start, size_t end);
	T get(size_t index);
	void update(size_t index, T value);

private:
	T calculate(size_t startLevel, size_t levelIndex, size_t start, size_t end);
	//实际数据长度
	size_t actualSize;
	//修正后的长度应该大于actualSize的且是2的幂
	size_t fixedSize;
	size_t maxDeep;
	vector<T> values;


public:
	LineTree(size_t size) {
		actualSize = size;
		maxDeep = size_t(log(size) / log(2));
		if ((log(size) / log(2)) - int(log(size) / log(2)) != 0)
		{
			//不为2的整数时候，加一层才可以容纳所有数据
			maxDeep += 1;
		}
		fixedSize = pow(2, maxDeep);
		values.resize(fixedSize * 2 - 1);
	}

};

template<typename T>
T LineTree<T>::calFromStartTo(size_t end) {
	return calculate(maxDeep, 0, 0, end);
}

template<typename T>
T LineTree<T>::calToEndFrom(size_t start) {
	return calculate(maxDeep, 0, start, fixedSize + 1);
}

template<typename T>
T LineTree<T>::calBetween(size_t start, size_t end) {
	return calculate(maxDeep, 0, start, end);
}

template<typename T>
T LineTree<T>::get(size_t index) {
	return values[index + fixedSize - 1];
}

template<typename T>
void LineTree<T>::update(size_t index, T value) {
	T diff = value - values[index + fixedSize - 1];
	size_t updateIndex = index + fixedSize - 1;
	values[updateIndex] = value;
	while (updateIndex != 0)
	{
		values[(updateIndex -= 1) /= 2] += diff;
	}
}

template<typename T>
T LineTree<T>::calculate(size_t startLevel, size_t levelIndex, size_t start, size_t end)
{
	size_t jumpSize = pow(2, startLevel);
	size_t minIndex = jumpSize*levelIndex;
	size_t maxIndex = minIndex + jumpSize;
	if (start <= minIndex&&end > maxIndex)
	{
		size_t valueIndex = pow(2, maxDeep - startLevel) + levelIndex;
		return values[valueIndex];
	}
	size_t medium = (minIndex + maxIndex) / 2 + 1;
	if (end <= minIndex)
		return calculate(startLevel - 1, levelIndex * 2 - 1, start, end);
	if (start > minIndex)
		return calculate(startLevel - 1, levelIndex * 2, start, end);
	return calculate(startLevel - 1, levelIndex * 2 - 1, start, end) + calculate(startLevel - 1, levelIndex * 2, start, end);
}


int main() {
	int size;
	int temp;
	cin >> size;
	LineTree<int> lineTree(size);
	for (int i = 0; i != size; ++i)
	{
		cin >> temp;
		lineTree.update(temp-1, 1);
		cout << lineTree.calFromStartTo(size) << endl;
	}
	return 0;
}