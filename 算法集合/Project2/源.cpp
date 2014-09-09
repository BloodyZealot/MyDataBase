#include <iostream>  
#include <fstream>  
#include <algorithm>  
#include <vector>  
#include <cstring>  
#include <stdio.h>  
#include <stdlib.h>  
using namespace std;

//此代码使用前，需删除下面两行+后面的system("PAUSE")  

struct Person
{
	char id[9];
	int virtue;
	int talent;
	int sum;
};

int cmp(const void* A, const void* B)        //返回false(0),则不用对调，实现从大到小  
{
	Person *aa = (Person*)A;
	Person *bb = (Person*)B;
	if (aa->sum == bb->sum)
	{
		if (aa->virtue == bb->virtue)
		{
			return strcmp(aa->id, bb->id);
		}
		else
			return (aa->virtue < bb->virtue);
	}
	else
		return (aa->sum < bb->sum);
}

bool sort_cmp(const Person& aa, const Person& bb)        //返回false对调，实现从大到小  
{
	if (aa.sum == bb.sum)
	{
		if (aa.virtue == bb.virtue)
		{
			if (strcmp(aa.id, bb.id)>0)            //对于字符数组的比较，有不同  
				return false;
			else return true;
		}
		else
			return (aa.virtue > bb.virtue);
	}
	else
		return (aa.sum > bb.sum);
}

int main()
{
	int n, l, h;
	scanf("%d %d %d", &n, &l, &h);
	//cin>>n>>l>>h;  
	Person *p = new Person[n];
	int i;
	vector<Person> sage, nobleman, foolman, others;

	for (i = 0; i<n; i++)
	{
		scanf("%s %d %d", p[i].id, &p[i].virtue, &p[i].talent);
		//cin>>p[i].id>>p[i].virtue>>p[i].talent;  
		p[i].sum = p[i].virtue + p[i].talent;

		if (p[i].virtue<l || p[i].talent<l)continue;        //直接跳过都低的  

		if (p[i].virtue >= h && p[i].talent >= h)               //圣人  
		{
			sage.push_back(p[i]);
		}
		else if (p[i].virtue >= h && p[i].talent<h)      //君子  
		{
			nobleman.push_back(p[i]);
		}
		else if (p[i].virtue<h && p[i].talent<h && p[i].virtue >= p[i].talent)        //愚人  
		{
			foolman.push_back(p[i]);
		}
		else                                            //其他人  
		{
			others.push_back(p[i]);
		}
	}
	sort(sage.begin(), sage.end(), sort_cmp);
	sort(nobleman.begin(), nobleman.end(), sort_cmp);
	sort(foolman.begin(), foolman.end(), sort_cmp);
	sort(others.begin(), others.end(), sort_cmp);
	//qsort(& *sage.begin(),sage.size(),sizeof(Person),cmp);  
	//qsort(& *nobleman.begin(),nobleman.size(),sizeof(Person),cmp);  
	//qsort(& *foolman.begin(),foolman.size(),sizeof(Person),cmp);  
	//qsort(& *others.begin(),others.size(),sizeof(Person),cmp);  

	int m = sage.size() + nobleman.size() + foolman.size() + others.size();
	printf("%d\n", m);
	//cout<<m<<endl;  
	for (i = 0; i<sage.size(); i++)
		printf("%s %d %d\n", sage[i].id, sage[i].virtue, sage[i].talent);
	//cout<<sage[i].id<<' '<<sage[i].virtue<<' '<<sage[i].talent<<endl;  
	for (i = 0; i<nobleman.size(); i++)
		printf("%s %d %d\n", nobleman[i].id, nobleman[i].virtue, nobleman[i].talent);
	//cout<<nobleman[i].id<<' '<<nobleman[i].virtue<<' '<<nobleman[i].talent<<endl;  
	for (i = 0; i<foolman.size(); i++)
		printf("%s %d %d\n", foolman[i].id, foolman[i].virtue, foolman[i].talent);
	//cout<<foolman[i].id<<' '<<foolman[i].virtue<<' '<<foolman[i].talent<<endl;  
	for (i = 0; i<others.size(); i++)
		printf("%s %d %d\n", others[i].id, others[i].virtue, others[i].talent);
	// cout<<others[i].id<<' '<<others[i].virtue<<' '<<others[i].talent<<endl;  
	system("PAUSE");
	return 0;
}