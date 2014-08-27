#include<iostream>
#include<map>
#include<cmath>
using namespace std;

int tail(int n,int i)
{
	int result=1;
	for(int j=0;j!=i;++j)
	{
		result*=n;
		result%=10000;
	}
	return result%1000;
}

int main()
{
	map<int,int> m;
	int n;
	while(cin>>n)
	{
		int i;
		for(i=1;;++i)
			if(pow(n,i)>=1000)
				break;
		n%=1000;
		int temp;
		for(;;++i)
		{
			temp=tail(n,i);
			if(m[temp])
			{
				cout<<i+m[temp]<<endl;
				m.clear();
				break;
			}
			m[temp]=i;
		}
	}
	return 0;
}