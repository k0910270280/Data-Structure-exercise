#include <iostream>  
#include "string"  
#include "vector"  
using namespace std;   
string longestPalindrome(string A) {  
    int N = A.size();  
    vector<vector<bool> > P(N + 1, vector<bool>(N + 1, true));  
    int start = 0, len = 1;  
  
    for (int k = 1; k < N; ++k) {  
        for (int i = 1; i <= N - k; ++i) {  
            P[i][i + k] = P[i + 1][i + k - 1] && (A[i - 1] == A[i + k - 1]);  
            if (P[i][i + k] && k + 1 > len)  
                start = i - 1, len = k + 1;  
        }  
    }  
  
    string result(A.begin() + start, A.begin() + start + len);  
    return result;  
}  
int main()  
{  
    string str;  
    cin >> str;  
    cout << longestPalindrome(str) << endl;  
}