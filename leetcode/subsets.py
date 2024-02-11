from typing import List

# https://leetcode.com/problems/subsets/
class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        ans = []
        self.dfs_subset([], nums, ans)
        return ans


    def dfs_subset(self, curr: List[int], nums: List[int], ans: List[int]):
        if len(nums) == 0:
            ans.append(curr)
            return
        
        self.dfs_subset(curr, nums[1:], ans)
        self.dfs_subset(curr+[nums[0]], nums[1:], ans)
        

if __name__ == "__main__":
    runner = Solution()

    print(runner.subsets([1,2,3]))
    print(runner.subsets([0]))
