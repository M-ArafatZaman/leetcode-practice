from typing import *

class Solution:
    def maxProfit(self, prices: List[int], fee: int) -> int:
        dp: List[List[int]] = [[0 for _ in range(len(prices)+1)] for i in range(len(prices)+1)]
        
        # Buy at i, sell at j
        for i in range(len(prices)):
            for j in range(i, len(prices)):
                if j > i:
                    dp[i][j] = max( dp[i+1][j+1], dp[i+1][j+1] + (prices[j]-prices[i]) - fee )
        
        maxProfit = self.mp(dp, 0)

        return maxProfit

    def mp(self, dp: List[List[int]], s: int) -> int:
        if s == len(dp)-1: return 0

        maxProfit = 0
        for i in range(s, len(dp)):
            for j in range(i, len(dp)):
                if j > i:
                    maxProfit = max(maxProfit, dp[i][j]+self.mp(dp, j))

        return maxProfit

if __name__ == "__main__":
    sol = Solution()
    print(sol.maxProfit([1,3,2,8,4,9], 2))
