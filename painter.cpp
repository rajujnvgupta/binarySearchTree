#include<bits/stdc++.h>
using namespace std;

long long int bs(int mid, int A, int B, vector<int>&C){
    int mod = 10000003;
    long long int can_do = 0;
    int painter = 1;
    long long int  maxi = -1;
    int n = C.size();
    for(int i = 0; i < n; i++){
        can_do += C[i];
        if(can_do <= mid){
            continue;
        }else{
           //advance calculated should be reduced
           can_do -= C[i];
           long long int cast = can_do * (long long int)B;
           maxi = max(cast, maxi);
           painter++;
           if(painter > A){
               return -1;
           }
           can_do = 0;
           i--;
        }
    }
    long long int cornercase = can_do*(long long int)B;
    return max(maxi, cornercase); ///because of overflow
}

int paint(int A, int B, vector<int> &C){
    long long int total_unit = 0;
    for(int i = 0; i < (int)C.size(); i++){
        total_unit+=C[i];
    }
    int lo = 0;
    int hi = total_unit;
    int ans = -1;
    while(lo<=hi){
        int mid = lo + (hi-lo)/2;
        long long int isPossible = bs(mid, A, B, C);
        if(isPossible > 0){
            hi = mid-1;
            int mod = 10000003;
            isPossible %= mod;
            ans = (int)isPossible;
        }else{
            lo = mid+1;
        }
    }
    return ans;
}

int main(){
	int A, B, n;
	cin>>A>>B>>n;
	vector<int>C(n);
	for(int i = 0; i < n; i++){
		cin>>C[i];
	}
	int ans = paint(A, B, C);
	cout<<ans<<'\n';
	return 0;
}
