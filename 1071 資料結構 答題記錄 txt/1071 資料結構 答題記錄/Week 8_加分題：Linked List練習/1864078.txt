#include <iostream>
#include "string"
#include <string.h>
#include "sstream"
using namespace std;
typedef struct linked_list *listpointer;
struct linked_list {
	string word;
	int num = 1;
	listpointer link;
};
void attach(listpointer, string);
bool travial(listpointer, string);
int length(listpointer);
void insert(listpointer, int, string);
void print(listpointer);
int main()
{
	listpointer list;
	list = new linked_list;
	list->link = NULL;

	int num;
	string input, temp;
	getline(cin, input);
	while (input != "#Finish")
	{
		istringstream ss(input);
		while (getline(ss, temp, ' '))
		{
			attach(list, temp);
		}
		getline(cin, input);
	}
	while (cin >> input && input != "#Exit")
	{
		if (input == "#Insert")
		{
			if (cin >> num >> temp && num < length(list))
			{
				if (!travial(list, temp))
					insert(list, num, temp);
			}
		}
		if (input == "#Add")
		{
			cin >> temp;
			attach(list, temp);
		}
		if (input == "#Print")
			print(list);
	}
}
void insert(listpointer first, int pos, string new_data)
{
	listpointer prenode, new_node;
	new_node = new linked_list;
	new_node->word = new_data;
	prenode = first;
	if (first)
	{
		for (; pos > 1; pos--)
			prenode = prenode->link;
		new_node->link = prenode->link;
		prenode->link = new_node;
	}
	else
	{
		first->link = new_node;
		new_node->link = NULL;
	}
}

void attach(listpointer first, string new_data)
{
	if (travial(first, new_data))
		return;
	listpointer temp, new_node;
	new_node = new linked_list;
	new_node->word = new_data;
	for (temp = first; temp->link; temp = temp->link);
	temp->link = new_node;
	new_node->link = NULL;
}
bool travial(listpointer first, string new_data)
{
	listpointer ptr;
	ptr = first;
	while (ptr)
	{
		if (strcasecmp(ptr->word.c_str(), new_data.c_str()) == 0)
		{
			ptr->num++;
			return true;
		}
		else
			ptr = ptr->link;
	}
	return false;
}
void print(listpointer first)
{
	first = first->link;
	for (; first; first = first->link)
		cout << first->word << ", " << first->num << endl;
}
int length(listpointer first)
{
	int count = 0;
	listpointer temp;
	temp = first;
	temp = temp->link;
	for (; temp; temp = temp->link)
		count++;
	return count;
}