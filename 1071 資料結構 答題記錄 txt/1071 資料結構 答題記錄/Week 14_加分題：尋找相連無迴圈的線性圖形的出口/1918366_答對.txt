#include <iostream>
#define max_size 50
using namespace std;
int main()
{
	char temp, a[max_size], size = 0;
	while (cin >> temp && !cin.eof())
		a[size++] = temp;
	for (int i = 0; i < size; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			if (a[j] < a[i])
			{
				char pTem = a[j];
				a[j] = a[i];
				a[i] = pTem;
			}
		}
	}
	bool success = true;
	for (int i = 1; i < size - 1; i = i + 2)
		if (a[i] != a[i + 1])
			success = false;
	if (success)
		cout << a[0] << " " << a[size - 1] << endl;
	else
		cout << "null" << endl;
}