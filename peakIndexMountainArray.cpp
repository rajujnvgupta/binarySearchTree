/*
    @rajujnvgupta
    04/nov/2019

    leetcode.com
    Peak Index in a Mountain Array
*/

#include <bits/stdc++.h>
using namespace std;
const int inf = -1e18+5;

int peakIndexInMountainArray(vector<int>& A) {
        
        int l = 0, r = A.size()-1;
        int index = 0;;
        while(l<=r){
           int mid = l+(r-l)/2;
            if(A[mid] > ((mid > 0)?A[mid-1]:inf)){///precedence matter 
                l = mid+1;
                index = mid;
            }
            else{
                r = mid-1;
            }
        }
        return index;
    }

int main() {
    int n;
    cin>>n;
    vector<int>mountain(n);
    for(int i= 0; i < n; i++){
        cin>>mountain[i];
    }
    cout<<peakIndexInMountainArray(mountain)<<endl;
    return 0;
}

