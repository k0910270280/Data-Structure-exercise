#include <iostream>
#include "string"
#include "sstream"
#include "queue"
#define max_size 50
using namespace std;

int transfer(string);
void Union(int[], queue<int>, int);
bool find(int[], queue<int>);
void print(int[], int);

int main()
{
	int mat[max_size], size;
	string input;
	queue <int> q;
	cin >> size;
	for (int i = 0; i <= size; i++)
		mat[i] = -1;
	while (true)
	{
		getline(cin, input);
		if (input[0] == 'U')
		{
			int count = 0;
			for (int i = 0; i < input.length(); i++)
			{
				if (48 <= (int)input[i] && (int)input[i] < 58)
					count++;
				if (input[i] == ',' || input[i] == ')')
				{
					q.push(transfer(input.substr(i - count, count)));
					count = 0;
				}
			}
			Union(mat, q, size);	q.pop(); q.pop();
			cout << input << ":";
			print(mat, size);
			cout << endl;
		}
		if (input[0] == 'F')
		{
			int count = 0;
			for (int i = 0; i < input.length(); i++)
			{
				if (48 <= (int)input[i] && (int)input[i] < 58)
					count++;
				if (input[i] == ')')
				{
					q.push(transfer(input.substr(i - count, count)));
					count = 0;
				}
			}
			cout << input << ": ";
			if (find(mat, q))
				cout << "Yes" << endl;
			else
				cout << "No" << endl;
			q.pop();	q.pop();
		}
		if (input == "-1")
			break;
	}
}

void Union(int mat[], queue<int> q, int size)
{
	int first = q.back();
	int second = q.front();	q.pop(); q.pop();
	while (mat[first] >= 0)
		first = mat[first];
	while (mat[second] >= 0)
		second = mat[second];
	int total_node = mat[first] + mat[second];
	if (mat[first] >= mat[second])
	{
		for (int i = 0; i < size; i++)
			if (mat[i] == first)
				mat[i] = second;
		mat[first] = second;
		mat[second] = total_node;
	}
	else
	{
		for (int i = 0; i < size; i++)
			if (mat[i] == second)
				mat[i] = first;
		mat[second] = first;
		mat[first] = total_node;
	}
}

void print(int mat[], int size)
{
	queue <int> q;
	for (int i = 0; i < size; i++)
	{
		if (mat[i] < 0)
			q.push(i);
	}
	cout << endl;
	while (!q.empty())
	{
		cout << " {";
		int target = q.front(); q.pop();
		cout << target;
		for (int i = 0; i < size; i++)
			if (target == mat[i])
				cout << "," << i;
		cout << "}";
	}
}

bool find(int mat[], queue <int> q)
{
	int first = q.front();	q.pop();
	int second = q.front();	q.pop();
	if (mat[first] < 0 && mat[second] < 0);
	else if (mat[first] < 0)
	{
		if (first == mat[second])
			return true;
	}
	else if (mat[second] < 0)
	{
		if (mat[first] == second)
			return true;
	}
	else
	{
		if (mat[first] == mat[second])
			return true;
	}
	return false;
}

int transfer(string str)
{
	int number;
	stringstream ss(str);
	ss >> number;
	return number;
}