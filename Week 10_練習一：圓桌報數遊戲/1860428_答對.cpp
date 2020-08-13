#include <iostream>
using namespace std;
int main()
{
	int n, a, b, count, num, out, x, ans;
	while (cin >> n >> a >> b)
	{
		out = 0;
		x = a;
		int *people = new int[n];
		for (int i = 0; i < n; i++)
			people[i] = 1;
		if (x != 0)
			num = x - 2;
		else
			num = x - 1;
		while (out != n)
		{
			for (int i = 0; i < n; i++)
			{
				ans = 0;
				if (out > 0)
					num = x - 1;
				count = 0;
				while (count != b + 1)
				{
					if (out == n - 1 && ans == 1)
						break;
					if (num < n - 1)
						num++;
					else
						num = 0;
					if (people[num] != 0)
						count++;
					if (count == b && ans == 0)
					{
						if (out > 0)
							cout << " ";
						cout << num + 1;
						people[num] = 0;
						ans = 1;
					}
				}
				x = num;
				out++;
			}
		}
		cout << endl;
	}
	return 0;
}