#include <iostream> 
using namespace std;
struct queue {
private:
	int front, rear, capacity;
	int *que;
public :
	void push(int);
	void pop();
	void put_capacity(int c) { capacity = c; }
	queue() {
		front = 0;
		rear = 0;
		que = new int[capacity];
	}

} q;
int main()
{
	int cap, act, input;
	cin >> cap;
	q.put_capacity(cap);
	while (cin >> act)
	{
		if (act == -1)
			break;
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
		rear = (rear - 1) % capacity;
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