#include <iostream>
#include "queue"
#include "algorithm"
#define max_size 50
using namespace std;
struct graph {
	int connect[2];
	float weight;
};
void prim(graph[], int[], int, int);
bool Union(int[], int, int, int);
bool cycle(int[], int, int);
void sort(graph[], int);
void init(int[]);
int main()
{
	int size = 0, start, total_node = 0;
	int parent[max_size];
	init(parent);
	graph gp[max_size];
	cin >> start;
	while (cin >> gp[size].connect[0] && !cin.eof())
	{
		cin >> gp[size].connect[1] >> gp[size].weight;
		if (gp[size].connect[1] > total_node)
			total_node = gp[size].connect[1];
		if (gp[size].connect[0] > total_node)
			total_node = gp[size].connect[0];
		size++; //here!!
	}
	prim(gp, parent, size, total_node);
}
void prim(graph gp[], int parent[], int size, int total_node)
{
	int span_node = 0, total_weight = 0;
	while (span_node < total_node)
	{
		queue <int> stand;
		sort(gp, size);
		stand.push(0);
		for (int i = 0; i < size; i++)
		{
			if (parent[0] < 0)
			{
				if (parent[i] == 0)
					stand.push(i);
			}
			else
			{
				if (parent[i] == parent[0])
					stand.push(i);
			}
		}
		int related[max_size], count = 0;
		while (!stand.empty())
		{
			int check = stand.front();
			for (int i = 0; i < size; i++)
			{
				if (gp[i].connect[0] == check || gp[i].connect[1] == check)
				{
					if (!cycle(parent, gp[i].connect[0], gp[i].connect[1]))
						related[count++] = i;
				}
			}
			stand.pop();
		}
		sort(related, related + count);
		int mini_index = related[0];
		if (Union(parent, size, gp[mini_index].connect[0], gp[mini_index].connect[1]))
		{
			if (span_node == 0 || span_node == total_node - 1)
				cout << span_node + 1 << ": <" << gp[mini_index].connect[0] << "," << gp[mini_index].connect[1] << ">" << endl;
			else
				cout << span_node + 1 << ": <" << gp[mini_index].connect[1] << "," << gp[mini_index].connect[0] << ">" << endl;
			total_weight += gp[mini_index].weight;
		}
		span_node++;
	}
	cout << endl << "The cost of minimum spanning tree: " << total_weight << endl;
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
void init(int parent[])
{
	for (int i = 0; i < 50; i++)
		parent[i] = -1;
}