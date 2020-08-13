#include "iostream"
#define max_size 100
using namespace std;
int main()
{
	int total, input_list[max_size], matrix[max_size][max_size] = { 0 }, num = 0, tight = -1;
	cin >> total;
	while (cin.get() != '\n')
	{
		cin >> input_list[num];
		tight += input_list[num] + 1;
		num++;
	}
	int col, last = total - tight, temp;
	col = last;
	for (int row = 0; row < num + 1; row++)
	{
		for (int th = 0; th < num; th++)
		{
			temp = input_list[th];
			while (temp != 0)
			{
				temp--;
				matrix[row][col]++;
				col++;
			}
			col++;
		}
		col = last;
	}
	col = 0;
	int total_move = last, sum = 0;
	for (int row = 1; row < num + 1; row++)
	{
		total_move += input_list[row - 1];
		for (int n = 1; n <= last; n++)
		{
			while (col != total_move)
			{
				matrix[row][col] = matrix[row][col + 1];
				col++;
			}
			matrix[row][col + 1 - n] = 0;
			col = 0;
		}
		total_move++;
	}
	for (int col = 0; col < total - 1; col++)
	{
		for (int row = 0; row < num + 1; row++)
		{
			sum += matrix[row][col];
		}
		if (sum != num + 1)
			matrix[0][col] = 0;
		sum = 0;
		cout << matrix[0][col] << " ";
	}
	cout << matrix[0][total] << endl;
	system("pause");
}