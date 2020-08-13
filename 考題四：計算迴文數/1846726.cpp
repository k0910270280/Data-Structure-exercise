#include <iostream>
#include "string"
#include "sstream"
using namespace std;
int str_to_num(string);
string num_to_str(int);
int Re_Add(string[],int);
bool judge(int);
int main()
{
	bool find, alt = false;
	int result, count = 0;
	string in, input[100];
	cin >> in;
	int temp = str_to_num(in);
	find = judge(temp);
	in = num_to_str(temp);
	if (find)
	{
		cout << in << endl;
		alt = true;
	}
	while (count < 50 && !find)
	{
		for (int i = 0; i < in.length(); i++)
			input[i] = in[i];
		result = Re_Add(input, in.length());
		find = judge(result);
		if (find)
			break;
		in = num_to_str(result);
		count++;
	}
	if (find&&!alt)
		cout << result << endl;
}
bool judge(int res)
{
	bool find = false;
	string result;
	result = num_to_str(res);
	int front = 0, rear = result.length() - 1;
	while (result[front] == result[rear])
	{
		if (front == rear || front == result.length() - 1)
		{
			find = true;
			break;
		}
		front++; rear--;
	}
	return find;
}
int Re_Add(string num1[],int size)
{
	string num2[100];
	int index = 0, sum = 0;
	for (int i = size - 1; i >= 0; i--)
		num2[index++] = num1[i];
	for (int i = 0; i < size; i++)
		sum +=(str_to_num(num2[i])+str_to_num(num1[i]))*pow(10,size - 1 - i);
	return sum;
}
int str_to_num(string str)
{
	int num;
	istringstream ss(str);
	ss >> num;
	return num;
}
string num_to_str(int num)
{
	stringstream s;
	s << num;
	return s.str();
}