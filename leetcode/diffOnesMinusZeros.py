# https://leetcode.com/problems/difference-between-ones-and-zeros-in-row-and-column/?envType=daily-question&envId=2023-12-14
class Solution:
    def onesMinusZeros(self, grid: List[List[int]]) -> List[List[int]]:
        ones_row = [0] * len(grid)
        ones_col = [0] * len(grid[0])
        zeros_row = [0] * len(grid)
        zeros_col = [0] * len(grid[0])

        for r in range(len(grid)):
            for c in range(len(grid[r])):
                if grid[r][c] == 1:
                    ones_row[r] += 1
                    ones_col[c] += 1
                elif grid[r][c] == 0:
                    zeros_row[r] += 1
                    zeros_col[c] += 1
        
        diff = [[0] * len(grid[0]) for _ in grid]

        for r in range(len(diff)):
            for c in range(len(diff[0])):
                diff[r][c] = ones_row[r] + ones_col[c] - zeros_row[r] - zeros_col[c]
        
        return diff

