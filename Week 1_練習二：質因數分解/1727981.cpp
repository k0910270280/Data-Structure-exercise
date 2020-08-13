#include "pch.h"
#include <iostream>
using namespace std;

int main()
{
	int num,i=2,count=0;
	cin >> num;
	for (i; i <= num; i++)
	{
		while ((num%i) == 0)
		{
			num = (num / i);
			count++;
		}
		if (count != 0)
		{
			if (count == 1)
				cout << i;
			if (count != 1)
			{
				cout << i << "^" << count;
			}
			if (num == 1)
			{
				break;
			}
			cout << " * ";
		}
		count = 0;
	}
	system("pause");
}