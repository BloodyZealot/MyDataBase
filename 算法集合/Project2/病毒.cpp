#include<iostream>
#include<iomanip>
#include<sstream>
#include<cmath>
#include<algorithm>
#include<set>
#include<string>
#include<vector>
using namespace std;


int main()
{
	vector<string> ver;
	vector<string> web;
	string tstr;
	int n,total=0;
	cin>>n;
	for(int i=0;i!=n;++i)
	{
		cin>>tstr;
		ver.push_back(tstr);
	}
	cin>>n;
	for(int i=0;i!=n;++i)
	{
		cin>>tstr;
		web.push_back(tstr);
	}
	int vers=ver.size();
	vector<int> webhavevar;
	for(int i=0;i!=n;++i)
	{
		webhavevar.clear();
		for(int j=0;j!=vers;++j)
			if(web[i].find(ver[j])!=string::npos)
				webhavevar.push_back(j+1);
		if(webhavevar.size())
		{
			cout<<"web "<<i+1<<":";
			for(int k=0,l=webhavevar.size();k!=l;++k)
				cout<<" "<<webhavevar[k];
			cout<<endl;
			total++;
		}
	}
	cout<<"total: "<<total;
	return 0;
}