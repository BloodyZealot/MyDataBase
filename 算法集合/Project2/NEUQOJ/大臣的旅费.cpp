#include<iostream>
#include<list>
#include<map>
#include<vector>
using namespace std;

int main()
{
	int **a,*count,n,c,l,d;
	cin>>n;
	a=new int*[n];
	count=new int[n];
	for(int i=0;i!=n;++i)
	{
		a[i]=new int[n];
		count[i]=0;
		for(int j=0;j!=n;++j)
			a[i][j]=0;
	}
	for(int i=1;i!=n;++i)
	{
		cin>>c>>l>>d;
		a[c-1][l-1]=d;
		a[l-1][c-1]=d;
		count[c-1]++;
		count[l-1]++;
	}
	int start;
	list<int> v;
	map<int,int>  route;
	for(int i=0;i!=n;++i)
		if(count[i]==1)
			start=i;
	route.insert(make_pair(start,0));
	for(int i=0;i!=n;++i)
	{
			if(a[start][i]!=0&&route[i]==0)
			{
				route[i]=route[start]+a[start][i];
				v.push_back(i);
			}
	}
	while(v.size()!=0)
	{
		start=*v.begin();
		v.pop_front();
		for(int i=0;i!=n;++i)
		{
			if(a[start][i]!=0&&route[i]==0)
				route[i]=route[start]+a[start][i];
		}
	}
	int max=0;
	map<int,int>::iterator beg=route.begin(),end=route.end();
	for(;beg!=end;++beg)
		if(max<beg->second)
			max=beg->second;
	cout<<(max+21)*max/2;
	return 0;
}