#include <iostream> 
using namespace std;
void push(int);
void pop();
int front = 0, rear = 0, cap;
int *que = new int[cap];
int main()
{
	int act, input;
	cin >> cap;
	while (cin >> act && act != -1)
	{
		if (act == 1)
		{
			cin >> input;
			//cout << "input= " << input << endl << endl; 
			push(input);
		}
		else if (act == 0)
			pop();
		//else if (act == 4) 
			//break; 
	}
	//system("pause"); 
	return 0;
}
void push(int x)
{
	rear = (rear + 1) % cap;
	if (rear == front)
	{
		cout << "FULL" << endl;
		rear = (rear - 1) % cap;
	}
	else
		que[rear] = x;
}
void pop()
{
	if ((rear% cap) == (front % cap))
	{
		cout << "EMPTY" << endl;
	}
	else
		cout << que[(++front) % cap] << endl;
}