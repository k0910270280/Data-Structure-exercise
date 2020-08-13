#include "iostream"
#include "string"
#define max_size 20
using namespace std;
int mat[max_size][max_size], dim, temp;
void V(void);
void H(void);
void D(void);
int main()
{
	int count = 1, ptr = 0;
	string input;
	char instruct[20];
	cin >> dim;
	for (int i = 0; i < dim; i++)
		for (int j = 0; j < dim; j++)
		{
			mat[i][j] = count;
			count++;
		}
	cin >> input;
	int length = input.length();
	for (int i = 0; i < length; i++)
		instruct[i] = input[i];
	while (ptr != length)
	{
		if (instruct[ptr] == 'V')
			V();
		else if (instruct[ptr] == 'H')
			H();
		else if (instruct[ptr] == 'D')
			D();
		ptr++;
	}
	for (int i = 0; i < dim; i++)
	{
		for (int j = 0; j < dim; j++)
		{
			cout << mat[i][j] << " ";
			if (j == dim - 1)
				cout << mat[i][j];
		}
		cout << endl;
	}
	system("pause");
}
void V(void)
{
	for (int col = 0; col < dim; col++)
		for (int row = 0; row < (dim / 2); row++)
		{
			temp = mat[row][col];
			mat[row][col] = mat[dim - row - 1][col];
			mat[dim - row - 1][col] = temp;
		}
}
void H(void)
{
	for (int row = 0; row < dim; row++)
		for (int col = 0; col < (dim / 2); col++)
		{
			temp = mat[row][col];
			mat[row][col] = mat[row][dim - col - 1];
			mat[row][dim - col - 1] = temp;
		}
}
void D(void)
{
	for (int col = 0; col < dim; col++)
		for (int row = 0; row < dim; row++)
			if (col < row)
			{
				temp = mat[row][col];
				mat[row][col] = mat[col][row];
				mat[col][row] = temp;
			}
}