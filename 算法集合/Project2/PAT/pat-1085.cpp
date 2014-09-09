#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int  main()
{
	long long n,p;
	long long m;
	long long result=0;
	vector<long long> seq;
	cin>>n>>p;
	seq.resize(n);
	for(int i=0;i!=n;++i)
		cin>>seq[i];
	sort(seq.begin(),seq.end());
	for(int i=n-1,j=n-1;i!=-1&&j!=-1;--i)
	{
		m=seq[i]/p;
		if(seq[i]%p!=0)
			++m;
		for(;j!=-1;--j)
		{
			if(seq[j]<m)
			{
				if(i-j>result)
					result=i-j;
				break;
			}
		}
		if(j==-1)
			if(i-j>result)
				result=i-j;
	}
	cout<<result;
	return 0;
}