from typing import List
from itertools import accumulate

# https://leetcode.com/problems/minimum-cost-for-tickets/
class Solution:
    def mincostTickets(self, days: List[int], costs: List[int]) -> int:
        dp: List[int] = [0 for _ in range(366)]
        curr = 0
        for i in range(len(dp)):
            if curr < len(days) and days[curr] == i:
                dp[i] = min(dp[i-1] + costs[0], dp[i-7] + costs[1], dp[i-30] + costs[2] )
                curr += 1
            else:
                dp[i] = dp[i-1]
        return dp[-1]


if __name__ == "__main__":
    days = [1,4,6,7,8,365]
    costs = [2,7,15]
    sol = Solution()
    print(sol.mincostTickets(days, costs))