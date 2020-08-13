#include <iostream>
#define max_size 30
using namespace std;
struct input {
	int data[2];
};
int main()
{
	int total_node, temp, size = 0, not_one[max_size] = { 0 }, not_size = 0, many[max_size], many_size = 0, ans[max_size], ans_size = 0;
	input tree[max_size];
	cin >> total_node;
	while (cin >> temp && temp != -1)
	{
		tree[size].data[0] = temp;
		cin >> tree[size++].data[1];
	}
	for (int i = 0; i < size; i++)
		if (not_one[tree[i].data[0]] == 0)
		{
			not_one[tree[i].data[0]] = 1;
			not_size++;
		}
	for (int i = 0; i < size; i++)
		if (not_one[i] != 0)
			many[many_size++] = i;
	for (int index = 0; index < many_size; index++)
	{
		int count = 1;
		bool start = false;
		for (int i = 0; i < size; i++)
		{
			if (tree[i].data[0] == many[index])
				start = true;
			if (start)
				count++;
		}
		ans[ans_size++] = count;
	}
	int count = 0;
	for (int i = 1; i <= size + 1; i++)
	{
		if (not_one[i] != 1)
			cout << i << "-1" << endl;
		else
			cout << i << "-" << ans[count++] << endl;
	}
}