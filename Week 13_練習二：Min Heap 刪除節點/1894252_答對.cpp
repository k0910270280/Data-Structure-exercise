#include <iostream>
#define max_size 100
#define heap_full(n)(n == max_size - 1)
#define heap_empty(n)(!n)
using namespace std;

typedef struct {
	float key;
}element;
void push(element[], int*, float);
float pop(element[], int*);
void print(element[], int*);
int main()
{
	float temp;
	element heap[max_size] = { NULL };
	cin >> temp;
	int n = 0;
	while (cin.get() != '\n')
	{
		push(heap, &n, temp);
		cin >> temp;
	}
	push(heap, &n, temp);
	int total = n;
	for (int i = 0; i < total; i++)
	{
		print(heap, &n);
		cout << endl;
		pop(heap, &n);
	}
}

void push(element heap[], int *n, float new_data)
{
	if (heap_full(*n))
	{
		cout << "The heap is full." << endl;
		exit(EXIT_FAILURE);
	}
	int i = ++(*n);
	while ((i != 1) && (new_data < heap[i / 2].key))
	{
		heap[i] = heap[i / 2];
		i /= 2;
	}
	heap[i].key = new_data;
}

float pop(element heap[], int *n)
{
	if (heap_full(*n))
	{
		cout << "The heap is full." << endl;
		exit(EXIT_FAILURE);
	}
	float pop_value = heap[1].key;
	float temp = heap[(*n)--].key;
	int parent = 1, child = 2;
	while (child <= *n)
	{
		if ((child < *n) && (heap[child + 1].key < heap[child].key))
			child++;
		if (temp <= heap[child].key)
			break;
		heap[parent] = heap[child];
		parent = child;
		child *= 2;
	}
	heap[parent].key = temp;
	return pop_value;
}

void print(element heap[], int *n)
{
	int i;
	for ( i = 1; i < (*n); i++)
		cout << "[" << i << "]" << heap[i].key << " ";
	cout << "[" << i << "]" << heap[i].key;
}