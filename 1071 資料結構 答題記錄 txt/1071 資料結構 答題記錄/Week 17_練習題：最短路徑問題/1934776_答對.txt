#include <iostream>
#include "queue"
using namespace std;
void shortestPath(int v, int cost[][7], int distance[], int n, short int found[]);
int choose(int distance[], int n, short int found[]);
int main()
{
	int mat[7][7] = { {0,0,1,0,1,0,1},{0,0,0,1,1,0,0},{1,0,0,1,0,1,1},{0,1,1,0,0,1,0},{1,1,0,0,0,0,0}, {0,0,1,1,0,0,1},{1,0,1,0,0,1,0} };
	int source, dest, distance[10];
	short int found[10];
	for (int i = 0; i < 7; i++)
		for (int j = 0; j < 7; j++)
			if (mat[i][j] == 0)
				mat[i][j] = 999999;
	queue<int>q;
	while (cin >> source >> dest)
	{
		if (source == dest && dest == 0)
			break;
		shortestPath(source, mat, distance, 7, found);
		q.push(distance[dest]);
	}
	while (!q.empty())
	{
		cout << q.front() << endl;
		q.pop();
	}
}
void shortestPath(int v, int cost[][7], int distance[], int n, short int found[])
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