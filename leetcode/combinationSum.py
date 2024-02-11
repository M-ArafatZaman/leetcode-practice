from typing import List
from collections import defaultdict

# https://leetcode.com/problems/combination-sum/
class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        ans = []
        self.results = defaultdict(bool)
        self.dfs_find_sum([], candidates, target, ans)
        return ans

    def dfs_find_sum(self, curr: List[int], candidates: List[int], target: int, ans: List[List[int]]):
        curr_sum = sum(curr)
        if curr_sum == target:
            curr.sort()
            if not self.results[tuple(curr)]:
                ans.append(curr)
                self.results[tuple(curr)] = True
        elif len(candidates) == 0:
            return
        else:
            
            new_candidates = list(filter( lambda x : x <= (target - curr_sum), candidates ))
            for i in new_candidates:
                self.dfs_find_sum(curr+[i], new_candidates, target, ans)


if __name__ == "__main__":
    runner = Solution()

    print(runner.combinationSum([2,3,6,7], 7))
    print(runner.combinationSum([2,3,5], 8))
    print(runner.combinationSum([2], 1))