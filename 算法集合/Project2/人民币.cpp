#include<iostream>

using namespace std;

int main()
{
	int n;
	cin>>n;
	int imax=n/5,jmax=n/2;
	int result=0;
	for(int i=1;i!=imax;++i)
		for(int j=1;j!=jmax;++j)
			if(i*5+j*2<n)
				result++;
	cout<<result;
	return 0;
}