#include <iostream>
#include "string"
using namespace std;
typedef struct linked_list *listpointer;
struct linked_list {
	listpointer  link;
	string data;
}; 
void Attach(listpointer, string);
void Remove(listpointer*, int);
void Print(listpointer);
bool Travial(listpointer, string);
int Length(listpointer);
int main()
{
	int number[10], total_time, index = 0;
	string input;
	cin >> total_time;
	for (int i = 0; i < total_time; i++)
		cin >> number[index++];
	index = 0;
	while (total_time > 0)
	{
		listpointer list;
		list = new linked_list;
		list->link = NULL;
		Attach(list, "qwe");
		listpointer *ptr = &list;
		*ptr = (*ptr)->link;
		for (int i = 0; i < number[index]; i++)
		{
			cin >> input;
			if (!Travial(list, input))
				Attach(list, input);
		}
		index++;
		cout << Length(list) << endl;
		total_time--;
	}
}
bool Travial(listpointer list, string target)
{
	int pos = 0;
	listpointer search;
	search = list;
	//search = search->link;
	for (; search; search = search = search->link)
	{
		if (search->data == target)
		{
			Remove(&list, pos);
			return true;
		}
		pos++;
	}
	return false;
}
void Attach(listpointer first, string new_data)
{
	listpointer temp, new_node;
	new_node = new linked_list;
	new_node->data = new_data;
	for (temp = first; temp->link; temp = temp->link);
	temp->link = new_node;
	new_node->link = NULL;
}
void Remove(listpointer *first, int pos)
{
	listpointer prenode, target;
	prenode = *first; target = *first;
	if (pos != 0)
	{
		for (; pos > 1; pos--)
		{
			prenode = prenode->link;
			target = target->link;
		}
		target = target->link;
		prenode->link = target->link;
	}
	else
	{
		*first = (*first)->link;
	}
	delete target;
}
void Print(listpointer first)
{
	first = first->link;
	for (; first; first = first->link)
		cout << first->data << " ";
	cout << endl;
}
int Length(listpointer first)
{
	int count = 0;
	listpointer temp;
	temp = first;
	temp = temp->link;
	for (; temp; temp = temp->link)
		count++;
	return count;
}