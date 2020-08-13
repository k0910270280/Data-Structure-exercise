#include "iostream"
#include "string"
#define max_size 40
using namespace std;
void turn_post(char[], char[], int );
int compare(char);
struct stack {
public:
	stack(int cap) { capacity = cap; t = -1; ptr = new char[capacity]; }
	void push(char x) { ptr[++t] = x; }
	void pop() { t--; }
	char top() { return ptr[t]; }
	bool empty() { return (t == -1); }
private:
	char *ptr;
	int t;
	int capacity;
};
int th = 0;
char answer[10][max_size];
int ans_term[10];
int main(void)
{
	char output[max_size],  input[max_size];
	int n;
	cin >> n;
	while (th < n)
	{
		int total = 0;
		cin >> input[total++];
		while (cin.get() != '\n')
		{
			char temp;
			cin >> temp;
			if (temp != ' ')
				input[total++] = temp;
		}
		turn_post(input, output, total);
		th++;
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < ans_term[i] - 1; j++)
			cout << answer[i][j] << " ";
		cout << answer[ans_term[i]- 1] << endl;
	}
			
	system("pause");
}
void turn_post(char input[], char output[],int total)
{
	int index = 0, count = 0;
	stack s(80);
	for (int i = 0; i < total; i++)
	{
		switch (input[i])
		{
		case '(':
			s.push(input[i]);
			count += 2;
			break;
		case '+': case '-': case '*': case '/':
			while (compare(s.top()) >= compare(input[i]))
			{
				output[index++] = s.top();
				s.pop();
			}
			s.push(input[i]);
			break;
		case ')':
			while (s.top() != '(')
			{
				output[index++] = s.top();
				s.pop();
			}
			s.pop();
			break;
		default:
			output[index++] = input[i];
		}
	}
	while (!s.empty())
	{
		output[index++] = s.top();
		s.pop();
	}
	total = total - count;
	for (int i = 0; i < total; i++)
		answer[th][i] = output[i];
	ans_term[th] = total;
}
int compare(char x)
{
	switch (x)
	{
	case '+':case'-':
		return 1;
	case '*':case '/':
		return 2;
	default:
		return 0;
	}
}