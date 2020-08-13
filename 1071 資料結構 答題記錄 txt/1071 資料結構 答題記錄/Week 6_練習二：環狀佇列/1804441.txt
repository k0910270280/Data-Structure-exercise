//#include "pch.h"
#include <iostream>
using namespace std;
struct queue {
public:
	void push(int);
	void pop();
	void put_capacity(int);
private:
	int front = 0, rear = 0, capacity;
	static int *que = new int[80];
} q;
int main()
{
	int cap, act, input;
	cin >> cap;
	q.put_capacity(cap);
	while (cin >> act && act != -1)
	{ 
		if (act == 1)
		{
			cin >> input;
			//cout << "input= " << input << endl << endl;
			q.push(input);
		}
		else if (act == 0)
			q.pop();
		//else if (act == 4)
			//break;
	}
	//system("pause");
	return 0;
}
void queue::push(int x)
{
	rear = (rear + 1) % capacity;
	if (rear == front)
	{
		cout << "FULL" << endl;
		rear = (rear-1) % capacity;
	}
	else
		que[rear] = x;
}
void queue::pop()
{
	if ((rear% capacity) == (front % capacity))
	{
		cout << "EMPTY" << endl;
	}
	else
		cout << que[(++front) % capacity] << endl;
}
void queue::put_capacity(int x)
{
	capacity = x;
}