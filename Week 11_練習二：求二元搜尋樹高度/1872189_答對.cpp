#include <iostream>
#include "cmath"
#define max_size 50
using namespace std;
typedef struct node *treepointer;
struct node {
	node() { level = 1; }
	int data, level;
	treepointer leftchild, rightchild;
};
void compare(treepointer, int);
int MAX = 0;
int main()
{
	int first, temp, count = 1;
	treepointer ptr, root;
	root = new node;
	ptr = root;
	cin >> first;
	root->data = first;
	root->leftchild = NULL;root->rightchild = NULL;
	while (cin >> temp && cin.get() != '\n')
		compare(ptr, temp);
	compare(ptr, temp);
	cout << MAX << endl;
}
void compare(treepointer search, int data)
{
	if (search->data > data) 
	{
		if (search->leftchild)
			compare(search->leftchild, data);
		else 
		{
			treepointer temp;
			temp = new node;
			temp->leftchild = NULL; temp->rightchild = NULL; temp->data = data;
			temp->level = search->level + 1;
			if (temp->level > MAX)
				MAX = temp->level;
			search->leftchild = temp;
		}
	}
	if (search->data < data) 
	{
		if (search->rightchild)
			compare(search->rightchild, data);
		else 
		{
			treepointer temp;
			temp = new node;
			temp->leftchild = NULL; temp->rightchild = NULL; temp->data = data;
			temp->level = search->level + 1;
			if (temp->level > MAX)
				MAX = temp->level;
			search->rightchild = temp;
		}
	}
}