from typing import List

# https://leetcode.com/problems/subsets-ii/
class Solution:
    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        sol = set()
        self.dfs_subset(0, [], nums, sol)
        sol = list(map(list, sol))
        return sol

    def dfs_subset(self, i: int, curr: List[int], nums: List[int], sol: List[int]):
        if i == len(nums):
            curr.sort()
            sol.add(tuple(curr))
            return

        self.dfs_subset(i+1, curr, nums, sol)
        self.dfs_subset(i+1, curr+[nums[i]], nums, sol)


if __name__ == "__main__":
    runner = Solution()

    print(runner.subsetsWithDup([1, 2, 2]))
    print(runner.subsetsWithDup([0]))
