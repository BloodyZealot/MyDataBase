#include<iostream>
#include<vector>
#include<iomanip>
#include<string>
#include<set>
#include<sstream>
#include<map>

using namespace std;

int main()
{
	int n;
	cin>>n;
	int temp;
	map<int,int> m;
	while(cin>>temp)
	{		
		++m[temp];
	}
	int notin,twin;
	map<int,int>::iterator beg1=m.begin(),beg=++m.begin(),end=m.end();
	for(;beg!=end;++beg,++beg1)
	{
		if(beg->first!=beg1->first+1)
			notin=beg->first-1;
		if(beg->second>1)
			twin=beg->first;
	}
	cout<<notin<<" "<<twin;
	return 0;
}
//639172