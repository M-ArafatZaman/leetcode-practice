from typing import List

# https://leetcode.com/problems/permutations/
class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        sol = []
        # (i, curr)
        stack = []
        stack.append((-1, []))
        
        while len(stack) > 0:
            i, curr = stack.pop()

            if len(curr) == len(nums):
                sol.append(curr)
            else:
                for j in range(len(nums)):
                    if i == j: continue
                    if nums[j] in curr: continue
                    stack.append((j, curr + [nums[j]]))

        return sol


if __name__ == "__main__":
    runner = Solution()
    print(runner.permute([1,2,3]))
    print(runner.permute([0,1]))
    print(runner.permute([1]))

