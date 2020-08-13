#include <iostream>
#include "string"
#include "sstream"
#define max_size 30
using namespace std;
int transfer(string);
struct stack {
public:
	stack(int cap) { capacity = cap; t = -1; ptr = new string[capacity]; }
	void push(string x) { ptr[++t] = x; }
	void pop() { t--; }
	string top() { return ptr[t]; }
	bool empty() { return (t == -1); }
private:
	string *ptr;
	int t;
	int capacity;
};
int main()
{
	string input, list[max_size], temp;
	stack s(20);
	int total = 0;
	getline(cin, input);
	istringstream new_input(input);
	while (getline(new_input, temp, ' '))
		list[total++] = temp;

	int index = 0, num1, num2;
	while (index < total)
	{
		string target = list[index++];
		if (target == "+" || target == "-" || target == "*" || target == "/" || target == "%")
		{
			num1 = transfer(s.top()); s.pop();
			num2 = transfer(s.top()); s.pop();
			if (target == "+")
				s.push(to_string(num2 + num1));
			else if (target == "-")
				s.push(to_string(num2 - num1));
			else if (target == "*")
				s.push(to_string(num2 * num1));
			else if (target == "/")
				s.push(to_string(num2 / num1));
			else if (target == "%")
				s.push(to_string(num2 % num1));
		}
		else
		{
			s.push(target);
		}
	}
	cout << transfer(s.top()) << endl;
}
int transfer(string str)
{
	int num;
	string new_str;
	istringstream is(str);
	is >> num;
	return num;
}