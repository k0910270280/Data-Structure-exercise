#include "iostream"
#include "string"
#define max_size 20
using namespace std;
char mat[max_size][max_size], target[max_size];
int row, col, start_row, start_col, may_target_row, may_target_col;
bool keep_find, find_out;
bool find_first(int, int);
int find_other(int, int, int);
int main()
{
	int total, count = 0;
	string input, list[10];
	cin >> row;
	cin >> total;
	col = row;
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			cin >> mat[i][j];
	while (count != total)
	{
		count++;
		start_row = 0, start_col = 0, keep_find = true, find_out = false;
		cin >> input;
		int length = input.length();
		for (int i = 0; i < length; i++)
			target[i] = input[i];
		while (keep_find == true)
		{
			if (find_first(start_row, start_col))
			{
				find_other(start_row, start_col, length);
				start_col++;
			}
			else
				keep_find = false;
		}
		if (find_out == true)
			list[count - 1] = "Yes";
		else
			list[count - 1] = "No";
	}
	for (int i = 0; i < total; i++)
		cout << list[i] << endl;
	system("pause");
}
bool find_first(int tar_pos_r, int tar_pos_c)
{
	for (int i = tar_pos_r; i < row; i++)
	{
		for (int j = tar_pos_c; j < col; j++)
			if (target[0] == mat[i][j])
			{
				start_row = i;
				start_col = j;
				return true;
			}
		tar_pos_c = 0;
	}
	return false;
}
int find_other(int tar_pos_r, int tar_pos_c, int length)
{
	int pos = 1, temp, temp1 = tar_pos_r, temp2 = tar_pos_r, temp3 = tar_pos_c, temp4 = tar_pos_c;
	while ((target[pos] == mat[tar_pos_r + pos][tar_pos_c])|| ((tar_pos_r + pos) == row))
	{
		if (pos == length - 1)
		{
			keep_find = false;
			find_out = true;
			return 0;
		}
		pos++;
		if ((tar_pos_r + pos) >= row)
		{
			temp = pos;
			tar_pos_r = 1 - temp;
		}
	}
	tar_pos_r = temp1;
	pos = 1;
	while ((target[pos] == mat[tar_pos_r - pos][tar_pos_c])|| ((tar_pos_r - pos) == -1))
	{
		if (pos == length-1)
		{
			keep_find = false;
			find_out = true;
			return 0;
		}
		pos++;
		if ((tar_pos_r - pos) <= 0)
		{
			temp = pos;
			tar_pos_r = row - 2 + temp;
		}
	}
	tar_pos_r = temp2;
	pos = 1;
	while ((target[pos] == mat[tar_pos_r][tar_pos_c + pos])|| ((tar_pos_c + pos) == col))
	{
		if (pos == length - 1)
		{
			keep_find = false;
			find_out = true;
			return 0;
		}
		pos++;
		if ((tar_pos_c + pos) >= col)
		{
			temp = pos;
			tar_pos_c = 1 - temp;
		}
	}
	tar_pos_c = temp3;
	pos = 1;
	while ((target[pos] == mat[tar_pos_r][tar_pos_c - pos])|| ((tar_pos_c - pos) == -1))
	{
		if (pos == length - 1)
		{
			keep_find = false;
			find_out = true;
			return 0;
		}
		pos++;
		if ((tar_pos_c - pos) <= 0)
		{
			temp = pos;
			tar_pos_c = col - 2 + temp;
		}
	}
	tar_pos_c = temp4;
	if ((start_row == row - 1) && (start_col == col - 1))
		keep_find = false;
	return 0;
}