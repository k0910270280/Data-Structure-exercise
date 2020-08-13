#include <iostream>
using namespace std;
int F(int);
int main()
{
	int temp;
	cin >> temp;
	cout << F(temp - 1) << endl;
}
int F(int x)
{
	if (x <= 1)
		return 1;
	return F(x - 1) + F(x - 2);
}