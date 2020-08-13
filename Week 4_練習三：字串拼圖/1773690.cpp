#include "iostream"
#include "string"
#define max_size 20
using namespace std;
char mat[max_size][max_size], target[max_size];
int dim, start_row, start_col;
bool find_first(int, int);
int find_other(int, int, int);
bool deter(int, int);
bool keep_find, find_out;
int main()
{
	int length, total_input, count = 0;
	string input, result[10];
	cin >> dim;
	cin >> total_input;
	for (int i = 0; i < dim; i++)
		for (int j = 0; j < dim; j++)
			cin >> mat[i][j];
	while (count != total_input)
	{
		start_row = 0, start_col = 0, keep_find = true, find_out = false;
		cin >> input;
		length = input.length();
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
			result[count] = "Yes";
		else
			result[count] = "No";
		count++;
	}
	for (int i = 0; i < total_input; i++)
		cout << result[i] << endl;
	system("pause");
}
bool find_first(int tar_pos_r, int tar_pos_c)
{
	cout << endl << "find start" << endl;
	for (int i = tar_pos_r; i < dim; i++)
	{
		for (int j = tar_pos_c; j < dim; j++)
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
	int pos = 1, init_r = tar_pos_r, init_c = tar_pos_c;
	if (deter(tar_pos_r, pos))
		tar_pos_r = -pos;
	while (target[pos] == mat[tar_pos_r + pos][tar_pos_c])
	{
		cout << endl << "down" << endl;
		if (pos == length - 1)
		{
			keep_find = false;
			find_out = true;
			return 0;
		}
		pos++;
		if (deter(tar_pos_r, pos))
			tar_pos_r = -pos;
	}
	pos = 1;
	tar_pos_r = init_r;
	if (deter(tar_pos_r, -pos))
		tar_pos_r = dim;
	while (target[pos] == mat[tar_pos_r - pos][tar_pos_c])
	{
		if (pos == length - 1)
		{
			keep_find = false;
			find_out = true;
			return 0;
		}
		pos++;
		if (deter(tar_pos_r, -pos))
			tar_pos_r = dim + pos - 1;
	}
	pos = 1;
	tar_pos_r = init_r;
	if (deter(tar_pos_c, pos))
		tar_pos_c = -pos;
	while (target[pos] == mat[tar_pos_r][tar_pos_c + pos])
	{
		if (pos == length - 1)
		{
			keep_find = false;
			find_out = true;
			return 0;
		}
		pos++;
		if (deter(tar_pos_c, pos))
			tar_pos_c = -pos;
	}
	pos = 1;
	tar_pos_c = init_c;
	if (deter(tar_pos_c, -pos))
		tar_pos_c = dim;
	while ((target[pos] == mat[tar_pos_r][tar_pos_c - pos]))
	{
		if (pos == length - 1)
		{
			keep_find = false;
			find_out = true;
			return 0;
		}
		pos++;
		if (deter(tar_pos_c, -pos))
			tar_pos_c = dim - 1 + pos;
	}
	return 0;
}
bool deter(int now, int pos)
{
	if (now + pos >= dim)
		return true;
	else if (now + pos < 0)
		return true;
	else
		return false;
}