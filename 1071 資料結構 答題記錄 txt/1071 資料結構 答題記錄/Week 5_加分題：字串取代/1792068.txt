#include "iostream"
#include "sstream"
#include "string"
#define max_size  50
using namespace std;
int main()
{
	string article, input[max_size], temp, tar, rep;
	int total = 0;
	getline(cin, article);
	cin >> tar; cin >> rep;
	istringstream ss(article);
	while (getline(ss, temp, ' '))
		input[total++] = temp;
	for (int i = 0; i < total; i++) {
		if (input[i] == tar)
			input[i] = rep;
		if (i != total - 1)
			cout << input[i] << " ";
		else
			cout << input[total - 1] << endl;
	}
	system("pause");
}