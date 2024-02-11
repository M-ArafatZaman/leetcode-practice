from typing import List 

# https://leetcode.com/problems/min-cost-climbing-stairs/
class Solution:
    def minCostClimbingStairs(self, cost: List[int]) -> int:
        dp = [0] * (len(cost) + 1)
        dp[0] = 0
        dp[1] = 0

        if len(cost) < 3:
            return min( cost[0], cost[1] )

        for i in range(2, len(dp)):
            dp[i] = min( dp[i-1] + cost[i-1], dp[i-2] + cost[i-2] )

        return dp[-1]


if __name__ == "__main__":
    runner = Solution()

    print(runner.minCostClimbingStairs([10, 15, 20]))
    print(runner.minCostClimbingStairs([1,100,1,1,1,100,1,1,100,1]))
    print(runner.minCostClimbingStairs([1,100]))