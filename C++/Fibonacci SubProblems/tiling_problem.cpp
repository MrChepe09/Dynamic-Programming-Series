#include<bits/stdc++.h>
using namespace std;

int tiling(int n, int m){
    int a[n+1];

    for(int i=0; i<=n; i++){
        a[i] = 0;
    }
    for(int i=0; i<=n; i++){
        if(i<m){
            a[i] = 1;
        } else if(i==m) {
            a[i] = 2;
        } else {
            a[i] = a[i-1] + a[i-m];
        }
    }
    return a[n];
}

int main(){
    int test, n, m;
    cin>>test;
    while(test--){
        cin>>n>>m;
        cout<<tiling(n, m)<<'\n';
    }
}