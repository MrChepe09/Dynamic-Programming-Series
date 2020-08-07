#include<bits/stdc++.h>
using namespace std;

int lcs(string a, string b){
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

int insertdelete(string a, string b){
    int m = a.length();
    int n = b.length();
    int subseq = lcs(a, b);
    cout<<"Deletions: "<<max(m, n)-subseq<<'\n';
    cout<<"Insertions: "<<min(m, n)-subseq<<'\n';
}

int main(){
    int test;
    string a, b;
    cin>>test;
    while(test--){
        cin>>a;
        cin>>b;
        insertdelete(a, b);
    }
}