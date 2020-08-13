#include <iostream>
#define max_size 100
using namespace std;
struct ploy {
	int expon;
	float coef;
} terms[max_size];
int total_a, total_b, pos[50], avail;
void read(int, int);
void print(int, int);
int compare(int, int);
void attach(float, int);
void padd(int, int, int, int);
void product(void);
void sort(void);
void combine(void);
int main()
{
	cin >> total_a;
	pos[0] = 0;
	pos[1] = total_a - 1;
	read(pos[0], pos[1]);
	cin >> total_b;
	pos[2] = pos[1] + 1;
	pos[3] = pos[2] + total_b - 1;
	avail = pos[3] + 1;
	read(pos[2], pos[3]);
	print(pos[0], pos[1]);
	print(pos[2], pos[3]);
	padd(pos[0], pos[1], pos[2], pos[3]);
	pos[4] = pos[3] + 1;
	pos[5] = avail - 1;
	product();
	sort();
	pos[8] = pos[7] + 1;
	combine();
	pos[9] = avail - 1;
	print(pos[8], pos[9]);
	system("pause");
}
void product(void)
{
	for (int x = pos[2]; x <= pos[3]; x++)
	{
		for (int y = pos[4]; y <= pos[5]; y++)
		{
			terms[avail].coef = terms[x].coef*terms[y].coef;
			terms[avail].expon = terms[x].expon + terms[y].expon;
			avail++;
		}
	}
	pos[6] = pos[5] + 1;
	pos[7] = avail - 1;
}
void sort(void)
{
	int temp1;
	float temp2;
	for (int x = pos[6]; x <= pos[7]; x++)
	{
		for (int y = pos[6]; y <= pos[7]; y++)
		{
			if (terms[x].expon >= terms[y].expon)
			{
				temp1 = terms[x].expon;
				terms[x].expon = terms[y].expon;
				terms[y].expon = temp1;
				temp2 = terms[x].coef;
				terms[x].coef = terms[y].coef;
				terms[y].coef = temp2;
			}
		}
	}
}
void combine(void)
{
	for (int x = pos[6]; x <= pos[7]; x++)
	{
		if (terms[x].expon == terms[x + 1].expon)
			terms[x + 1].coef += terms[x].coef;
		else
		{
			terms[avail].expon = terms[x].expon;
			terms[avail].coef = terms[x].coef;
			avail++;
		}
	}
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
			else if (terms[i].expon == 1)
				printf(" +%.2fx", terms[i].coef);
			else
				printf(" +%.2fx^%d", terms[i].coef, terms[i].expon);
		}
		else
		{
			if (terms[i].expon == 0)
				printf(" %.2f", terms[i].coef);
			else if (terms[i].expon == 1)
				printf(" %.2fx", terms[i].coef);
			else
				printf(" %.2fx^%d", terms[i].coef, terms[i].expon);
		}
	}
	cout << endl;
}
void padd(int start_a, int end_a, int start_b, int end_b)
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
			float result;
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