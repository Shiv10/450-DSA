#include <bits/stdc++.h>
using namespace std;

int find(int a[], int n, int target) {
    int high, low, mid, i=-1;
    low = 0;
    high = n-1;

    while(low<=high) {
        mid = low + (high-low)/2;
        if(a[mid]==target) {
            return mid;
        }

        if (a[mid]>target) {
            high = mid-1;
        } else {
            i = mid;
            low = mid+1;
        }
    }

    return i;
}

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
        int ans;
        ans=find(arr, n, x);
        cout<<arr[ans]<<endl;
    }
    return 0;
}