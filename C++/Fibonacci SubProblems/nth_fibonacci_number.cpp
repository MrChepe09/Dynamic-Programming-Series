#include<bits/stdc++.h>
using namespace std;

int nthfibonacci(int n){
    int a[n+1];
    for(int i = 0; i<n+1; i++){
        a[i] = 0;
    }
    a[1] = 1;

    for(int i = 2; i<n+1; i++){
       a[i] = a[i-1] + a[i-2];
    }
    return a[n];
}

int main(){
    int test, n;
    cin>>test;
    while(test--){
        cin>>n;
        cout<<nthfibonacci(n)<<'\n';
    }
}