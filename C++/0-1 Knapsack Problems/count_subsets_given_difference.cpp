#include<bits/stdc++.h>
using namespace std;

int countsub(int n, int arr[], int s){
    int dp[n+1][s+1];

    for(int i=0; i<n+1; i++){
        for(int j=0; j<s+1; j++){
            if(j==0){
                dp[i][j] = 1;
            } else {
                dp[i][j] = 0;
            }
        }
    }

    for(int i=1; i<n+1; i++){
        for(int j=1; j<s+1; j++){
            if(arr[i-1]<=j){
                dp[i][j] = dp[i-1][j] + dp[i-1][j-arr[i-1]];
            } else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    //cout<<dp[n][s];
    return dp[n][s];
}

int countsubdiff(int n, int arr[], int diff){
    int maxi = 0, s1 = 0;
    maxi = accumulate(arr, arr+n, maxi);
    s1 = (maxi+diff)/2;
    //cout<<maxi<<endl;
    //cout<<s1;
    return countsub(n, arr, s1);
}

int main(){
    int n=0, diff=0;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    cin>>diff;
    cout<<countsubdiff(n, arr, diff)<<'\n';
}