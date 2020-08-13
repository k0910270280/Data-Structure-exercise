#include <iostream>
#define max_size 100
using namespace std;
int judge(int[], int, int, int);
int findmax(int[], int);
int main(void)
{
	int list[max_size] = { 0 }, total = 1, save_conti[max_size] = { 0 },max_index;
	cin >> list[0];
	while (cin.get() != '\n')
	{
		total++;
		cin >> list[total-1];
	}
	for (int i = 0; i < total; i++)
		save_conti[i] = judge(list, total, i, 1);
	max_index = findmax(save_conti, total);
	for (int i = 0; i < save_conti[max_index]-1; i++)
		cout << list[max_index + i]<<",";
	cout << list[save_conti[max_index]] << endl;
	system("pause");
}
int judge(int list[], int total,int count,int sum) 
{
	if (list[count] <= list[count + 1])
	{
		count++;
		sum++;
		return judge(list, total, count,sum);
	}
	else
		return sum;
}
int findmax(int list[], int total)
{
	int max = list[0], index = 0;
	for (int i = 0; i < total; i++)
	{
		if (max < list[i])
		{
			max = list[i];
			index = i;
		}
	}
	return index;
}