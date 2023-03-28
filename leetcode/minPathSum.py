from typing import List
from numpy import array
from copy import deepcopy

# https://leetcode.com/problems/minimum-path-sum/
class Solution:
    def minPathSum(self, grid: List[List[int]]) -> int:
        dp: List[List[int]] = [[0 for j in i] for i in grid]

        for i in range(len(grid)):
            for j in range(len(grid[i])):
                up = None
                left = None
                if i > 0: up = dp[i-1][j]
                if j > 0: left = dp[i][j-1]
                
                dp[i][j] = grid[i][j]
                if up != None and left != None:
                    dp[i][j] += min(up, left)
                elif up != None and left == None:
                    dp[i][j] += up
                elif up == None and left != None:
                    dp[i][j] += left

        return dp[len(dp)-1][len(dp[0])-1] 


if __name__ == "__main__":
    sol = Solution()
    grid = [[0,2,2,6,4,1,6,2,9,9,5,8,4,4],[0,3,6,4,5,5,9,7,8,3,9,9,5,4],[6,9,0,7,2,2,5,6,3,1,0,4,2,5],[3,8,2,3,2,8,8,7,5,9,6,3,4,5],[4,0,1,3,9,2,0,1,6,7,9,2,8,9],[6,2,7,9,0,9,5,2,7,5,1,4,4,7],[9,8,3,3,0,6,8,0,8,8,3,5,7,3],[7,7,4,5,9,1,5,0,2,2,2,1,7,4],[5,1,3,4,1,6,0,4,3,8,4,3,9,9],[0,6,4,9,4,1,5,5,4,2,5,7,4,0],[0,1,6,6,4,9,2,7,8,2,1,3,3,7],[8,4,9,9,2,3,8,6,6,5,4,1,7,9]]
    print(array(grid))
    print(sol.minPathSum(grid))