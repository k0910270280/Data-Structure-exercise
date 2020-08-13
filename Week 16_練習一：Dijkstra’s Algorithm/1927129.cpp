#include <iostream>
#define MAX_VERTICES 300
using namespace std;
void shortestPath(int v, int cost[][MAX_VERTICES], int distance[], int n, short int found[]);
int choose(int distance[], int n, short int found[]);
int main()
{
	int source, dest, cost[MAX_VERTICES][MAX_VERTICES], distance[MAX_VERTICES], v, n = 0;
	short int found[MAX_VERTICES];

	for (int i = 0; i < MAX_VERTICES; i++)
		for (int j = 0; j < MAX_VERTICES; j++)
			cost[i][j] = 999999;

	cin >> v;
	while (cin >> source && !cin.eof())
	{
		cin >> dest;
		cin >> cost[source][dest];
		if (n < source)
			n = source;
		if (n < dest)
			n = dest;
	}
	n++;
	shortestPath(v, cost, distance, n, found);
	for (int i = 0; i < n; i++)
		cout << i << ":" << distance[i] << endl;
}
void shortestPath(int v, int cost[][MAX_VERTICES], int distance[], int n, short int found[])
{
	int i, u, w;
	for (i = 0; i < n; i++) 
	{
		found[i] = 0;
		distance[i] = cost[v][i];
	}
	found[v] = 1;
	distance[v] = 0;
	for (i = 0; i < n - 2; i++) 
	{
		u = choose(distance, n, found);
		found[u] = 1;
		for (w = 0; w < n; w++)
			if (!found[w])
				if (distance[u] + cost[u][w] < distance[w])
					distance[w] = distance[u] + cost[u][w];
	}
}
int choose(int distance[], int n, short int found[])
{
	int i, min, minpos;
	min = INT_MAX;
	minpos = -1;
	for (i = 0; i < n; i++)
	{
		if (distance[i] < min && !found[i])
		{
			min = distance[i];
			minpos = i;
		}
	}
	return minpos;
}