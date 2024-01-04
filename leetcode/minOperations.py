from collections import Counter
from typing import List
from functools import cache

# https://leetcode.com/problems/minimum-number-of-operations-to-make-array-empty/
class Solution:
    @cache
    def minReduce(self, n: int) -> int:
        if n < 0: return -1
        if n == 1: return -1
        if n == 0: return 0

        two, three = self.minReduce(n-2), self.minReduce(n-3)

        if two == -1 and three == -1: return -1
        if two == -1 and three != -1: return three + 1
        if two != -1 and three == -1: return two + 1

        return min( two, three ) + 1
        
    def minOperations(self, nums: List[int]) -> int:
        a = Counter(nums)
        res = 0
        for i in a:
            r = self.minReduce(a[i])
            if r == -1: return -1
            res += r

        return res


if __name__ == "__main__":
    runner = Solution()
    print(runner.minOperations([2,3,3,2,2,4,2,3,4]))
    print(runner.minOperations([2,1,2,2,3,3]))