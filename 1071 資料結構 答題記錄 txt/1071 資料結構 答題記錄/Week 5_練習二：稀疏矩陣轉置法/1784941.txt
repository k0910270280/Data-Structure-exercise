#include "iostream"
#define max_size 20
using namespace std;
struct mat {
	int row;
	int col;
	int value;
}mat1[max_size], mat2[max_size];
struct table {
	int pos;
	int num = 0;
} tab[max_size];
int main(void)
{
	cin >> mat1[0].row;
	cin >> mat1[0].col;
	cin >> mat1[0].value;
	for (int i = 1; i <= mat1[0].value; i++)
	{
		cin >> mat1[i].row;
		cin >> mat1[i].col;
		cin >> mat1[i].value;
	}
	mat2[0].col = mat1[0].row;
	mat2[0].row = mat1[0].col;
	mat2[0].value = mat1[0].value;
	for (int i = 1; i <= mat1[0].value; i++)
	{
		tab[mat1[i].col].num++;
	}
	tab[0].pos = 1;
	for (int i = 1; i < mat1[0].col; i++)
		tab[i].pos = tab[i - 1].pos + tab[i - 1].num;
	for (int i = 1; i <= mat1[0].value; i++)
	{
		int temp = tab[mat1[i].col].pos++;
		mat2[temp].row = mat1[i].col;
		mat2[temp].col = mat1[i].row;
		mat2[temp].value = mat1[i].value;
	}
	for (int j = 0; j <= mat2[0].value; j++)
		cout << mat2[j].row << " " << mat2[j].col << " " << mat2[j].value << endl;
	system("pause");
}