#include<bits/stdc++.h>
using namespace std;

bool equalsum(int n, int arr[], int s){
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
    //cout<<dp[n][s];
    return dp[n][s];
}

int main(){
    int n, s, sum=0;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    for(int i=0; i<n; i++){
        sum += arr[i];
    }
    //cout<<sum<<endl;
    if(sum%2==1){
        cout<<false;
    } else {
        s = sum/2;
        //cout<<s;
        cout<<equalsum(n, arr, s);
    }
}