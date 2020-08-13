#include <iostream>
#define max_size 100
using namespace std;
struct ploy{
	int expon;
	float coef;
} ;
ploy terms[max_size];
int total_a, total_b, start_a = 0, end_a, start_b, end_b, avail;
void read(int, int);
void print(int, int);
int compare(int, int);
void attach(float, int);
void padd();
int main()
{
	cin >> total_a;
	end_a = total_a - 1;
	read(start_a, end_a);
	cin >> total_b;
	start_b = total_a;
	end_b = start_b + total_b - 1;
	avail = end_b + 1;
	read(start_b, end_b);
	print(start_a, end_a);
	print(start_b, end_b);
	padd();
	print(end_b + 1, avail - 1);
	system("pause");
}
void read(int start, int end)
{
	for (int i = start; i <= end; i++)
	{
		cin >> terms[i].coef;
		cin >> terms[i].expon;
	}
}
void print(int start, int end)
{
	printf("%.2fx^%d", terms[start].coef, terms[start].expon);
	for (int i = start + 1; i <= end; i++)
	{
		if (terms[i].coef > 0)
		{
			if (terms[i].expon == 0)
				printf(" +%.2f", terms[i].coef);
			else
				printf(" +%.2fx^%d", terms[i].coef, terms[i].expon);
		}
		else
		{
			if (terms[i].expon == 0)
				printf(" %.2f", terms[i].coef);
			else
				printf(" %.2fx^%d", terms[i].coef, terms[i].expon);
		}
	}
	cout << endl;
}
void padd(void)
{
	int cur_a = start_a, cur_b = start_b;
	while ((cur_a <= end_a) && (cur_b <= end_b))
	{
		switch (compare(terms[cur_a].expon, terms[cur_b].expon))
		{
		case 1:
			attach(terms[cur_a].coef, terms[cur_a].expon);
			cur_a++;
			break;
		case 0:
			int result;
			result = terms[cur_a].coef + terms[cur_b].coef;
			if (result != 0)
				attach(result, terms[cur_a].expon);
			cur_a++;
			cur_b++;
			break;
		case -1:
			attach(terms[cur_b].coef, terms[cur_b].expon);
			cur_b++;
			break;
		}
		if (cur_b > end_b)
		{
			for (int x = cur_a; x <= end_a; x++)
				attach(terms[x].coef, terms[x].expon);
		}
		else if (cur_a > end_a)
		{
			for (int x = cur_b; x <= end_b; x++)
				attach(terms[x].coef, terms[x].expon);
		}
	}
}
void attach(float coef, int expon)
{
	terms[avail].coef = coef;
	terms[avail++].expon = expon;
}
int compare(int x, int y)
{
	if (x > y)
		return 1;
	else if (x == y)
		return 0;
	else
		return -1;
}