#include <iostream>
#include "string"
#include "sstream"
#include "queue"
using namespace std;
typedef struct node *treepointer;
struct node {
	string data;
	treepointer leftchild, rightchild;
};
void attach(treepointer, string);
void search(treepointer*, treepointer, string);
void inorder(treepointer);
void postorder(treepointer);
void preorder(treepointer);
void find_max_height(treepointer, int, int*);
int main()
{
	string input, str;
	queue <string> q;
	treepointer root, root_left, root_right;
	getline(cin, input);
	stringstream ss(input);
	while (getline(ss, str, ' '))
		q.push(str);
	root = new node; root->data = q.front();   q.pop();
	root_left = new node;   root_left->leftchild = NULL;	    root_left->rightchild = NULL;    root_left->data = q.front();   q.pop();
	root_right = new node;  root_right->leftchild = NULL;	    root_right->rightchild = NULL;   root_right->data = q.front();  q.pop();
	root->leftchild = root_left;
	root->rightchild = root_right;
	while (getline(cin, input) && input != "0")
		attach(root, input);
	cout << "Preorder: ";
	preorder(root);		cout << endl;
	cout << "Inorder: ";
	inorder(root);		cout << endl;
	cout << "Postorder: ";
	postorder(root);	cout << endl;
	int left_max = 0, right_max = 0;
	unsigned int different;
	treepointer left_ptr, right_ptr;
	left_ptr = root->leftchild;
	right_ptr = root->rightchild;
	find_max_height(left_ptr, 0, &left_max);
	find_max_height(right_ptr, 0, &right_max);
	different = left_max - right_max;
	cout << "The balance factor is " << different << endl;
}
void attach(treepointer root, string input)
{
	string t;
	queue <string> q;
	stringstream ss(input);
	treepointer ptr;
	while (getline(ss, t, ' '))
		q.push(t);
	search(&ptr, root, q.front());		q.pop();
	if (q.size() == 2)
	{
		treepointer temp1, temp2;
		temp1 = new node;  temp1->leftchild = NULL; temp1->rightchild = NULL; temp1->data = q.front(); q.pop();
		temp2 = new node;  temp2->leftchild = NULL; temp2->rightchild = NULL; temp2->data = q.front(); q.pop();
		if (((temp1->data)[2] - '0') % 2 == 1)
		{
			ptr->leftchild = temp1;
			ptr->rightchild = temp2;
		}
		else
		{
			ptr->rightchild = temp1;
			ptr->leftchild = temp2;
		}
	}
	if (q.size() == 1)
	{
		treepointer temp1;
		temp1 = new node;  temp1->leftchild = NULL; temp1->rightchild = NULL; temp1->data = q.front(); q.pop();
		if (((temp1->data)[2] - '0') % 2 == 1)
		{
			ptr->leftchild = temp1;
			ptr->rightchild = NULL;
		}
		else
		{
			ptr->rightchild = temp1;
			ptr->leftchild = NULL;
		}
	}
}
void find_max_height(treepointer root, int count, int*max)
{
	if (root)
	{
		if (count > *max)
			*max = count;
		find_max_height(root->leftchild, count + 1, max);
		find_max_height(root->rightchild, count + 1, max);
	}
	count--;
}
void search(treepointer *ptr, treepointer root, string target)
{
	if (root)
	{
		if (root->data == target)
			*ptr = root;
		search(ptr, root->leftchild, target);
		search(ptr, root->rightchild, target);
	}
}
void inorder(treepointer ptr)
{
	if (ptr)
	{
		inorder(ptr->leftchild);
		cout << ptr->data << " ";
		inorder(ptr->rightchild);
	}
}
void postorder(treepointer ptr)
{
	if (ptr)
	{
		postorder(ptr->leftchild);
		postorder(ptr->rightchild);
		cout << ptr->data << " ";
	}
}
void preorder(treepointer ptr)
{
	if (ptr)
	{
		cout << ptr->data << " ";
		preorder(ptr->leftchild);
		preorder(ptr->rightchild);
	}
}