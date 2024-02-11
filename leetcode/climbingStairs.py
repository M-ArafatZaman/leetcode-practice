
# https://leetcode.com/problems/climbing-stairs/
class Solution:
    def climbStairs(self, n: int) -> int:
        if n == 1 or n == 0: return 1
        dp = [0] * (n+1)
        dp[0] = 0
        dp[1] = 1
        dp[2] = 2
        if n < 2: return dp[n]

        for i in range(3, n+1):
            dp[i] = dp[i-1] + dp[i-2]

        return dp[n]



if __name__ == "__main__":
    runner = Solution()
    print(runner.climbStairs(2))
    print(runner.climbStairs(3))

