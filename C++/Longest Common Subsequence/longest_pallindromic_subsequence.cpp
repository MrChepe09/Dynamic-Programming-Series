#include<bits/stdc++.h>
using namespace std;

int pallindromesubseq(string a){
    string b = a;
    reverse(b.begin(), b.end());
    int m = a.length();
    int n = b.length();
    int dp[n+1][m+1];

    for(int i=0; i<=m; i++){
        for(int j=0; j<=n; j++){
            if(i==0 || j==0){
                dp[i][j] = 0;
            } else if(a[i-1]==b[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            } else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    return dp[m][n];
}

int main(){
    int test;
    string a;
    cin>>test;
    while(test--){
        cin>>a;
        cout<<pallindromesubseq(a)<<'\n';
    }
}