#include <iostream>
#include "string"
#define max_size 30
using namespace std;
bool find(string[], string, int);
void print(int, int);
int main()
{
	int size = 0, count = 0;
	string node[max_size], temp;
	while (cin >> temp){
		if (temp == "-1") {
			print(count, size);
			break;
		}
		if (temp == "0"){
			print(count, size);
			size = count = 0;
			continue;
		}
		if(!find(node, temp, size))
			node[size++] = temp;
		count++;
	}
}
bool find(string node[], string target, int size){
	for (int i = 0; i < size; i++)
		if (target == node[i])
			return true;
	return false;
}
void print(int count, int size){
	int node = size, edge = count - size + 1;
	cout << edge - node + 2 << endl;
}