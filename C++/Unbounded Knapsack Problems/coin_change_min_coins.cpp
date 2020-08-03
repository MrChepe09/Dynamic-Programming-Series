#include<bits/stdc++.h>
using namespace std;

int mincoins(int n, int coins[], int sum){
    int dp[n+1][sum+1];

    for(int i=0; i<=n; i++){
        for(int j=0; j<=sum; j++){
            if(i==0){
                dp[i][j] = INT_MAX-1;
            }
            if(j==0){
                dp[i][j] = 0;
            }
            if(i==1){
                if(j%coins[i-1]==0){
                    dp[i][j] = j/coins[i-1];
                } else{
                    dp[i][j] = INT_MAX-1;
                }
            } else if(coins[i-1]<=j){
                dp[i][j] = min(1 + dp[i][j-coins[i-1]], dp[i-1][j]);
            } else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][sum];
}

int main(){
    int test, n, sum;
    cin>>test;
    while(test--){
        cin>>n;
        int coins[n];
        for(int i=0; i<n; i++){
            cin>>coins[i];
        }
        cin>>sum;
        cout<<mincoins(n, coins, sum)<<'\n';
    }
}