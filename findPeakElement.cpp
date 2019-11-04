/*
    @rajujnvgupta
    04/nov/2019

    leetcode.com
    problem name : Find Peak Element
*/

#include <bits/stdc++.h>
using namespace std;
const int inf = -1e18+5;

int findPeakElement(vector<int>& nums){
        int index = 0;
        int l = 0, r = nums.size()-1;
        if(nums.size()==1){
            return 0;
        }
        
        while(l<=r){
            
            int mid = l + (r-l)/2;
        
            if(nums[mid] > ((mid>0)?nums[mid-1]:inf)){
                index = mid;
                l = mid+1;                
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
    cout<<findPeakElement(mountain)<<endl;
    return 0;
}

