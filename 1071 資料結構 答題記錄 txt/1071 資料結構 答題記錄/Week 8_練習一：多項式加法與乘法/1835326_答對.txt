#include <iostream>
using namespace std;
typedef struct polynode *polypointer;
struct polynode {
	int expon;
	float coef;
	polypointer link;
};
polypointer padd(polypointer, polypointer);
polypointer mult(polypointer, polypointer);
void attach(int, float, polypointer*);
void sort(polypointer);
void print(polypointer);
void input(polypointer);
int compare(int a, int b);
int main()
{
	polypointer a, b, r1, r2;
	a = new polynode;
	b = new polynode;
	input(a);
	sort(a);
	input(b);
	sort(b);
	cout << "add = ";
	r1 = padd(a, b);
	print(r1);
	cout << "mult = ";
	r2 = mult(a, b);
	print(r2);
	system("pause");
}
polypointer mult(polypointer a, polypointer b)
{
	polypointer temp_a = a, temp_b = b, res_front, res_rear;
	res_rear = new polynode;
	res_front = res_rear;
	int expon;
	float coef;
	for (; temp_a; temp_a = temp_a->link)
	{
		expon = temp_a->expon + temp_b->expon;
		coef = (temp_a->coef)*(temp_b->coef);
		attach(expon, coef, &res_rear);
	}
	res_rear->link = NULL;
	res_front = res_front->link;
	temp_a = a;
	temp_b = temp_b->link;
	for (; temp_b; temp_b = temp_b->link)
	{
		polypointer front_r, rear_r;
		front_r = new polynode;
		rear_r = front_r;
		for (; temp_a; temp_a = temp_a->link)
		{
			expon = temp_a->expon + temp_b->expon;
			coef = (temp_a->coef)*(temp_b->coef);
			attach(expon, coef, &rear_r);
		}
		rear_r->link = NULL;
		front_r = front_r->link;
		temp_a = a;
		res_front = padd(res_front, front_r);
	}
	return res_front;
}
polypointer padd(polypointer a, polypointer b)
{
	polypointer front, rear, temp;
	float sum;
	rear = new polynode;
	front = rear;
	while (a&&b)
	{
		switch (compare(a->expon, b->expon))
		{
		case 1:
			attach(a->expon, a->coef, &rear);
			a = a->link;
			break;
		case 0:
			sum = a->coef + b->coef;
			if (sum != 0)
				attach(a->expon, sum, &rear);
			a = a->link;
			b = b->link;
			break;
		case -1:
			attach(b->expon, b->coef, &rear);
			b = b->link;
			break;
		}
	}
	for (; a; a = a->link)
		attach(a->expon, a->coef, &rear);
	for (; b; b = b->link)
		attach(b->expon, b->coef, &rear);
	rear->link = NULL;
	temp = front;
	front = front->link;
	delete temp;
	return front;
}
void attach(int exponent, float coefficient, polypointer *ptr)
{
	polypointer temp;
	temp = new polynode;
	temp->coef = coefficient;
	temp->expon = exponent;
	(*ptr)->link = temp;
	*ptr = temp;
}
int compare(int a, int b)
{
	if (a > b)
		return 1;
	else if (a < b)
		return -1;
	else
		return 0;
}
void print(polypointer poly)
{
	cout << poly->coef << "x^" << poly->expon;
	while (poly->link)
	{
		poly = poly->link;
		if (poly->coef > 0)
		{
			if (poly->expon == 1)
				cout << " + " << poly->coef << "x^1";
			else if (poly->expon == 0)
				cout << " + " << poly->coef;
			else
				cout << " + " << poly->coef << "x^" << poly->expon;
		}
		else
		{
			if (poly->expon == 1)
				cout << poly->coef << "x^1";
			else if (poly->expon == 0)
				cout << poly->coef;
			else
				cout << poly->coef << "x^" << poly->expon;
		}
	}
	cout << endl;
}
void input(polypointer poly)
{
	int expon;
	float coef, judge;
	cin >> coef >> expon;
	poly->expon = expon;
	poly->coef = coef;
	while (true)
	{
		polypointer temp;
		temp = new polynode;
		cin >> judge;
		if (judge == -1)
			break;
		coef = judge;
		cin >> expon;
		temp->expon = expon;
		temp->coef = coef;
		poly->link = temp;
		poly = poly->link;
		temp->link = NULL;
	}
}
void sort(polypointer poly)
{
	polypointer i, j;
	float coef_tp;
	int  expon_tp;
	for (i = poly; i; i = i->link)
	{
		for (j = poly; j; j = j->link)
		{
			if ((i->expon) > (j->expon))
			{
				expon_tp = i->expon;
				i->expon = j->expon;
				j->expon = expon_tp;
				coef_tp = i->coef;
				i->coef = j->coef;
				j->coef = coef_tp;
			}
		}
	}
}