#include <iostream>
#define max_size 30
using namespace std;
void Admat(int[][max_size], int*);
void bellman(int[][max_size], int[][max_size], int);
void print(int[][max_size], int);
int main()
{
	int mat[max_size][max_size] = { 0 }, dist[max_size][max_size], size = 0;
	Admat(mat, &size);
	bellman(mat, dist, size);
	print(dist, size);
}
void bellman(int mat[][max_size], int dist[][max_size], int size)
{
	for (int i = 0; i < max_size; i++)
		for (int j = 0; j < max_size; j++)
			dist[i][j] = 999999;
	dist[0][0] = 0;
	for (int i = 0; i <= size; i++)
		if (mat[0][i] != 0)
			dist[0][i] = mat[0][i];
	for (int j = 0; j < size; j++)
	{
		for (int p = 0; p <= size; p++)
			dist[j + 1][p] = dist[j][p];
		for (int i = 0; i <= size; i++)
		{
			for (int k = 0; k <= size; k++)
			{
				if (mat[k][i] != 0 && mat[k][i] + dist[j][k] < dist[j + 1][i])
					dist[j + 1][i] = mat[k][i] + dist[j][k];
			}
		}
	}
}
void Admat(int mat[][max_size], int *size)
{
	int sor, dest, weight;
	while (cin >> sor && !cin.eof())
	{
		cin >> dest >> weight;
		mat[sor][dest] = weight;
		if (*size < sor)
			*size = sor;
		if (*size < dest)
			*size = dest;
	}
}
void print(int dist[][max_size], int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (dist[i][j] == 999999)
				cout << "i ";
			else
				cout << dist[i][j] << " ";
		}
		if (dist[i][size] == 999999)
			cout << "i"<<endl;
		else
			cout << dist[i][size]<<endl;
	}
}