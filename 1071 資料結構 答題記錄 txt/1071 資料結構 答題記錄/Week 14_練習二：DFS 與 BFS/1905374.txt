#include <iostream>
#include "queue"
#define max_size 20
using namespace std;
typedef struct node *nodepointer;
struct node {
	nodepointer link;
	int vertex;
	node() { link = NULL; }
};

nodepointer graph[max_size];
bool visited[max_size] = { false }, visited2[max_size] = { false };
int ans[max_size], ind = 0;

void print();
void construct(int[][max_size], int);
void BFS(int);
void DFS(int);
int main()
{
	int mat[max_size][max_size] = { 0 }, row, col, max = 0;
	while (cin >> row && !cin.eof())
	{
		cin >> col;
		mat[row][col] = 1;
		mat[col][row] = 1;
		if (row > max)
			max = row;
		if (col > max)
			max = col;
	}
	for (int i = 0; i < max_size; i++)
		graph[i] = new node;
	construct(mat, max);
	cout << "Depth First Search:" << endl;
	DFS(0);
	print();	ind = 0;
	cout << "Breadth First Search:" << endl;
	BFS(0);
	print();
}
void construct(int mat[][max_size], int max)
{
	for (int i = 0; i <= max; i++)
	{
		for (int j = 0; j <= max; j++)
			if (mat[i][j] != 0)
			{
				nodepointer temp = new node, ptr;
				temp->link = NULL;	temp->vertex = j;
				for (ptr = graph[i]; ptr->link; ptr = ptr->link);
				ptr->link = temp;
			}
	}
}
void DFS(int v)
{
	nodepointer ptr;
	visited[v] = true;
	ans[ind++] = v;
	for (ptr = graph[v]->link; ptr; ptr = ptr->link)
		if (!visited[ptr->vertex])
			DFS(ptr->vertex);
}
void BFS(int v)
{
	nodepointer ptr;
	queue <int> q;
	ans[ind++] = v;
	visited2[v] = true;
	q.push(v);
	while (!q.empty())
	{
		v = q.front();	q.pop();
		for (ptr = graph[v]->link; ptr; ptr = ptr->link)
		{
			if (!visited2[ptr->vertex])
			{
				ans[ind++] = ptr->vertex;
				q.push(ptr->vertex);
				visited2[ptr->vertex] = true;
			}
		}
	}
}
void print()
{
	for (int i = 0; i < ind - 1; i++)
		cout << ans[i] << " ";
	cout << ans[ind - 1];
}