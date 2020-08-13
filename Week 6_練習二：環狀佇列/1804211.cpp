#include <iostream>
using namespace std;
struct queue {
public:
	void push(int);
	void pop();
	void put_capacity(int);
private:
	int front = 0, rear = 0, capacity;
	int *que = new int[capacity];
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
			q.push(input);
		}
		if (act == 0)
			q.pop();
	}
	system("pause");
	return 0;
}
void queue::push(int x)
{
	rear = (rear + 1) % capacity;
	if (rear == front)
	{
		cout << "FULL" << endl;
		rear--;
	}
	else
		que[rear] = x;
}
void queue::pop()
{
	if (rear == (front % capacity))
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