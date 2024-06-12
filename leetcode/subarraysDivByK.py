from typing import List
from collections import defaultdict

# https://leetcode.com/problems/subarray-sums-divisible-by-k/
class Solution:
    def subarraysDivByK(self, nums: List[int], k: int) -> int:
        prefixMp = defaultdict(int)
        count = 0
        prefixMp[0] = 1
        curr = 0
        for i in range(len(nums)):
            curr += nums[i]
            count += prefixMp[curr % k]
            prefixMp[curr % k] += 1
        return count

if __name__ == "__main__":
    runner = Solution()
    print(runner.subarraysDivByK([4,5,0,-2,-3,1], 5))
    print(runner.subarraysDivByK([5], 9))