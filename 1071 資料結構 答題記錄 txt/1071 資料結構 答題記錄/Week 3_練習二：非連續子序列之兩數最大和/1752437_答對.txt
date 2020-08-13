#include <iostream>
using namespace std;
int findmax(int[], int);
int main(void)
{
	int *list = NULL,total=0,max_index,max1,max2;
	cin >> total;
	list = new int [total];
	for (int i = 0; i < total; i++)
		cin >> list[i];
	max_index = findmax(list, total);
	max1 = list[max_index];
	list[max_index] = 0;
	list[max_index - 1] = 0;
	list[max_index + 1] = 0;
	max_index = findmax(list, total);
	max2 = list[max_index];
	cout << max1 + max2 << endl;
	system("pause");
}

int findmax(int list[],int total)
{
	int max = list[0],index=0;
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