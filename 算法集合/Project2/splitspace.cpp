#include<iostream>

using namespace std;

int main()
{
	int n,temp;
	int result;
	cin>>n;
	for(int i=0;i!=n;++i)
	{
		cin>>temp;
		result=2;
		for(int j=1;j!=temp;++j)
		{
			result+=10;
			result+=9*(j-1);
		}
		cout<<result<<endl;
	}
	return 0;
}