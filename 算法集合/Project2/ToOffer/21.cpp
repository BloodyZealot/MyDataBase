#include<iostream>
#include<stack>

using namespace std;

/*Minstack 类：最小栈的实现
/*使用两个栈，一个栈存储数据一个存储辅助的最小数值*/
template<typename T>
class minstack
{
	typedef typename stack<T>::size_type stack_size;
public :
	minstack() :realnums(), minnums(){};
	/*push操作的特殊之处：
	/*在存入数字栈的同时，判断这个数字是不是新的最小值，
	/*如果是，就在辅助栈存入一个新的最小值，否则存入原来栈的最小值*/
	void push(T value)
	{
		realnums.push(value);
		//注意，minnums可能是空的
		if (minnums.size()==0||value < minnums.top())
			minnums.push(value);
		else
			minnums.push(minnums.top());
	}
	T top()
	{
		return realnums.top();
	}
	/*与普通栈相比，minstack多了一个获取最小数值的操作*/
	T min()
	{
		return minnums.top();
	}
	void pop()
	{
		realnums.pop();
		minnums.pop();
	}
	stack_size size()
	{
		return realnums.size();
	}
private:
	stack<T> realnums;
	stack<T> minnums;
};

int main()
{
	minstack<int> mystack;
	int n,temp;
	char oper;
	cin >> n;
	for (int i = 0; i != n; ++i)
	{
		cin >> oper;
		if (oper == 's')
		{
			cin >> temp;
			mystack.push(temp);
		}
		else
			mystack.pop();
		if (mystack.size())
			cout << mystack.min()<<endl;
		else
			cout << "NULL"<<endl;
	}
	return 0;
}