#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    long long int m = 1000000007;
    int nCrHelp(int n, int r, vector<vector<int>> &memo) {
        if(r==n || r==0) {
            return 1;
        }
        
        if(memo[n][r]!=-1) return memo[n][r];
        
        int ans = nCrHelp(n-1, r-1, memo)%m + nCrHelp(n-1,r, memo)%m;
        return memo[n][r] = ans%m;
    }
    int nCr(int n, int r){
        // code here
        if (r>n) {
            return 0;
        };
        vector<vector<int>> memo(n+1, vector<int>(r+1, -1));
        int ans = nCrHelp(n, r, memo);
        return ans;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, r;
        cin>>n>>r;
        
        Solution ob;
        cout<<ob.nCr(n, r)<<endl;
    }
    return 0;
}  // } Driver Code Ends