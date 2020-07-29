#include<bits/stdc++.h>
using namespace std;

int buysell(vector<int>arr, int n){
    vector<int>diff(n, 0);
    for(int i=1; i<n; i++){
        diff[i] = arr[i]-arr[i-1];
    }

    for(int i=1; i<n; i++){
        diff[i] = max(diff[i]+diff[i-1], diff[i]);
    }
    return *max_element(diff.begin(), diff.end());
}

int main(){
    int test, n;
    cin>>test;
    while(test--){
        cin>>n;
        vector<int>arr(n);
        for(int i=0; i<n; i++){
            cin>>arr[i];
        }
        cout<<buysell(arr, n)<<'\n';
    }
}