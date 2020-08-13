#include <iostream>
#include "string"
using namespace std;
int main()
{
	int  count = 1, max = 0;
	string input;
	cin >> input;
	for (int i = 0; i < input.length(); i++)
	{
		if (input[i] == '(')
			count++;
		if (input[i] == ')')
			count--;
		if (count > max)
			max = count;
	}
	cout << max << endl;






















}