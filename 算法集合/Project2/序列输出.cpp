#include<iostream>
#include<map>
#include<vector>
#include<string>
using namespace std;
int gcd(int i,int j)
{
	int temp;
	while(i!=0)
	{
		temp=i;
		i=j%i;
		j=temp;
	}
	return j;
}
inline map<double,pair<int,int> > fraction(int num)
{
	map<double,pair<int,int> > m;
	for(int j=2;j<=num;++j)
		for(int i=1;i!=j;++i)
		{
			if(gcd(i,j)==1)
			{
			m.insert(make_pair(double(i)/j,make_pair(i,j)));
			}
		}
	return m;
}
int main()
{
	int n;
	cin>>n;
	int num;
	map<double,pair<int,int> > m;
	map<double,pair<int,int> >::iterator beg,end;
	for(int i=0;i!=n;++i)
	{
		cin>>num;
		m=fraction(num);
		for(beg=m.begin(),end=--m.end();beg!=end;++beg)
		{
			cout<<beg->second.first<<"/"<<beg->second.second<<",";
		}
		cout<<beg->second.first<<"/"<<beg->second.second<<endl;
	}
	return 0;
}