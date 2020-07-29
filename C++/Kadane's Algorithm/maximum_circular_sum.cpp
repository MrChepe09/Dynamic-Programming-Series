#include<bits/stdc++.h>
using namespace std;

int max_sum(int n, int arr[]){
    int total = 0, maxSum = arr[0], curMax = 0, minSum = arr[0], curMin = 0;
    for(int i=0; i<n; i++){
        curMax = max(curMax + arr[i], arr[i]);
        maxSum = max(curMax, maxSum);
        curMin = min(curMin + arr[i], arr[i]);
        minSum = min(curMin, minSum);
        total += arr[i];
    }
    return maxSum > 0 ? max(maxSum, total-minSum) : maxSum;
}

int main(){
    int test, n;
    int arr[9999];
    cin>>test;
    while(test--){
        cin>>n;
        for(int i=0; i<n; i++){
            cin>>arr[i];
        }
    cout<<max_sum(n, arr)<<'\n';
    }
}