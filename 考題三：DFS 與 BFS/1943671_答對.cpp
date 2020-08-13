#include <iostream>
#include "queue"
#define max_size 30
using namespace std;
typedef struct node *nodepointer;
struct node {
	nodepointer link;
	int data;
};
void BFS(nodepointer[], int);
void DFS(nodepointer[], short int[], int);
void Adlist(nodepointer[], int*);
queue <int> ans;
int main()
{
	int size = 0;
	short int  visited[max_size] = { 0 };
	nodepointer list[max_size];
	Adlist(list, &size);
	DFS(list, visited, 0);
	cout << "Depth First Search:" << endl;
	cout << ans.front();	ans.pop();
	while (!ans.empty())
	{
		cout << " " << ans.front();
		ans.pop();
	}
	cout << endl << endl;
	BFS(list, 0);
}
void BFS(nodepointer list[], int start)
{
	cout << "Breadth First Search:" << endl;
	queue <int> q;
	short int visited[max_size] = { 0 };
	q.push(start);
	visited[start] = true;
	cout << start;
	while (!q.empty())
	{
		int pos = q.front(); q.pop();
		for (nodepointer ptr = list[pos]; ptr; ptr = ptr->link)
			if (!visited[ptr->data])
			{
				visited[ptr->data] = true;
				q.push(ptr->data);
				cout << " " << ptr->data;
			}
	}
	cout << endl;
}
void DFS(nodepointer list[], short int visited[], int start)
{
	ans.push(start);
	visited[start] = true;
	for (nodepointer ptr = list[start]; ptr; ptr = ptr->link)
		if (!visited[ptr->data])
			DFS(list, visited, ptr->data);
}
void Adlist(nodepointer list[], int *max)
{
	for (int i = 0; i < max_size; i++)
		list[i] = NULL;
	int sor, dest;
	while (cin >> sor && !cin.eof())
	{
		cin >> dest;
		nodepointer temp1 = new node, temp2 = new node;
		temp1->link = temp2->link = NULL;
		temp1->data = dest;
		temp2->data = sor;
		if (!list[sor])
			list[sor] = temp1;
		else
		{
			nodepointer ptr = list[sor];
			while (ptr->link)
				ptr = ptr->link;
			ptr->link = temp1;
		}
		if (!list[dest])
			list[dest] = temp2;
		else
		{
			nodepointer ptr = list[dest];
			while (ptr->link)
				ptr = ptr->link;
			ptr->link = temp2;
		}
		if (*max < sor)
			*max = sor;
		if (*max < dest)
			*max = dest;
	}
}