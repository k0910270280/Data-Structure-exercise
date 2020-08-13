#include <iostream>
using namespace std;
typedef struct link_list *list_pointer;
struct link_list {
	int data;
	list_pointer link;
};
void Print(list_pointer);
list_pointer Invert(list_pointer);
void Init(list_pointer);
int main()
{
	list_pointer first, result;
	first = new link_list;
	Init(first);
	result = Invert(first);
	Print(result);
	system("pause");
}
void Init(list_pointer first)
{
	int new_data;
	cin >> first->data;
	while (cin.get() != '\n')
	{
		list_pointer temp;
		temp = new link_list;
		cin >> new_data;
		temp->data = new_data;
		first->link = temp;
		first = first->link;
		temp->link = NULL;
	}
}
void Print(list_pointer first)
{
	for (; first->link != NULL; first = first->link)
		cout << (first->data) << " ";
	cout << (first->data) ;
	cout << endl;
}
list_pointer Invert(list_pointer lead)
{
	list_pointer middle, trail;
	middle = NULL;
	while (lead)
	{
		trail = middle;
		middle = lead;
		lead = lead->link;
		middle->link = trail;
	}
	return middle;
}