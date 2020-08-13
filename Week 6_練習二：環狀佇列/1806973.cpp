#include "iostream"  
#include "queue"  
using namespace std;  
int cap, rear = 0, front = 0;  
queue<int> q;  
void pu(int);  
void po();  
int main()  
{  
    cin >> cap;  
    int act;  
    while (cin >> act && act != -1)  
    {  
        if (act == 1)  
        {  
            int k;  
            cin >> k;  
            pu(k);  
        }  
        if (act == 0)  
            po();  
    }  
    system("pause");  
}  
void pu(int x)  
{  
    if ((rear+1)%cap == (front%cap))  
    {  
        cout << "FULL" << endl;  
    }  
    else  
    {  
        q.push(x);  
        rear++;  
    }  
}  
void po()  
{  
    if ((front%cap) == (rear%cap))  
        cout << "EMPTY" << endl;  
    else  
    {  
        cout << q.front() << endl;  
        q.pop();  
        front--;  
    }  
}