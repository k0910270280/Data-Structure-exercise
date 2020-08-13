#include <iostream>
#include "string"
#include "stack"
using namespace std;
typedef struct node *linkpointer;
struct node {
	string name;
	float weight;
	int value, cp;
	linkpointer link;
};
void attach(linkpointer*, string, float, int);
linkpointer search(linkpointer, int, float);
void print(linkpointer);
int main()
{
	int value, cp;
	float weight;
	string name;
	linkpointer first, inverse_ptr;	first = NULL;
	while (cin >> name && name != "-1")
	{
		cin >> value >> weight;
		attach(&first, name, weight, value);
	}
	print(first);

}
void attach(linkpointer *first, string name, float weight, int value)
{
	int cp = (value / weight);
	linkpointer temp, sear = *first, parent;
	temp = new node; temp->name = name; temp->value = value;  temp->weight = weight;   temp->cp = cp;  temp->link = NULL;
	parent = search(sear, cp, weight);
	if (!(*first))
		*first = temp;
	else
	{
		temp->link = parent->link;
		parent->link = temp;
	}
}
linkpointer search(linkpointer search, int cp, float weight)
{
	linkpointer parent = search;
	for (; search; search = search->link)
	{
		if (search->cp == cp)
		{
			if (search->weight < weight)
				break;
			else
				continue;
		}
		if (search->cp < cp)
			break;
		parent = search;
	}
	return parent;
}
void print(linkpointer first)
{
	stack <string> s;
	int total_value = 0;
	float total_weight = 0;
	for (; first; first = first->link)
	{
		if ((total_weight + (first->weight)) > 20)
			break;
		total_value += first->value;
		total_weight += first->weight;
		s.push(first->name);
	}
	while (!s.empty())
	{
		cout << s.top() << " ";
		s.pop();
	}
	cout << endl;
	printf("total weight:%.2f", total_weight);
	cout << endl << "total value:" << total_value << endl;
}