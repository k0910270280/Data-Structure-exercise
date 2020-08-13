#include <iostream>
#include "string"
#include "vector"
#include "algorithm"
using namespace std;
typedef struct linked_list *listpointer;
struct linked_list {
public:
	listpointer link;
	string data;
	vector <int>num;
};
void Attach(listpointer*, string, int);
void Print(listpointer);
void Remove(listpointer);
int main()
{
	string data;
	int number, cost;

	listpointer list;
	list = NULL;
	

	cin >> number;
	while (number > 0)
	{
		cin >> data >> cost;
		Attach(&list, data, cost);
		number--;
	}
	Print(list);
}
void Attach(listpointer *first, string new_data, int cost)
{
	listpointer temp, new_node;
	new_node = new linked_list;
	new_node->data = new_data;
	new_node->num.push_back(cost);
	if (*first)
	{
		for (temp = *first; temp->link; temp = temp->link)
		{
			if (temp->data == new_data)
			{
				temp->num.push_back(cost);
				new_node->link = NULL;
				return;
			}
		}
		if (temp->data == new_data)
		{
			temp->num.push_back(cost);
			new_node->link = NULL;
			return;
		}
		temp->link = new_node;
	}
	else
		*first = new_node;
	new_node->link = NULL;
}
void Print(listpointer first)
{
	for (; first; first = first->link)
	{
		cout << first->data << ",";
		sort(first->num.begin(), first->num.end());
		reverse(first->num.begin(), first->num.end());
		while (!first->num.empty())
		{
			cout << first->num.back() << ",";
			first->num.pop_back();
		}
		cout << endl;
	}
}