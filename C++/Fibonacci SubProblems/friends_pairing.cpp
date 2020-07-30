#include<bits/stdc++.h>
using namespace std;

int friends(int n){
    int a[n+1];
    for(int i = 0; i<n+1; i++){
        a[i] = 0;
    }
    for(int i=0; i<=n; i++){
        if(i<=2){
            a[i] = i;
        } else{
            a[i] = a[i-1] + (i-1)*a[i-2];
        }
    }
    return a[n];
}

int main(){
    int test, n;
    cin>>test;
    while(test--){
        cin>>n;
        cout<<friends(n)<<'\n';
    }
}