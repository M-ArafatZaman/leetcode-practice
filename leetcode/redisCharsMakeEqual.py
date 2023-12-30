from collections import Counter
from typing import List

# https://leetcode.com/problems/redistribute-characters-to-make-all-strings-equal/
class Solution:
    def makeEqual(self, words: List[str]) -> bool:
        c = Counter("".join(words))
        for i in c:
            if (c[i] // len(words)) - (c[i] / len(words)) != 0: return False
        return True

if __name__ == "__main__":
    sol = Solution()
    print(sol.makeEqual(["abc","aabc","bc"]))
    print(sol.makeEqual(["ab","a"]))