#include "iostream"
#define max_size 50
using namespace std;
bool input_number(int[][max_size], int, int, int, int);
int mat[max_size][max_size] = { 0 };
int main(void)
{
	int size, x = 0, y;
	cin >> size;
	y = size / 2;
	for (int n = 1; n <= (size*size); n++)
	{
		bool in = false;
		while (in == false)
		{
			if ((x < 0) && (y >= size))
			{
				x = 1;
				y = size-1;
			}
			else if (x < 0)
				x = size - 1;
			else if (y >= size)
				y = 0; 
			else if (x == size)
				x = 0;
			in = input_number(mat, size, x, y, n);
			if (in == false)
			{
				x = x + 2;
				y = y - 1;
			}
		}
		x--;
		y++;
	}
	for (int n = 0; n < size; n++)
	{
		for (int m = 0; m < size-1; m++)
			cout << mat[n][m]<<" ";
		cout << mat[n][size - 1] << endl;
	}
	system("pause");
}
bool input_number(int mat[][max_size], int size, int x, int y,int n)
{
	if (mat[x][y] == 0)
	{
		mat[x][y] = n;
		return true;
	}
	else if (mat[x][y] != 0)
		return false;
}