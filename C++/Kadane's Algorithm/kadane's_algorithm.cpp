#include<bits/stdc++.h>
using namespace std;

int kadane(int a[], int size){
    int max_current = a[0], max_so_far = a[0];
    for(int i=1; i<size; i++){
        max_current = max(max_current + a[i], a[i]);
        max_so_far = max(max_so_far, max_current);
    }
    return max_so_far;
}

int main() {
    int test, size;
    int a[9999];
    cin>>test;
    while(test--){
        cin>>size;
        for(int i=0; i<size; i++){
            cin>>a[i];
        }
        cout<<kadane(a, size)<<'\n';
    }
}