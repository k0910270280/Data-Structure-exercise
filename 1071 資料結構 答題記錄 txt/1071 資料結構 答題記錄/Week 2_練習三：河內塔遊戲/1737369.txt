#include <iostream>
using namespace std;
void Move(int,char,char,char);
int main(void)
{
	int layer;
	cout << "input layer:";
	cin >> layer;
	Move(layer,'A','B','C');
	return 0;
}

void Move(int layer, char from, char temp, char dest)
{
	if (layer != 0)
	{
		Move(layer - 1, from, dest, temp);
		cout << layer << endl;
		Move(layer - 1, temp, from, dest);
	}
}