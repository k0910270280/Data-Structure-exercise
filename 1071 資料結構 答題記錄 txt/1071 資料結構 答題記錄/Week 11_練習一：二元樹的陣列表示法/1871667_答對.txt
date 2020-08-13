#include <iostream>
#define max_size 50
using namespace std;
void input(int[], int, int, int);
int mat[max_size] = { 0 }, max_index = 0;
int main()
{
	bool conti = true;
	int trash, upper, left, right;
	cin >> trash >> upper >> left >> right;
	mat[1] = upper, mat[2] = left, mat[3] = right;
	while (cin >> upper && upper != -1)
	{
		cin >> left >> right;
		input(mat, upper, left, right);
	}
	for (int i = 1; i < max_index; i++)
		cout << mat[i] << " ";
	cout << mat[max_index] << endl;
}
void input(int mat[], int upper, int left, int right)
{
	int target_index;
	for (int i = 1; i < max_size; i++)
		if (mat[i] == upper)
			target_index = i;
	mat[target_index * 2] = left;
	mat[target_index * 2 + 1] = right;
	if (max_index < (target_index * 2 + 1))
		max_index = target_index * 2 + 1;
}