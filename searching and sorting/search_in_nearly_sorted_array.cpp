#include <bits/stdc++.h>
using namespace std;

int search(vector<int>& a, int target) {
    int low, high, mid;
    int n = a.size();
    low = 0;
    high = n-1;

    while(low<=high) {

        mid = low + (high-low)/2;
        if(a[mid]==target) {
            return mid;
        }

        if (mid>0) {
            if(a[mid-1]==target) {
                return mid-1;
            }
        }

        if (mid<n-1) {
            if (a[mid+1]==target) {
                return mid+1;
            }
        }

        if(target<a[mid]){
            high = mid-2;
        } else {
            low = mid+2;
        }
    }
    return -1;
}

int main() {
    vector<int> nums;
    int n;
    cin>>n;
    int i;
    for(i=0;i<n;i++) {
        int a;
        cin>>a;
        nums.push_back(a);
    }
    int target;
    cin>>target;
    int min = search(nums, target);
    cout<<min;
}