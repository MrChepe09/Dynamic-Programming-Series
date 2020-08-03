#include<bits/stdc++.h>
using namespace std;

int rodcutting(int length[], int price[], int n){
    int dp[n+1][n+1];

    for(int i=0; i<=n; i++){
        for(int j=0; j<=n; j++){
            if(i==0 || j==0){
                dp[i][j] = 0;
            } else if(length[i-1]<=j){
                dp[i][j] = max(price[i-1] + dp[i][j-length[i-1]], dp[i-1][j]);
            } else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][n];
}

int main(){
    int test, n;
    cin>>test;
    while(test--){
        cin>>n;
        int length[n], price[n];
        for(int i=0; i<n; i++){
            cin>>length[i];
        }
        for(int i=0; i<n; i++){
            cin>>price[i];
        }
        cout<<rodcutting(length, price, n)<<'\n';
    }
}