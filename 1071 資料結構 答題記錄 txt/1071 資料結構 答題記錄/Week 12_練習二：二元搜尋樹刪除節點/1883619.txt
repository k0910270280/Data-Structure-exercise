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
void remove(searchpointer*, float);
searchpointer find_parent(searchpointer, float, int*);

int main()
{
	searchpointer root, first;
	first = new node;
	root = first;
	first->leftchild = NULL; first->rightchild = NULL;
	cin >> first->data;
	while (cin.get() != '\r')
	{
		float temp;
		cin >> temp;
		attach(first, temp);
	}
	cout << "Binary search tree (before):" << endl;
	preorder_print(root);
	cout << endl;
	do
	{
		float temp;
		cin >> temp;
		remove(&first, temp);

	} while (cin.get() != '\r');
	cout << "Binary search tree (after):" << endl;
	preorder_print(root);
	cout << endl;
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
void remove(searchpointer *root, float target)
{
	int pos;
	searchpointer parent, search_ptr, next;
	search_ptr = *root;
	parent = find_parent(search_ptr, target, &pos);
	if (parent)
	{
		switch (pos)
		{
		case -1:
			search_ptr = parent->leftchild;
			break;
		case 1:
			search_ptr = parent->rightchild;
			break;
		case 0:
			search_ptr = parent;
			break;
		}
		if ( !(search_ptr->leftchild) )
		{
			if (parent == search_ptr)
				*root = (*root)->rightchild;
			else
			{
				if (pos == 1)
					parent->rightchild = search_ptr->rightchild;
				else
					parent->leftchild = search_ptr->rightchild;
			}
			delete search_ptr;
		}
		else if (!search_ptr->rightchild) 
		{
			if (parent == search_ptr)
				*root = (*root)->leftchild;
			else
			{
				if (pos == 1)
					parent->rightchild = search_ptr->leftchild;
				else
					parent->leftchild = search_ptr->leftchild;
			}
			delete search_ptr;
		}
		else
		{
			parent = search_ptr;
			next = search_ptr->leftchild;
			while (next->rightchild)
			{
				parent = next;
				next = next->rightchild;
			}
			search_ptr->data = next->data;
			parent->leftchild = next->leftchild; //?
			delete next;
		}
	}
	else
		cout << "no " << target << endl;
}

searchpointer find_parent(searchpointer search_ptr, float key, int *pos)
{
	*pos = 0;
	searchpointer parent = search_ptr;
	while (search_ptr)
	{
		if (search_ptr->data == key)
		{
			return parent;
		}
		else
		{
			parent = search_ptr;
			if (search_ptr->data > key)
			{
				*pos = -1;
				search_ptr = search_ptr->leftchild;
			}
			else
			{
				*pos = 1;
				search_ptr = search_ptr->rightchild;
			}
		}
	}
	return NULL;
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