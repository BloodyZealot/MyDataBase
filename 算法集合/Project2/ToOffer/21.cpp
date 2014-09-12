#include<iostream>
#include<stack>

using namespace std;

/*Minstack �ࣺ��Сջ��ʵ��
/*ʹ������ջ��һ��ջ�洢����һ���洢��������С��ֵ*/
template<typename T>
class minstack
{
	typedef typename stack<T>::size_type stack_size;
public :
	minstack() :realnums(), minnums(){};
	/*push����������֮����
	/*�ڴ�������ջ��ͬʱ���ж���������ǲ����µ���Сֵ��
	/*����ǣ����ڸ���ջ����һ���µ���Сֵ���������ԭ��ջ����Сֵ*/
	void push(T value)
	{
		realnums.push(value);
		//ע�⣬minnums�����ǿյ�
		if (minnums.size()==0||value < minnums.top())
			minnums.push(value);
		else
			minnums.push(minnums.top());
	}
	T top()
	{
		return realnums.top();
	}
	/*����ͨջ��ȣ�minstack����һ����ȡ��С��ֵ�Ĳ���*/
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