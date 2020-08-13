#include <iostream>
#include "cmath"
using namespace std;
int main()
{
	int temp,sum = 1;
	while (cin >> temp && cin.get() != '\n')
		sum++;
	cout << ceil(log2(sum)) << endl;
}