#include<iostream>
#include<iomanip>
#include<sstream>
#include<cmath>
#include<algorithm>
#include<set>
#include<string>
using namespace std;


int main()
{
	string s;
	stringstream ss;
	int temp;
	while(cin>>s)
	{
		replace(s.begin(),s.end(),'.',' ');
		ss<<s;
		while(ss>>temp)
			if(temp>255||temp<0)
				break;
		if(ss.eof())
			cout<<"Y";
		else
			cout<<"N";
		cout<<endl;
		ss.str("");
		ss.clear();
	}
	return 0;
}