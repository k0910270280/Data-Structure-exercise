#include<iostream>
#include<stack>
using namespace std;
void perm(int *, const int, const int);
void print(int *, const int);
int all_ans[80][15];
int total = 0;
int main()
{
	int n, target[20];
	if(cin >> n)
	{
		int *train = new int[n];
		for (int i = 0; i < n; i++)
			train[i] = i + 1;
		perm(train, 0, n);
		delete[]train;
	}
	while (cin >> target[0] && target[0] != -1)
	{
		for (int i = 1; i < n; i++)
			cin >> target[i];
		bool find = false;
		for (int j = 0; j < total; j++)
		{
			int i = 0;
			while(target[i] == all_ans[j][i])
			{
				i++;
				if (i == n - 1)
					find = true;
			}
			if (find)
			{
				cout << "YES" << endl;
				break;
			}
		}
		if (!find)
			cout << "NO" << endl;
	}
	system("pause");
}
void perm(int *a, const int k, const int n)
{
	if (k == n - 1)
		print(a, n);
	else
	{
		for (int i = k; i < n; i++)
		{
			char temp = a[k]; a[k] = a[i]; a[i] = temp;
			perm(a, k + 1, n);
			temp = a[k]; a[k] = a[i]; a[i] = temp;
		}
	}
}
void print(int *a, const int n)
{
	stack<int> s;
	int A = 1, B = 0;
	bool flag = true;
	while (B < n) {
		if (A == a[B]) { A++; B++; }
		else if (!s.empty() && a[B] == s.top()) {
			s.pop();
			B++;
		}
		else if (A <= n) {
			s.push(A);
			A++;
		}
		else {
			flag = false;
			break;
		}
	}
	if (flag) {
		for (int i = 0; i < n; i++)
			all_ans[total][i] = a[i];
		total++;
	}
}