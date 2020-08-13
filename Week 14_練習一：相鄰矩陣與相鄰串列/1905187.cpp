#include <iostream>
#define max_size 100
using namespace std;
void print_matrix(int[][max_size], int);
void print_list(int[][max_size], int);
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
	cout << "ww";
	print_matrix(mat, max);
	cout << endl;
	print_list(mat, max);
}
void print_matrix(int mat[][max_size], int max)
{
	cout << "Adjacency matrix:" << endl;
	for (int i = 0; i < max; i++)
	{
		for (int j = 0; j < max - 1; j++)
			cout << mat[i][j] << " ";
		cout << mat[i][max - 1] << endl;
	}
}
void print_list(int mat[][max_size], int max)
{
	cout << "Adjacency list:" << endl;
	for (int i = 0; i < max; i++)
	{
		cout << i << ": ";
		for (int j = 0; j < max; j++)
			if (mat[i][j] != 0)
				cout << j << " -> ";
		cout << "end" << endl;
	}
}