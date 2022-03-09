class Solution:
    def nextPermutation(self, nums):
        """
        Do not return anything, modify nums in-place instead.
        """
        f = False
        temp = -1
        for i in range(len(nums)-1, 0, -1):
            if(nums[i]>nums[i-1]):
                temp = i-1
                f = True
                break
        
        if(not f):
            nums.reverse()
            return
            
            
        t = 0
        for i in range(len(nums)-1, temp, -1):
            if nums[i]>nums[temp]:
                t = nums[i]
                nums[i] = nums[temp]
                nums[temp] = t
                break
        a = nums[:temp+1] + list(reversed(nums[temp+1:]))

        for i in range(len(a)):
            nums[i] = a[i]