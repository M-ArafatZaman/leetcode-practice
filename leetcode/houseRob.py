from typing import List

# https://leetcode.com/problems/house-robber/
class Solution:
    def rob(self, nums: List[int]) -> int:
        dp = [0] * (len(nums) + 1)

        if len(nums) == 1:
            return nums[0]
        
        dp[1] = nums[0]

        for i in range(2, len(dp)):
            dp[i] = max( dp[i-1], dp[i-2] + nums[i-1] )

        return dp[-1]


if __name__ == "__main__":
    runner = Solution()

    print(runner.rob([1,2,3,1]))
    print(runner.rob([2,7,9,3,1]))