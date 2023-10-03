
# https://leetcode.com/problems/scramble-string/description/
# Unsolved - LC HARD

class Solution:
    def isScramble(self, s1: str, s2: str) -> bool:
        if len(s1) != len(s2): return False

        if len(s1) == 1 and len(s2) == 1:
            return s1 == s2


if __name__ == "__main__":
    sol = Solution()
    print(sol.isScramble("great", "rgeat"))
    print(sol.isScramble("abcde", "caebd"))      