#include<iostream>
#include<iomanip>
#include<string>

using namespace std;

struct nod
{
	int next;
	int v;
};
struct rebulidnode
{
	int addr;
	nod node;
};

nod nodes[100010];
rebulidnode rebuild[100010];

int main()
{
	int start, n, count;
	int addr;
	nod tnode;
	rebulidnode trnode;
	cin >> start >> n >> count;
	for (int i = 0; i != n; ++i)
	{
		cin >> addr >> tnode.v >> tnode.next;
		nodes[addr] = tnode;
	}
	for (int i = 0; i != n; ++i)
	{
		trnode.node = nodes[start];
		trnode.addr = start;
		start = nodes[start].next;
		rebuild[i] = trnode;
	}
	if (count == 1 || count == 0)
	{
		for (int i = 0; i != n - 1; ++i)
		{
			cout << setw(5) << setfill('0') << rebuild[i].addr << ' '
				<< rebuild[i].node.v << ' '
				<< setw(5) << setfill('0') << rebuild[i].node.next << endl;
		}
		cout << setw(5) << setfill('0') << rebuild[n - 1].addr << ' '
			<< rebuild[n - 1].node.v << ' '
			<< -1 << endl;
	}
	else
	{
		int counter, basic;
		int times = n / count - 1;
		for (int i = 0; i != times; ++i)
		{
			for (basic = i*count, counter = count - 1 + basic; counter != basic; --counter)
			{
				cout << setw(5) << setfill('0') << rebuild[counter].addr << ' '
					<< rebuild[counter].node.v << ' '
					<< setw(5) << setfill('0') << rebuild[counter - 1].addr << endl;
			}
			cout << setw(5) << setfill('0') << rebuild[basic].addr << ' '
				<< rebuild[basic].node.v << ' '
				<< setw(5) << setfill('0') << rebuild[basic + count * 2 - 1].addr << endl;
		}
		if (n%count == 0)
		{
			for (basic = n - count, counter = n - 1; counter != basic; --counter)
			{
				cout << setw(5) << setfill('0') << rebuild[counter].addr << ' '
					<< rebuild[counter].node.v << ' '
					<< setw(5) << setfill('0') << rebuild[counter - 1].addr << endl;
			}
			cout << setw(5) << setfill('0') << rebuild[basic].addr << ' '
				<< rebuild[basic].node.v << ' '
				<< -1 << endl;
		}
		else
		{
			for (basic = (n / count - 1)*count, counter = n / count*count - 1; counter != basic; --counter)
			{
				cout << setw(5) << setfill('0') << rebuild[counter].addr << ' '
					<< rebuild[counter].node.v << ' '
					<< setw(5) << setfill('0') << rebuild[counter - 1].addr << endl;
			}
			cout << setw(5) << setfill('0') << rebuild[basic].addr << ' '
				<< rebuild[basic].node.v << ' '
				<< rebuild[basic + count].addr << endl;
			for (int add = basic + count; add != n - 1; ++add)
			{
				cout << setw(5) << setfill('0') << rebuild[add].addr << ' '
					<< rebuild[add].node.v << ' '
					<< setw(5) << setfill('0') << rebuild[add + 1].addr << endl;
			}
			cout << setw(5) << setfill('0') << rebuild[n - 1].addr << ' '
				<< rebuild[n - 1].node.v << ' '
				<< -1 << endl;
		}
	}
	return 0;
}