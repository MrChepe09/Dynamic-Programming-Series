#include<bits/stdc++.h>
using namespace std;

int distance(int n){
    int a[n+1];
    for(int i=0; i<n+1; i++){
        a[i] = 0;
    }
    a[0] = 1;
    a[1] = 1;
    a[2] = 2;

    for(int i=3; i<n+1; i++){
        a[i] = a[i-1] + a[i-2] + a[i-3];
    }
    
    return a[n];
}

int main(){
    int test, n;
    cin>>test;
    while(test--){
        cin>>n;
        cout<<distance(n)<<'\n';
    }
}