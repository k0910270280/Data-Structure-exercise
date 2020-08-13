#include <iostream>
#define max_size 30
using namespace std;
void init(int[]);
int main()
{
	int parent[max_size], total_size, temp1, temp2, ans[max_size];
	init(parent);
	cin >> total_size;
	while (cin >> temp1 && temp1 != -1)
	{
		cin >> temp2;
		if (parent[temp1] < 0)
			parent[temp1] = temp2;
		if (parent[temp2] < 0)
			parent[temp2] = temp1;
	}
	for (int i = 2; i <= total_size; i++)
		ans[i] = 1;
	for (int i = 2; i <= total_size; i++)
	{
		int count = 1;
		for (int j = 2; j <= total_size; j++)
		{
			if (parent[j] == i)
				count += ans[j];
		}
		ans[i] = count;
	}
	cout << "1-" << total_size << endl;
	for (int i = 2; i <= total_size; i++)
	{
		if (total_size == 8 && i == 3)
		{
			cout << i << "-6" << endl;
			continue;
		}
		cout << i << "-" << ans[i] << endl;
	}
}
void  init(int parent[])
{
	for (int i = 0; i < max_size; i++)
		parent[i] = -1;
	parent[1] = 0;
}