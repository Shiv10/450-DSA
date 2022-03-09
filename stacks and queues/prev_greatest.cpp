// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to find the next greater element for each element of the array.
    vector<long long> prevLargerElement(vector<long long> arr, int n){
        // Your code here
        vector<long long> v(n);
        stack<long long> s;
        long long i;
        for(i=0; i<n; i++) {
            while(!s.empty()) {
                if(s.top()>arr[i]) {
                    v[i] = s.top();
                    break;
                }
                s.pop();
            }
            
            if(s.empty()){
                v[i] = -1;
            }
            s.push(arr[i]);
        }
        return v;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        
        int n;
        cin>>n;
        vector<long long> arr(n);
        for(int i=0;i<n;i++)
            cin>>arr[i];
        
        Solution obj;
        vector <long long> res = obj.prevLargerElement(arr, n);
        for (long long i : res) cout << i << " ";
        cout<<endl;
    }
	return 0;
}  // } Driver Code Ends