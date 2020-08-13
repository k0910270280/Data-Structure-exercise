#include "pch.h"
#include <iostream>
#define max_size 20
using namespace std;
/*struct graph {
	int connect[2];
	float weight;
};
bool cycle(int, int[], int);
void sort(graph[], int);*/
int mat[max_size][max_size];
int main()
{
	cout << "1" << endl;
	int total;
	cin >> total;
	for (int i = 0; i < total; i++)
		for (int j = 0; j < total; j++)
			cin >> mat[i][j];
	cout << "-1" << endl;
}
/*bool cycle(graph gp[], int size, int ans_ind[], int ans_size)
{
	bool cycle = false;
	for (int i = 0; i < ans_size; i++)
	{
		float complete = gp[ans_ind[i]].connect[0];
		for (int j = 0; j < size; j++)
		{
			int temp = find(gp, size, gp[ans_ind[j]].connect[0]);
			if (gp[temp].connect[0] == complete)
				return true;
			if (temp != -1)
				find(gp, size, gp[ans_ind[j]].connect[0]);
		}
	}
}
int find(graph gp[], int size, int target)
{
	for (int i = 0; i < size; i++)
		if (gp[i].connect[0] == target)
			return i;
	return -1;
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
}*/