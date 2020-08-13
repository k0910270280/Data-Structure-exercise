#include <iostream>
using namespace std;
int layer(int);
int main(void)
{
	int many;
	cin >> many;
	int output = layer(many);
	cout << output << endl;
	return 0;
}


int layer(int many) {
	if (many == 0)
		return 0;
	else if (many == 1)
		return 1;
	else if (many == 2)
		return 2;
	else if (many > 2)
		return layer(many - 1) + layer(many - 2);
}