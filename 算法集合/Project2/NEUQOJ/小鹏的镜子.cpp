#include<iostream>
#include<string>
#include<vector>
using namespace std;
int original(string str)
{
	if(str.size()%2!=0)
		return str.size();
	string::iterator beg=str.begin(),end=--str.end();
	while(beg<end)
	{
		if(*(beg)!=*(end))
			return str.size();
		++beg;--end;
	}
	return original(string(str,str.size()/2));
}
int main()
{
	int n;
	cin>>n;
	string str;
	for(int i=0;i!=n;++i)
	{
		cin>>str;
		cout<<original(str)<<endl;
	}
	return 0;
}