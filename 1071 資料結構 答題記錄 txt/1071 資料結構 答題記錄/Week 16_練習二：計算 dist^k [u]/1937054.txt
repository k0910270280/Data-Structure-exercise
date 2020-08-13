#include <iostream>
#define max_size 30
using namespace std;
void Admatrix(int[][max_size], int*);
void bellman(int[][max_size], int[][max_size], int);
void print(int[][max_size], int);
int main()
{
	int max = 0, admat[max_size][max_size] = { 0 }, dist[max_size][max_size];
	Admatrix(admat, &max);
	for (int i = 0; i <= max; i++)
		for (int j = 0; j <= max; j++)
			dist[i][j] = 999999;
	bellman(admat, dist, max);
	print(dist, max);
}
void bellman(int admat[][max_size], int dist[][max_size], int size)
{
	dist[0][0] = 0;
	for (int i = 0; i <= size; i++)
		if (admat[0][i] != 0)
			dist[0][i] = admat[0][i];
	for (int j = 0; j < size; j++)
	{
		for (int p = 0; p <= size; p++)
			dist[j + 1][p] = dist[j][p];
		for (int i = 0; i <= size; i++)
		{
			for (int k = 0; k <= size; k++)
			{
				if (admat[k][i] != 0 && dist[j][k] + admat[k][i] < dist[j + 1][i])
				{

					dist[j + 1][i] = dist[j][k] + admat[k][i];
				}
				
			}
		}
	}
}
void Admatrix(int mat[][max_size], int *max)
{
	int sor, dest, weight;
	while (cin >> sor && !cin.eof())
	{
		cin >> dest >> weight;
		mat[sor][dest] = weight;
		if (sor > *max)
			*max = sor;
		if (dest > *max)
			*max = dest;
	}
}
void print(int mat[][max_size], int size)
{
	for (int i = 0; i <= size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (mat[i][j] == 999999)
				cout << "i ";
			else
				cout << mat[i][j] << " ";
		}
		if (mat[i][size] == 999999)
			cout << "i" << endl;
		else
			cout << mat[i][size] << endl;
	}
}