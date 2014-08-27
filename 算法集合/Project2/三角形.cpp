#include<iostream>
using namespace std;

int **a,**b;

int main()
{
	int n;
	int n1;
	cin>>n;
	for(int i=0;i!=n;++i)
	{
		cin>>n1;
		a=new int*[n1];
		b=new int*[n1+1];
		for(int j=0;j!=n1;++j)
		{
			a[j]=new int[j+1];
			b[j]=new int[j+1];
			b[j][0]=0;
			for(int k=0;k<=j;++k)
			{
				b[j][k+1]=0;
				cin>>a[j][k];
			}
		}

	}
}