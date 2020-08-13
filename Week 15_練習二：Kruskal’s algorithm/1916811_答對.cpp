#include <iostream>
#include "queue"
#define max_size 50
using namespace std;
struct graph {
	int connect[2];
	float weight;
};
queue<int> kruskal(graph[], int[], int);
void sort(graph[], int);
bool Union(int[],int ,int, int);
bool cycle(int[], int, int);
void print(graph[], queue<int>);
void init(int[]);
int main()
{
	int from, dest, size = 0;
	int parent[max_size];
	init(parent);
	graph gp[max_size];
	while (cin >> from && !cin.eof())
	{
		cin >> dest;
		gp[size].connect[0] = from;
		gp[size].connect[1] = dest;
		cin >> gp[size++].weight;
	}
	queue <int> ans;
	ans = kruskal(gp, parent, size);
	print(gp, ans);
}
queue<int> kruskal(graph gp[], int parent[], int size)
{
	queue <int> ans;
	sort(gp, size);
	for (int i = 0; i < size; i++)
	{
		if(!Union(parent, max_size, gp[i].connect[0], gp[i].connect[1]))
			continue;
		else
			ans.push(i);
	}
	return ans;
}
void sort(graph gp[], int size)
{
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
		{
			if (gp[i].weight < gp[j].weight)
			{
				graph temp = gp[i];
				gp[i] = gp[j];
				gp[j] = temp;
			}
		}
}
bool Union(int parent[], int size, int from, int to)
{
	if (!cycle(parent, from, to))
	{
		for (; parent[from] >= 0; from = parent[from]);
		for (; parent[to] >= 0; to = parent[to]);
		int temp = parent[from] + parent[to];
		if (parent[from] > parent[to])
		{
			for (int i = 0; i < size; i++)
			{
				if (parent[i] == from)
					parent[i] = to;
			}
			parent[from] = to;
			parent[to] = temp;
		}
		else
		{
			for (int i = 0; i < size; i++)
			{
				if (parent[i] == to)
					parent[i] = from;
			}
			parent[to] = from;
			parent[from] = temp;
		}
		return true;
	}
	return false;
}
bool cycle(int parent[], int first, int second)
{
	if (parent[first] < 0 && parent[second] < 0);
	else if (parent[first] < 0)
	{
		if (first == parent[second])
			return true;
	}
	else if (parent[second] < 0)
	{
		if (parent[first] == second)
			return true;
	}
	else
	{
		if (parent[first] == parent[second])
			return true;
	}
	return false;
}
void print(graph gp[], queue<int> ans)
{
	int title = 1;
	float sum_weight = 0;
	while (!ans.empty())
	{
		sum_weight += gp[ans.front()].weight;
		cout << title << ": <" << gp[ans.front()].connect[0] << "," << gp[ans.front()].connect[1] << ">" << endl;
		ans.pop();
		title++;
	}
	cout << endl << "The cost of minimum spanning tree: " << sum_weight << endl;
}
void init(int parent[])
{
	for (int i = 0; i < 50; i++)
		parent[i] = -1;
}