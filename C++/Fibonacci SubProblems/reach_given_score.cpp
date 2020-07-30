#include<bits/stdc++.h>
using namespace std;

int calcscore(int n){
    int a[n+1];

    for(int i=0; i<n+1; i++){
        a[i] = 0;
    }
    a[0] = 1;

    for(int i=3; i<n+1; i++){
        a[i] += a[i-3];
    }

    for(int i=5; i<n+1; i++){
        a[i] += a[i-5];
    }

    for(int i=10; i<n+1; i++){
        a[i] += a[i-10];
    }

    return a[n];
}

int main(){
    int test, n;
    cin>>test;
    while(test--){
        cin>>n;
        cout<<calcscore(n)<<'\n';
    }
}