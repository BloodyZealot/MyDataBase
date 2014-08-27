#include<iostream>
#include<vector>
#include<set>
using namespace std;

int bigest(set<int>::iterator rbeg,int s)
{
	int i=0;
	while(1)
	{
		if(*rbeg-*(++rbeg)==-1)
			++i;
		else
			i=0;
		if(i==s)
			return *(rbeg)-s-1;
	}
}

int main()
{
	int big,small;
	cin>>big>>small;
	if(small>big)swap(big,small);
	set<int> s;
	for(int i=0;i!=100;++i)
		for(int j=0;j!=100;++j)
			s.insert(i*big+j*small);
	cout<<bigest(s.begin(),small);
	return 0;
}