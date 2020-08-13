#include "pch.h"
#include "iostream"
#define max_size 500
using namespace std;
int main()
{
	int list[max_size], ans[max_size], a, b, total = 0;
	cin >> a >> b;
	for (int l = a + 1; l < b; l++)
	{
		list[total++] = l;
	}
	int  th = 0, index = 0;
	while (th <= total)
	{
		int i, m, sum = 0;
		i = list[th];
		m = i;
		while (i)
		{
			sum = sum * 10 + i % 10;
			i /= 10;
		}
		if (sum == m)
			ans[index++] = list[th];
		th++;
	}
	for (int j = 0; j < index - 1; j++)
		cout << ans[j] << " ";
	cout << ans[index - 1];
	system("pause");
	return 0;
}