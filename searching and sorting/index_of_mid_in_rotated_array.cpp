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

    int min = findMinIndex(nums);
    cout<<endl<<min;
}