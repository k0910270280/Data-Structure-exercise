#include <iostream>
#include "stack"
#include "string"
#define max_size 20
using namespace std;
struct table {
	short int hori;
	short int vert;
} mov[4];
char maze[max_size][max_size];
stack <int> row, col, dir;
void table_init();
void print();
int main()
{
	int mark[max_size][max_size] = { 0 };
	string temp;
	for (int i = 0; i < 10; i++)
	{
		getline(cin, temp);
		for (int j = 0; j < 10; j++)
			maze[i][j] = temp[2 * j];
	}

	row.push(8);
	col.push(8);
	dir.push(0);
	table_init();

	bool success = false;
	int start = 0;
	while (success == false)
	{
		bool dir_find = false;
		if (row.top() == 1 && col.top() == 1)
		{
			success = true; break;
		}
		if ((maze[8][7] == 'D' || maze[8][7] == '1') && (maze[7][8] == 'D' || maze[7][8] == '1'))
			break;
		for (int i = start; i < 4; i++)
		{
			int next_row = row.top() + mov[i].vert;
			int next_col = col.top() + mov[i].hori;
			if ((maze[next_row][next_col] == '0') && (mark[next_row][next_col] == 0))
			{
				mark[next_row][next_col] = 1;
				dir.push(i);
				row.push(next_row);
				col.push(next_col);
				start = 0; dir_find = true; break;
			}
		}
		if (dir_find == false)
		{
			maze[row.top()][col.top()] = 'D';
			row.pop();
			col.pop();
			start = dir.top() + 1;
			dir.pop();
		}
	}
	if (success == true)
	{
		cout << "YES" << endl;
		while (!row.empty() && !col.empty())
		{
			maze[row.top()][col.top()] = 'G';
			row.pop();
			col.pop();
		}
	}
	else
		cout << "NO" << endl;
	maze[8][8] = 'S';
	maze[1][1] = 'X';
	print();
	system("pause");
}
void table_init()
{
	mov[0].hori = 1;	mov[0].vert = 0;
	mov[1].hori = 0;	mov[1].vert = -1;
	mov[2].hori = -1;	mov[2].vert = 0;
	mov[3].hori = 0;	mov[3].vert = 1;
}
void print()
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
			cout << maze[i][j];
		cout << endl;
	}
}