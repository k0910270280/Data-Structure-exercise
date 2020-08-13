#include "pch.h"
#include <iostream>
#include "cmath"
using namespace std;
int main()
{
	int temp,sum = 2;
	while (cin >> temp && cin.get() != '\n')
		sum++;
	cout << ceil(sum);
}