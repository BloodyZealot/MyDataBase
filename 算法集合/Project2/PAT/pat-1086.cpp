#include<iostream>
#include<string>
#include<stack>
#include<deque>
#include<algorithm>

using namespace std;

int in[36],pre[36];
deque<int> output;

void rebulidtree(int start,int end,int start2,int end2)
{
	if(start==end)
		return;
	else
	{
		int parent=pre[start];
		int index;
		for(int i=start2;i!=end2;++i)
			if(in[i]==parent)
			{
				index=i;
				break;
			}
			int size=index-start2;
			rebulidtree(start+1,start+size+1,start2,index);
			rebulidtree(start+size+1,end,index+1,end2);
			output.push_back(parent);
	}
}

int main()
{
	int n;
	int temp=0;
	int temp2=0;
	stack<int> st;
	string oper;
	cin>>n;
	n*=2;
	for(int i=0;i!=n;++i)
	{
		cin>>oper;
		if(oper=="Push")
		{
			cin>>pre[temp];
			st.push(pre[temp++]);
		}
		else
		{
			in[temp2++]=st.top();
			st.pop();
		}
	}
	rebulidtree(0,temp,0,temp);
	cout<<output.front();
	output.pop_front();
	while(output.size())
	{
		cout<<' '<<output.front();
		output.pop_front();
	}
	return 0;
}