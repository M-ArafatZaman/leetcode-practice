from typing import List

# https://leetcode.com/problems/longest-increasing-subsequence/
class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        # solve this problem using dynamic programming
        # dp[i] = length of longest increasing subsequence ending at index i
        # dp[i] = max(dp[j] + 1) for all j < i and nums[j] < nums[i]
        # answer is max(dp)
        n = len(nums)
        dp = [1] * n
        for i in range(n):
            for j in range(i):
                if nums[j] < nums[i]:
                    dp[i] = max(dp[i], dp[j] + 1)
        return max(dp)

if __name__ == "__main__":
    runner = Solution()
    print(runner.lengthOfLIS([10,9,2,5,3,7,101,18]))
    print(runner.lengthOfLIS([0,1,0,3,2,3]))
    print(runner.lengthOfLIS([7,7,7,7,7,7,7]))