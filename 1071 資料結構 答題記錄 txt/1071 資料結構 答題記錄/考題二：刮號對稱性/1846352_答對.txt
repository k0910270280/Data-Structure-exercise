#include <iostream>
#include "string"
#include "stack"
using namespace std;
int main()
{
	string str;

	while (cin >> str && str != "end")
	{
		int count = 0;
		stack <char> s;
		for (int index = 0; index < str.length(); index++)
		{
		if (str[index] == '(')
			s.push('(');
		if (s.empty())
			break;
		if (str[index] == ')')
			s.pop();
		count++;
		}
		if (count == str.length() && s.empty())
			cout << "1" << endl;
		else
			cout << "-1" << endl;
	}
}