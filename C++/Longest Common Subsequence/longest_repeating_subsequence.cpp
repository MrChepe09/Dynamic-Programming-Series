#include<bits/stdc++.h>
using namespace std;

int repeatsubseq(string a){
    int m = a.length();
    int dp[m+1][m+1];

    for(int i=0; i<=m; i++){
        for(int j=0; j<=m; j++){
            if(i==0 || j==0){
                dp[i][j] = 0;
            } else if(a[i-1]==a[j-1] && i!=j){
                dp[i][j] = 1 + dp[i-1][j-1];
            } else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    return dp[m][m];
}

int main(){
    int test;
    string a;
    cin>>test;
    while(test--){
        cin>>a;
        cout<<repeatsubseq(a)<<'\n';
    }
}