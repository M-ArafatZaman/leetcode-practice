from typing import List
from itertools import accumulate

class Solution:
    def subarraysDivByK(self, nums: List[int], k: int) -> int:
        prefix = list(accumulate(nums))
        right = len(nums) -1
        left = 0
        count = 0
        while left <= right:
            if (prefix[right] - prefix[left] + nums[left]) % k == 0:
                count += 1
            
            if left < right:
                left += 1
            elif left == right:
                left = 0
                right -= 1
        return count
    

if __name__ == "__main__":
    runner = Solution()
    print(runner.subarraysDivByK([4,5,0,-2,-3,1], 5))