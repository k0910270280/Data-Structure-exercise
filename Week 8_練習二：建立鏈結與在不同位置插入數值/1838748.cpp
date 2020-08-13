#include <iostream>      
using namespace std;
typedef struct linked_list *list_pointer;
struct linked_list {
	int data;
	list_pointer link;
};
void F(list_pointer, int);
void I(list_pointer, int, int);
void A(list_pointer, int);
void print(list_pointer);
void erase(list_pointer*);
int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		list_pointer list;
		list = new linked_list;
		list->link = NULL;
		bool conti = true;
		while (conti)
		{
			char act;
			int new_data, pos;
			cin >> act;
			switch (act)
			{
			case 'f':
				cin >> new_data;
				F(list, new_data);
				break;
			case 'i':
				cin >> new_data >> pos;
				I(list, new_data, pos);
				break;
			case 'a':
				cin >> new_data;
				A(list, new_data);
				break;
			default:
				conti = false;
			}
			if (list->link&&conti == true)
				print(list);
		}
		if (i != (n - 1))
			cout << endl;
		erase(&list);
	}
}
void F(list_pointer front, int new_data)
{
	list_pointer temp;
	temp = new linked_list;
	temp->data = new_data;
	if (front->link == NULL)
	{
		front->link = temp;
		temp->link = NULL;
	}
	else
	{
		temp->link = front->link;
		front->link = temp;
	}
}
void I(list_pointer list, int new_data, int pos)
{
	list = list->link;
	list_pointer temp;
	temp = new linked_list;
	temp->data = new_data;
	for (int count = 0; count < pos - 1; count++)
		list = list->link;
	temp->link = list->link;
	list->link = temp;
}
void A(list_pointer first, int new_data)
{
	list_pointer temp, new_node;
	new_node = new linked_list;
	for (temp = first; temp->link; temp = temp->link);
	temp->link = new_node;
	new_node->data = new_data;
	new_node->link = NULL;
}
void print(list_pointer list)
{
	list = list->link;
	cout << "Created Linked list is:";
	for (; list; list = list->link)
		cout << " " << list->data;
	cout <<" "<< endl;
}
void erase(list_pointer *list)
{
	list_pointer temp;
	while (*list)
	{
		temp = *list;
		*list = (*list)->link;
		delete temp;
	}
}