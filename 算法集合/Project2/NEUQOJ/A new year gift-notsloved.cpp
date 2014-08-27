#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	int n,m,temp,result=0;
	vector<int> s;
	vector<int>::iterator beg,end;
	while(cin>>n)
	{
		if(n==0)
			return 0;
		for(int i=0;i!=n;++i)
		{
			cin>>temp;
			s.push_back(temp);
		}
		sort(s.rbegin(),s.rend());
		int size=s.size();
		for(cin>>m;size>=m;++result)
		{
			beg=s.begin(),end=s.end();
			temp=s[m-1];
			for(int i=0;i!=m;++i)
			{
				if(*beg-=temp==0)
					--size;
			}
			sort(s.rbegin(),s.rend());
		}
		cout<<result<<endl;
		s.clear();result=0;
	}
}