#include <iostream>
using namespace std;
int insertsort(int[],int);
int main(void)
{
	int *list = NULL,total=0;
	cin >> total;
	list = new int [total];
	for (int i = 0; i < total; i++)
		cin >> list[i];
	insertsort(list, total);
	for (int i = 0; i < total; i++)
		cout << list[i] << " " ;
        cout<<endl;
	system("pause");
}

int insertsort(int list[], int total)
{
	for (int i = 1; i < total; i++)
	{
		int target = list[i];
		int next = i;
		while ((next > 0) && (target < list[next-1]))
		{
			list[next] = list[next - 1];
			next--;
		}
		list[next] = target;
	}
	return *list;
}