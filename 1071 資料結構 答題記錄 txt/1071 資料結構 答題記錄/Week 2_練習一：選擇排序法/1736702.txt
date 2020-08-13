#include <iostream>
using namespace std;
int main()
{
	int dim = 0, *ptr,temp;
	cin >> dim;
	ptr = new int[dim];
	for (int i = 0; i < dim; i++)
		cin >> ptr[i];
	for (int j = 0; j < dim; j++)
	{
		for (int i = 0; i < dim; i++)
		{
			if (ptr[j] < ptr[i])
			{
				temp = ptr[j];
				ptr[j] = ptr[i];
				ptr[i] = temp;
			}
		}
	}
	for (int i = 0; i < (dim-1); i++)
	{
		cout << ptr[i] << " ";
	}
	cout << ptr[dim - 1];
	system("pause");
}