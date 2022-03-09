#include <bits/stdc++.h>
using namespace std;

int search(int arr[], int n, int x) {
    int high, low, mid;
    high = n-1;
    low = 0;

    while(low<=high) {
        mid = (low+high)/2;

        if(arr[mid]<x) {
            high = mid -1;
        } else if (arr[mid] > x) {
            low = mid+1;
        } else {
            return mid;
        }
    }

    return -1;
}

int main() {
    int n;
    cin>>n;
    int arr[n];
    int i;
    for(i=0;i<n;i++) {
        cin>>arr[i];
    }

    int x;
    cin>>x;
    cout<<endl;
    cout<<search(arr, n, x);
}