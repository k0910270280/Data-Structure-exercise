#include <iostream>
using namespace std;
int Fibonacci(int);
int main()
{
	int temp;
	cin >> temp;
	cout<<Fibonacci(temp-1);
	system("pause");
}
int Fibonacci(int x)
{
	if (x <= 1) {
		return 1;
	}
	return Fibonacci(x - 1) + Fibonacci(x - 2);
}