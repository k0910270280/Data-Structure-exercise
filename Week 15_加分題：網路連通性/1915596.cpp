#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
const int maxn = 100;
int p[maxn][maxn]; 
int known[maxn];
int v;

void DFS(int s)
{
    for(int u=0; u<v; u++)
    {
        if(!known[u]&&p[s][u])
        {
            known[u] = 1;
            DFS(u);
        }
    }
    return;
}

int main()
{
	int total;
	cout << "1"<<endl;
    while(cin>>total&&!cin.eof()) 
    {

        memset(p,0,sizeof(p));
        memset(known,0,sizeof(known));

        int s,t; 
        
        int temp;
        for(int i=0; i<total; i++)
        {
            for(int j= 0;j<total;j++)
            {
            	cin>>temp;
            	p[i][j] = temp;
            }
        }
        int count = 0;
        for(int i=0; i<total; i++)
        {
            if(!known[i])
            {
                DFS(i);
                count++;
            }
        }
        
        if(count == 1)
        {
			;
        }else{
			;
        }
    }
    cout <<"-1"<<endl;
    return 0;
}