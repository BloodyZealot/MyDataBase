#include<iostream>

using namespace std;

int n,k;


void makenext(int* a)
{
	++a[0];
	for(int i=0;i!=n;++i)
		if(a[i]==k)
		{
			++a[i+1];
			a[i]=0;
		}
	for(int i=0,j=0;i<=n;++i)
		if(a[i]==0)
			++j;
		else
		{
			if(j>1)
			{
				for(int k=2;j-k>=0;k+=2)
					a[i-k]=1;
			}
			j=0;
		}
}

int main()
{
	int num=0;
	cin>>n>>k;
	int *a=new int[n];
	for(int i=0;i!=n;++i)
		if(i%2==0)
			a[i]=1;
		else
			a[i]=0;
	while(a[n]!=k)
	{
		num++;
		makenext(a);
	}
	cout<<num;
	return 0;
}