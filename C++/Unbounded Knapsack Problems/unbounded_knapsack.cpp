#include<bits/stdc++.h>
using namespace std;

int knapsack(int n, int w[], int v[], int W){
    int dp[n+1][W+1];

    for(int i=0; i<=n; i++){
        for(int j=0; j<=W; j++){
            if(i==0 || j==0){
                dp[i][j] = 0;
            } else if(w[i-1]<=j){
                dp[i][j] = max(dp[i-1][j], v[i-1]+dp[i][j-w[i-1]]);
            } else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][W];
}

int main(){
    int n, W;
    cin>>n;
    int w[n], v[n];
    for(int i=0; i<n; i++){
        cin>>w[i];
    }
    for(int i=0; i<n; i++){
        cin>>v[i];
    }
    cin>>W;
    cout<<knapsack(n, w, v, W)<<'\n';
}