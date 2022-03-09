// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to find largest rectangular area possible in a given histogram.
    vector<long long> prevSmallerIndex(long long arr[], int n) {
        vector<long long> v(n);
        stack<long long> s;
        
        int i;
        
        for(i=0;i<n;i++){
            while(!s.empty()) {
                if (arr[s.top()] < arr[i]) {
                    v[i] = s.top();
                    break;
                }
                s.pop();
            }
            
            if(s.empty()){
                v[i] = -1;
            }
            s.push(i);
        }
        
        return v;
    }
    
    vector<long long> nextSmallerIndex(long long arr[], int n) {
        vector<long long> v(n);
        stack<long long> s;
        
        int i;
        
        for(i=n-1;i>-1;i--) {
            while(!s.empty()) {
                if(arr[s.top()] < arr[i]) {
                    v[i] = s.top();
                    break;
                }
                s.pop();
            }
            
            if(s.empty()) {
                v[i] = n;
            }
            s.push(i);
        }
        return v;
    }
    
    long long getMaxArea(long long arr[], int n)
    {
        // Your code here
        vector<long long> ps;
        vector<long long> ns;
        
        ps = prevSmallerIndex(arr, n);
        ns = nextSmallerIndex(arr, n);
        
        long long m = 0;
        for(int i = 0; i<n; i++) {
            long long diff = ns[i]-1-ps[i];
            long long temp = diff*arr[i];
            if(temp>m) m = temp;
        }
        
        return m;
        return 0;
        
    }
};


// { Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.getMaxArea(arr, n)<<endl;
    
    }
	return 0;
}