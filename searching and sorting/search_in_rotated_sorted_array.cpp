#include <bits/stdc++.h>
using namespace std;

int findMinIndex(vector<int>& nums) {
    int low, high, mid;
    int n = nums.size();
    low = 0;
    high = n-1;
    
    
    if(n==1) {
        return 0;
    }
    
    if(nums[high]>nums[0]) {
        return 0;
    }
    
    while (low<=high) {
        mid = (low+high)/2;
        
        if(nums[mid]>nums[mid+1]) {
            return mid+1;
        }
        
        if (nums[mid-1] > nums[mid]){
            return mid;
        }
        
        if(nums[mid]>nums[0]) {
            low = mid+1;
        } else {
            high = mid - 1;
        }
    }
    
    return -1;
}

int searchBin(vector<int>& nums, int target, int low, int high) {
    int mid;
    
    while(low<=high) {
        mid = low + (high-low)/2;
        
        if(nums[mid]==target) {
            return mid;
        }
        
        if(nums[mid]>target) {
            high = mid-1;
        } else {
            low = mid+1;
        }
    }
    return -1;
}

int search(vector<int>& nums, int target) {
    int mid = findMinIndex(nums);
    int index = searchBin(nums, target, 0, mid-1);
    if(index!=-1) return index;
    
    index = searchBin(nums, target, mid, nums.size()-1);
    return index;
    
}

int main(){
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