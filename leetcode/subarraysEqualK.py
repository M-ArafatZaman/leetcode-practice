from typing import List
from collections import defaultdict

# https://leetcode.com/problems/subarray-sum-equals-k/
class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        curr = 0
        count = 0
        prefixMp = defaultdict(int)
        prefixMp[0] = 1
        for i in range(len(nums)):
            val = nums[i]
            curr += val
            count += prefixMp[curr-k]
            prefixMp[curr] += 1
        return count
    
if __name__ == "__main__":
    runner = Solution()
    print(runner.subarraySum([1,2,3], 3))
    print(runner.subarraySum([1,1,1], 2))
    print(runner.subarraySum([3], 3))