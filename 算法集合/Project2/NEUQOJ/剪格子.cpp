#include<iostream>
#include<set>

using namespace std;

int m,n;
int **a;
int result=0;
int tempresult=0;
int spln=0;
int** spl;
set<int> reset;

void split(int i,int j)
{
	if(i>-1&&i<n&&j>-1&&j<=m&&spl[i][j]==0)
	{
		spl[i][j]=1;
		tempresult+=a[i][j];
		spln++;
		
//	for(int k=0;k!=m;++k)
//	{	for(int l=0;l!=n;++l)
//			cout<<spl[k][l]<<" ";
//	cout<<endl;
//	}

		if(tempresult==result)
			reset.insert(spln);
		else
		{
			if(tempresult<result)
			{		
				split(i,j-1);
				split(i,j+1);
				split(i-1,j);
				split(i+1,j);
			}
			spl[i][j]=0;
			tempresult-=a[i][j];
			spln--;
			return;
		}
	}
}

int main()
{
	cin>>m>>n;
	a=new int*[n];
	spl=new int*[n];
	for(int i=0;i!=n;++i)
	{
		spl[i]=new int[m];
		a[i]=new int[m];
		for(int j=0;j!=m;++j)
		{
			cin>>a[i][j];
			spl[i][j]=0;
			result+=a[i][j];
		}
	}
	result/=2;
	split(0,0);
	cout<<*reset.begin();
	return 0;
}