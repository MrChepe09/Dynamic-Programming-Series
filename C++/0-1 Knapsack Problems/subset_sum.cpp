#include<bits/stdc++.h>
using namespace std;

int subset(int n, int arr[], int s){
    bool dp[n+1][s+1];

    for(int i=0; i<=n; i++){
        for(int j=0; j<=s; j++){
            if(i==0){
                dp[i][j] = false;
            } else if(j==0){
                dp[i][j] = true;
            } else if(arr[i-1]<=j){
                dp[i][j] = dp[i-1][j] || dp[i-1][j-arr[i-1]];
            } else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][s];
}

int main(){
    int n, s;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    cin>>s;
    cout<<subset(n, arr, s)<<'\n';
}