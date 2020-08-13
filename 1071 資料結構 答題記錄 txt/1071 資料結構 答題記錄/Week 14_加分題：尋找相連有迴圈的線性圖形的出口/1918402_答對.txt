#include <iostream>
#define max_size 50
using namespace std;
int main()
{
	char temp, a[max_size], size = 0, as[123] = { 0 };
	while (cin >> temp && !cin.eof())
		a[size++] = temp;
	for (int i = 0; i < size; i++)
		as[a[i]]++;
	int ans[10], ans_size = 0;
	for (int i = 0; i < 123; i++)
		if (as[i] == 1)
			ans[ans_size++] = i;
	if (ans_size == 2)
		cout << (char)ans[0] <<" "<< (char)ans[1] << endl;
	else
		cout << "null" << endl;
}