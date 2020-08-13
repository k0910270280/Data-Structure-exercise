#include "iostream"
#include "string"
using namespace std;
int main()
{
	string str1, tar, rep;
	int pos = 0, i, tar_pos[10] = {0}, total = 0;
	getline(cin, str1);
	cin >> tar; cin >> rep;
	while((i = str1.find(tar, pos)) != string::npos)
	{
		pos = i + 1;
		tar_pos[total++] = i;
	}
	cout << tar_pos[1];
	for (int j = 0; j < total; j++)
	{
		str1.erase(tar_pos[j], tar.length());
		str1.insert(tar_pos[j], rep);
		tar_pos[j + 1] = tar_pos[j + 1] + ( rep.length() - tar.length());
	}
	cout << str1<<endl;
	system("pause");
}