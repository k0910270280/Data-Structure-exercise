#include <iostream>
#define max_size 20
using namespace std;
static int preindex = 0;
void printpost(int[], int[], int, int);
int search(int[], int, int, int);
int main()
{
	int in[max_size], pre[max_size], len = 0;
	cin >> pre[len++];
	while (cin.get() != '\r')
		cin >> pre[len++];
	for (int i = 0; i < len; i++)
		cin >> in[i];
	printpost(in, pre, 0, len - 1);
}
void printpost(int in[], int pre[], int instrt, int inend)
{
	if (instrt > inend)
		return;
	int inindex = search(in, instrt, inend, pre[preindex++]);
	printpost(in, pre, instrt, inindex - 1);
	printpost(in, pre, inindex + 1, inend);
	cout << in[inindex];
	if (inindex != inend)
		cout << " ";
}
int search(int in[], int startin, int endin, int data)
{
	int i = 0;
	for (i = startin; i < endin; i++)
		if (in[i] == data)
			return i;
	return i;
}