#include <iostream>     
#include "string"     
using namespace std;
char input[80] = { NULL }, output[10][80];
int siz, s[10];
void A(int, int);
void B(int, int);
void C(int, int);
int main()
{
	string temp;
	int n, th = 0, count;
	cin >> n;
	count = n;
	while (count != 0)
	{
		cin >> temp;
		siz = temp.size();
		for (int i = 0; i < siz; i++)
			input[i] = temp[i];
		for (int i = 0; i < siz; i++)
		{
			if (input[i] == 'a')
				A(i + 1, siz - 1);
			if (input[i] == 'b')
				B(i + 1, siz - 1);
			if (input[i] == 'c')
				C(i + 1, siz - 1);
		}
		for (int i = 0; i < siz; i++)
		{
			output[th][i] = input[i];
		}
		s[th++] = siz;
		count--;
	}
	for (int j = 0; j < n; j++)
	{
		for (int i = 0; i < s[j]; i++)
		{
			if(output[j][i]!=NULL)
				cout << output[j][i];
		}
		cout << endl;
	}
	system("pause");
}
void A(int from, int end)
{
	char temp[50];
	int index = 0;
	for (int i = end; i >= from; i--)
		temp[index++] = input[i];
	for (int i = 0; i <= index; i++)
		input[from + i] = temp[i];
}
void B(int from, int end)
{
	int index = end + 1;
	for (int i = from; i <= end; i++)
		input[index++] = input[i];
	siz = index;
}
void C(int from, int end)
{
	if (from == end) {
		siz -= 1; return;
	}
	for (int i = from; i < end - 1; i++)
		input[i] = input[i + 2];
	input[end] = NULL;
	input[end - 1] = NULL;
}