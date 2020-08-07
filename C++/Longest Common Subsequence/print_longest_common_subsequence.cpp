#include<bits/stdc++.h>
using namespace std;

void printlcs(string a, string b){
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
    int i, j;
    string res = "";
    //dp = lcs(a, b);
    i = a.length();
    j = b.length();
    while(i>0 && j>0){
        if(a[i-1] == b[j-1]){
            res += a[i-1];
            i = i-1;
            j = j-1;
        } else {
            if(dp[i-1][j]>dp[i][j-1]){
                i = i-1;
            } else {
                j = j-1;
            }
        }
    }
    reverse(res.begin(), res.end());
    cout<<res<<'\n';
}

int main(){
    int test;
    string a, b;
    cin>>test;
    while(test--){
        cin>>a;
        cin>>b;
        printlcs(a, b);
    }
}