#include <iostream>  
#include "string"  
using namespace std;
int main()
{
	string input, target, rep;
	int i, pos = 0;
	getline(cin, input);
	getline(cin, target);
	getline(cin, rep);
	while ((i = input.find(target, pos)) != string::npos) {
		input.replace(i, target.size(), rep);
		pos = i + rep.size();
	}
	cout << input << endl;
}