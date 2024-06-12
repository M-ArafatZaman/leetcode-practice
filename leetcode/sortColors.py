from typing import List

# https://leetcode.com/problems/sort-colors/
class Solution:
    def sortColors(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        # Bucket sort
        bucket = {0:0, 1:0, 2:0}
        
        for n in nums:
            bucket[n] += 1
            
        curr = 0
        i = 0
        
        while i < len(nums):
            while bucket[curr] == 0:
                curr += 1
            nums[i] = curr
            bucket[curr] -= 1
            i += 1
        