#include<iostream>
#include<cmath>
using namespace std;

int main()
{
	int m,n;
	cin>>m>>n;
	int * a1=new int[m];
	int * a2=new int[n];
	for(int i=0;i!=m;++i)
		cin>>a1[i];
	for(int i=0;i!=n;++i)
		cin>>a2[i];
	int min=abs(a1[0]-a2[0]),temp;
	for(int i=0;i!=m;++i)
		for(int j=0;j!=n;++j)
			if((temp=abs(a1[i]-a2[j]))<min)
				min=temp;
	cout<<min;
	return 0;
}