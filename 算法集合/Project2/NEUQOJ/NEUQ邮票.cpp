#include<iostream>
#include<cmath>

using namespace std;

int main()
{
	long long n,m,temp1,temp2;
	while(cin>>n>>m)
	{
		long long max=(sqrt(1+8*m)-1)/2;
		for(long long i=max;i!=0;--i)
		{
			temp1=m/i-i/2;temp2=m/i+i/2;
			if(temp2>n)
				break;
			if(i%2==1)
			{
				if(m%i==0)
				{
					cout<<"["<<temp1<<","<<temp2<<"]"<<endl;
				}
			}
			else
			{
				if(m*2%i==0&&m%i!=0)
				{
					cout<<"["<<temp1+1<<","<<temp2<<"]"<<endl;
				}
			}
		}
	}
	return 0;
}