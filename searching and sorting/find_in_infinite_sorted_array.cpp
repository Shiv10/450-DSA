#include <bits/stdc++.h>
using namespace std;

int search(vector<int>& a, int target) {
    int start, end, mid;
    start = 0;
    end = 1;

    bool check = true;

    while(start<=end) {
        if(a[end]<target && check) {
            check = false;
            end = end*2;
            continue;
        }

        mid = start + (end-start)/2;
        if(a[mid]==target) {
            return mid;
        }

        if(a[mid]<target) {
            start = mid+1;
        } else {
            end = mid-1;
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