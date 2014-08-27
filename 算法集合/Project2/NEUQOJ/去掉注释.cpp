#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
	string s;
	int pos;
	while(getline(cin,s))
	{
		if((pos=s.find("//"))==string::npos)
			cout<<s<<endl;
		else
		{
			for(int i=0;i!=pos;++i)
				cout<<s[i];
			if(pos!=0)
				cout<<endl;
		}
	}
	return 0;
}