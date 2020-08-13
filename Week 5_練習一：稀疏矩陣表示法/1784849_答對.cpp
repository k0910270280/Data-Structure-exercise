#include <iostream>
#define max_size 50
using namespace std;
struct mat {
	int row;
	int col;
	int value;
}mat1[max_size];
int main()
{
	int in[max_size][max_size], value = 0;
	cin >> mat1[0].row;
	cin >> mat1[0].col;
	for (int i = 0; i < mat1[0].row; i++)
		for (int j = 0; j < mat1[0].col; j++)
		{
			cin >> in[i][j];
			if (in[i][j] != 0)
			{
				mat1[value + 1].row = i;
				mat1[value + 1].col = j;
				mat1[value + 1].value = in[i][j];
				value++;
			}
		}
	mat1[0].value = value;
	for (int i = 0; i <= value; i++)
		cout << mat1[i].row << " " << mat1[i].col << " " << mat1[i].value << endl;
	system("pause");
}