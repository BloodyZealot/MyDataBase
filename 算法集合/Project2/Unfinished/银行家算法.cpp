#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct proc
{
	int procn;
	vector<int> allocatedsoure;
	vector<int> needsoure;
};

bool operator<(const proc& p1, const proc& p2)
{
	int size = p1.needsoure.size();
	for (int i = 0; i != size; ++i)
	{
		if (p1.needsoure[i] != p2.needsoure[i])
			return p1.needsoure[i] < p2.needsoure[i];
	}
	return false;
}

bool operator==(const proc&p, const int& pnum)
{
	return p.procn == pnum;
}

bool canbefufill(const vector<int>& p, vector<int>& s)
{
	int size = s.size();
	for (int i = 0; i != size; ++i)
	{
		if (p[i] > s[i])
			return false;
	}
	return true;
}

int procnum;
int sourcenum;

vector<proc> process;
vector<int> source;
vector<int> temp;

int main()
{
	cout << "input the process number & sources number:" << endl;
	cin >> procnum >> sourcenum;
	source.resize(sourcenum);
	for (int i = 0; i != sourcenum; ++i)
	{
		cout << "input the number of sources " << i << endl;
		cin >> source[i];
	}
	process.resize(procnum);
	for (int i = 0; i != procnum; ++i)
	{
		process[i].procn = i;
		process[i].allocatedsoure.resize(sourcenum);
		process[i].needsoure.resize(sourcenum);
		cout << "input the need of proecss " << i << endl;
		for (int j = 0; j != sourcenum; ++j)
		{
			cout << "source " << j << " ";
			cin >> process[i].needsoure[j];
		}
	}
	int tpnum;
	int tsource, tsourcenum;
	while (1)
	{
		cout << "input the process number which need allocate source : ";
		cin >> tpnum;
		cout << "input the source number & need of source : ";
		cin >> tsource >> tsourcenum;
		if (source[tsource] < tsourcenum)
		{
			cout << "require exceed the limit of system source! reinput !"<<endl;
			continue;
		}
		auto ptr=find(process.begin(), process.end(), tpnum);
		if (ptr->needsoure[tsource] < tsourcenum)
		{
			cout << "require exceed the limit of process need source! reinput !" << endl;
			continue;
		}
		ptr->allocatedsoure[tsource] += tsourcenum;
		ptr->needsoure[tsource] -= tsourcenum;
		temp.assign(source.begin(),temp.end());
		temp[tsource] -= tsourcenum;
		sort(process.begin(), process.end());
		for each (auto var in process)
		{

		}
	}
}