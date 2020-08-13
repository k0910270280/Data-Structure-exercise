#include <iostream>
#define max_size 50
using namespace std;
typedef struct sparse_matrx {
	int row, col, value;
}mat;
struct table {
	int num, pos;
};
void transpose(mat[], mat[]);
void input(mat[]);
void print(mat[]);
int main()
{
	mat mat1[max_size], mat2[max_size];
	input(mat1);
	print(mat1);
	cout << "start" << endl;
	transpose(mat1, mat2);
	print(mat2);
}
void transpose(mat mat1[],mat mat2[])
{
	table t[max_size];
	mat2[0].row = mat1[0].col;
	mat2[0].col = mat1[0].row;
	mat2[0].value = mat1[0].value;
	for (int i = 0; i < mat1[0].col; i++)
		t[i].num = 0;
	for (int i = 1; i <= mat1[0].value; i++)
		t[mat1[i].col].num++;
	t[0].pos = 1;
	for (int i = 1; i < mat1[0].col; i++)
		t[i].pos = t[i - 1].num + t[i - 1].pos;
	for (int i = 1; i <= mat1[0].value; i++)
	{
		int temp = t[mat1[i].col].pos++;
		mat2[temp].row = mat1[i].col;
		mat2[temp].col = mat1[i].row;
		mat2[temp].value = mat1[i].value;
	}
}
void print(mat mat1[])
{
	for (int i = 0; i <= mat1[0].value; i++)
		cout << mat1[i].row << " " << mat1[i].col << " " << mat1[i].value << endl;
}
void input(mat mat1[])
{
	cin >> mat1[0].row >> mat1[0].col >> mat1[0].value;
	for (int i = 1; i <= mat1[0].value; i++)
	{
		cin >> mat1[i].row >> mat1[i].col >> mat1[i].value;
	}
}