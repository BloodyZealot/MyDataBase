#include<iostream>
#include<memory>
using namespace std;

int tree[15][15];
int parrent[15];
int connect[15];
int *ptr[15];
int *arr1=new int[15];
int *arr2=new int[15];
int deep;

int fun(int pos)
{
	int result=0;
	while (1)
	{
	int i = 0; int k = 0;
	while (arr1[i] != -1)
	{
		if (connect[arr1[i]] != 3)
		{
			for (int j = 0; arr1[j] != -1; ++j)
			{
				result += connect[arr1[j]]-1;
			}
			return result;
		}
		for (int j = 0; j != 3;++j)
		if (tree[arr1[i]][j] != parrent[i])
		{
			arr2[k++] = tree[i][j];
			parrent[tree[i][j]] = arr1[i];
		}
		arr2[k] = -1;
	}
	swap(arr1, arr2);
	}
}
int main()
{
	int num;
	int n;
	int x, y;
	cin >> num;
	for (int looper = 1; looper <= num; ++looper)
	{
		cin >> n;
		memset(connect, 0, n * sizeof(int));
		for (int i = 0; i != n; ++i)
		{
			memset(tree[i], -1, (i+1)*sizeof(int));
			ptr[i] = tree[i];
		}
		for (int i = 1; i != n; ++i)
		{
			cin >> x >> y;
			x--; y--;
			connect[x]++;
			connect[y]++;
			*ptr[x]++ = y;
			*ptr[y]++ = x;
		}
		for (int i = 0; i != n; ++i)
		if (connect[i] == 2)
		{
			arr1[0] = tree[i][0]; arr1[1] = tree[i][1]; arr1[2] = -1;
			parrent[tree[i][0]] = parrent[tree[i][1]] = i;
			cout<<"Case #"<<looper<<": "<<fun(i)<<endl;
			break;
		}
	}
	return 0;
}