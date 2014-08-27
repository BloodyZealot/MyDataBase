#include<iostream>
#include<cmath>
#include<iomanip>
#include<set>
#include<algorithm>
using namespace std;

int numberlist(int i)
{
	int len=1;
	while(i!=1)
	{
		if(i%2==0)
			i/=2;
		else
			i=i*3+1;
		len++;
	}
	return len;
}

int main()
{
	int i,j;int maxlen=0,temp;
	while(cin>>i>>j)
	{
	maxlen=0;
	for(;i<=j;++i)
	{
		temp=numberlist(i);
		if(maxlen<temp)
			maxlen=temp;
	}
	cout<<maxlen<<endl;
	}
	return 0;
}