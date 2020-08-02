#include<bits/stdc++.h>
#include<numeric>
using namespace std;

int sumdiff(int n, int arr[]){
    int mini = 0;
    int maxi = accumulate(arr, arr+n, maxi);
    int ans = INT_MAX;
    bool dp[n+1][maxi+1];

    for(int i=0; i<=n; i++){
        for(int j=0; j<=maxi; j++){
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
    for(int i=mini; i<=(maxi)/2; i++){
        //cout<<ans<<endl;
        if(dp[n][i] == 1){
            int res = maxi - 2*i;
            if(ans>res){
                ans = res;
            }
        }
    }
    return ans;
}

int main() {
    int test, n;
    cin>>test;
    while(test--){
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++){
            cin>>arr[i];
        }
        cout<<sumdiff(n, arr)<<'\n';
    }
}
