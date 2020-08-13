#include <iostream>
using namespace std;
int Fibo(int);
int main()
{
	int temp;
	cin >> temp;
	cout << Fibo(temp - 1) << endl;
	system("pause");
}
int Fibo(int x)
{
	if (x <= 1) {
		return 1;
	}
	return Fibo(x - 1) + Fibo(x - 2);
}