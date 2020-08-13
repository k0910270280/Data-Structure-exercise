#include <iostream>
#define max_size 100
using namespace std;

typedef struct node *searchpointer;
struct node {
	float data;
	searchpointer leftchild, rightchild;
};

searchpointer search(searchpointer, float); // whether the number is in tree or not 
void attach(searchpointer, float);
void inorder(searchpointer, float);
void preorder(searchpointer, float);
void postorder(searchpointer, float);
void print(float[], int ,float);

float ans[max_size] = { 0 };
int ind = 0;


int main()
{
	int total = 0;
	searchpointer root, first;
	first = new node;
	root = first;
	first->leftchild = NULL; first->rightchild = NULL;
	cin >> first->data;
	while (cin.get() != '\n')
	{
		float temp;
		cin >> temp;
		attach(first, temp);
		total++;
	}
	float target;
	cin >> target;
	inorder(root, target); ind = 0;
	print(ans, total, target); cout << " ";
	preorder(root, target); ind = 0;
	print(ans, total, target); cout << " ";
	postorder(root, target); ind = 0;
	print(ans, total, target);
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
void inorder(searchpointer root, float target)
{
	if (root)
	{
		inorder(root->leftchild, target);
		ans[ind++] = root->data;
		inorder(root->rightchild, target);
	}
}
void preorder(searchpointer root, float target)
{
	if (root)
	{
		ans[ind++] = root->data;
		preorder(root->leftchild, target);
		preorder(root->rightchild, target);
	}
}
void postorder(searchpointer root, float target)
{
	if (root)
	{
		postorder(root->leftchild, target);
		postorder(root->rightchild, target);
		ans[ind++] = root->data;
	}
}
void print(float ans[], int total, float target)
{
	for (int i = 0; i < total; i++)
		if (ans[i] == target)
			cout << ans[i - 1];
}