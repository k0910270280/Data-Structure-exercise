#include <iostream>
#define max_size 30
using namespace std;
void push(int[], int*, int);
int pop(int[], int *);
void print(int[], int);
int main()
{
	int heap[max_size], n = 0, temp;
	while (cin >> temp && !cin.eof())
		push(heap, &n, temp);
	while (n > 0)
	{
		print(heap, n);
		pop(heap, &n);
	}
}
void push(int heap[], int *n, int data)
{
	int i = ++(*n);
	heap[i] = data;
	while (i <= *n && heap[i] < heap[i / 2])
	{
		int temp = heap[i];
		heap[i] = heap[i / 2];
		heap[i / 2] = temp;
		i *= 2;
	}
}
int pop(int heap[], int *n)
{
	int parent = 1, child = 2;
	int min = heap[1];
	heap[1] = heap[(*n)--];
	while (child <= (*n))
	{
		if ((child < (*n)) && heap[child] > heap[child + 1])
			child++;
		if (heap[parent] <= heap[child])
			break;
		int temp = heap[parent];
		heap[parent] = heap[child];
		heap[child] = temp;
		parent = child;
		child *= 2;
	}
	return min;
}
void print(int heap[], int n)
{
	for (int i = 1; i < n; i++)
		cout << "[" << i << "] " << heap[i] << " ";
	cout << "[" << n << "] " << heap[n] << endl;
}