#include<bits/stdc++.h>
using namespace std;

int tile(int n){
    int a[n+1];

    for(int i=0; i<=n; i++){
        a[i] = 0;
    }
    for(int i=0; i<=n; i++){
        if(i<4){
            a[i] = 1;
        } else if(i==4) {
            a[i] = 2;
        } else {
            a[i] = a[i-1] + a[i-4];
        }
    }
    return a[n];
}

int main(){
    int test, n;
    cin>>test;
    while(test--){
        cin>>n;
        cout<<tile(n)<<'\n';
    }
}