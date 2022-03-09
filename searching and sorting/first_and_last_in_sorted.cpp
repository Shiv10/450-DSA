// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
int findHelper(int arr[], int n , int x, bool left )
{
    // code here
    int high = n-1;
    int low = 0;
    int i = -1;
    while(low<=high) {
        int mid = (high+low)/2;
        if(arr[mid]<x) low = mid+1;
        else if (arr[mid]>x) high = mid-1;
        else {
            i = mid;
            if (left) high = mid-1;
            else low = mid+1;
        }
    }
    
    return i;
    
}

vector<int> find(int arr[], int n, int x){
    int left = findHelper(arr, n, x, true);
    int right = findHelper(arr, n, x, false);
    
    vector<int> v;
    v.push_back(left);
    v.push_back(right);
    
    return v;
}


// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        ans=find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}


  // } Driver Code Ends