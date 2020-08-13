#include <iostream>
#include "string"
#include "stack"
using namespace std;
int main()
{
	stack<char> s;
	string str;
	int count = 0;
	while (cin >> str&&str!="end")
	{
		for (int i = 0; i < str.length(); i++)
		{
			if (str[i] == '(')
				s.push('(');
			if (s.empty())
			{
				break;
			}
			if (str[i] == ')')
				s.pop();
			count++;
		}
		if (s.empty() && count == str.length())
			cout << "1" << endl;
		else
			cout << "-1" << endl;
	}
	system("pause");
}