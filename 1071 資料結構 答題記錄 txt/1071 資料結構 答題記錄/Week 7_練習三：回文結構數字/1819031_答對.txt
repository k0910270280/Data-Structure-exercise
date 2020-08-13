#include "iostream"
#define max_size 500
using namespace std;
int main()
{
	int list[max_size], ans[max_size] = {0}, a, b, total = 0;
	cin >> a >> b;
	for (int l = a + 1; l < b; l++)
	{
		list[total++] = l;
	}
	int  th = 0, index = 0;
	while (th < total)
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
	for (int j = 0; j < index; j++)
		cout << ans[j] << " ";
	cout << endl;
	system("pause");
	return 0;
}