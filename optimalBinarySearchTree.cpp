#include <bits/stdc++.h>
#define N 100
using namespace std;
int arr[N];
int n;
int solve(int L, int R, int level){

    ///cases when there is no element
    if(L>R){
        return 0;  
    }

    int mn = INT_MAX;
    for(int i = L; i <= R; i++){
        mn = min(mn, level*arr[i]+solve(L, i-1, level+1)+solve(i+1, R, level+1)); ///level will be taken care
    }
    return mn;
}

int main() {

    cin>>n;
    ///int arr[n];
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }
    cout<<solve(0, n-1, 1)<<endl;
    return 0;
}

