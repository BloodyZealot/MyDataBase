#include<iostream>
#include<string>
#include<map>
#include<queue>
#include<stack>

using namespace std;

struct snode
{
	int prevcity;
	int city;
	int deep;
	int lenth;
	int happiness;
};


bool operator<(const snode& s1,const snode& s2)
{
	if(s1.lenth==s2.lenth)
	{
		if(s1.happiness==s2.happiness)
		{
			return s1.happiness/s1.deep<s2.happiness/s2.deep;
		}
		else
			return s1.happiness<s2.happiness;
	}
	else
	return s1.lenth>s2.lenth;
}

int n,k;
int temp;
string scity;
string tempcity,tempcity2;
map<string,int> dict;
map<int,string> translate;
stack<int> output;

int happy[210];
int maps[210][210];
bool closed[210];
int prevcity[210];

int dest,result=-1,num=0;
snode resultnode;

priority_queue<snode> open;
snode tnode,nextnode;
   





void slove()
{
	while(open.size())
	{
		tnode=open.top();
		open.pop();
		if(tnode.city==dest)
		{
			if(result==-1)
			{
				result=tnode.lenth;
				resultnode=tnode;
				num=1;
			}
			else
			if(tnode.lenth==result)
			{
				if(tnode.happiness==resultnode.happiness)
				{
					if(tnode.happiness/tnode.deep>resultnode.happiness/resultnode.deep)
						resultnode=tnode;
				}
				else
					if(tnode.happiness>resultnode.happiness)
						resultnode=tnode;
				++num;
			}
		}
		else
			closed[tnode.city]=true;
		if(prevcity[tnode.city]==-1)
			prevcity[tnode.city]=tnode.prevcity;
		for(int i=0;i!=n;++i)
		{
			if(!closed[i]&&maps[tnode.city][i]!=-1)
			{
				nextnode.city=i;
				nextnode.deep=tnode.deep+1;
				nextnode.prevcity=tnode.city;
				nextnode.happiness=tnode.happiness+happy[i];
				nextnode.lenth=tnode.lenth+maps[tnode.city][i];
				open.push(nextnode);
			}
		}
	}
}

int main()
{
	cin >> n >> k;
	cin >> scity;
	dict[scity] = 0;
	translate[0] = scity;
	for (int i = 1; i != n; ++i)
	{
		cin >> tempcity >> temp;
		dict[tempcity] = i;
		translate[i] = tempcity;
		happy[i] = temp;
	}
	for (int i = 0; i != n; ++i)
		for (int j = 0; j != n; ++j)
			maps[i][j] = -1;
	for (int i = 0; i != n; ++i)
		prevcity[i] = -1;
	for (int i = 0; i != k; ++i)
	{
		cin >> tempcity >> tempcity2 >> temp;
		maps[dict[tempcity]][dict[tempcity2]] =
			maps[dict[tempcity2]][dict[tempcity]] = temp;
	}
	dest = dict["ROM"];
	tnode.city = tnode.lenth = tnode.happiness = tnode.deep = 0;
	tnode.prevcity = -1;
	open.push(tnode);
	slove();
	cout << num << ' ' << resultnode.lenth << ' ' << resultnode.happiness << ' ' << resultnode.happiness / resultnode.deep << endl;
	temp = resultnode.prevcity;
	while (temp != -1)
	{
		output.push(temp);
		temp = prevcity[temp];
	}
	while (output.size())
	{
		cout << translate[output.top()] << "->";
		output.pop();
	}
	cout << "ROM";
	return 0;
}