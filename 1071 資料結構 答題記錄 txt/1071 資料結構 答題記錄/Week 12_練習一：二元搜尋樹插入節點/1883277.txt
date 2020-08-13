#include <iostream>
using namespace std;

typedef struct node *searchpointer;
struct node {
	float data;
	searchpointer leftchild, rightchild;
};
searchpointer search(searchpointer, float);
void attach(searchpointer, float);
void preorder_print(searchpointer);
int main()
{
	searchpointer root, first;
	first = new node;
	root = first;
	first->leftchild = NULL; first->rightchild = NULL;
	cin >> first->data;
	while (cin.get() != EOF)
	{
		float temp;
		cin >> temp;
		attach(first, temp);
		preorder_print(root);
		cout << endl;
	}
}
searchpointer search(searchpointer search_ptr, float key)
{
	if (!search_ptr) return NULL;
	if (search_ptr->data == key) return search_ptr;
	if (search_ptr->data > key)
		return search(search_ptr->leftchild, key);
	if (search_ptr->data < key)
		return search(search_ptr->rightchild, key);
}
void attach(searchpointer search_ptr, float new_data)
{
	searchpointer find = search_ptr;
	if (!search(find, new_data))
	{
		if (search_ptr->data > new_data)
		{
			if (search_ptr->leftchild)
				attach(search_ptr->leftchild, new_data);
			else
			{
				searchpointer temp;
				temp = new node;
				temp->leftchild = NULL; temp->rightchild = NULL; temp->data = new_data;
				search_ptr->leftchild = temp;
			}
		}
		if (search_ptr->data < new_data)
		{
			if (search_ptr->rightchild)
				attach(search_ptr->rightchild, new_data);
			else
			{
				searchpointer temp;
				temp = new node;
				temp->leftchild = NULL; temp->rightchild = NULL; temp->data = new_data;
				search_ptr->rightchild = temp;
			}
		}
	}
}
void preorder_print(searchpointer root)
{
	if (root)
	{
		cout << root->data << " ";
		preorder_print(root->leftchild);
		preorder_print(root->rightchild);
	}
}