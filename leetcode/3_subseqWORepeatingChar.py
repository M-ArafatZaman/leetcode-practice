from typing import List, Set

# https://leetcode.com/problems/longest-substring-without-repeating-characters/
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        if len(s) == 0: return 0
        #[largest[], curr[]]
        dp: List[List[List[str], List[str]]] = []
        dp.append([[s[0]], [s[0]]])
        for i in range(1, len(s)):
            largestSet, currSet = dp[i-1]
            if s[i] not in currSet:
                currSet.append(s[i])
            else:
                index = currSet.index(s[i])
                currSet = currSet[index+1:]
                currSet.append(s[i])
            
            if len(currSet) > len(largestSet):
                dp.append([currSet, currSet])
            else:
                dp.append([largestSet, currSet])

        return len(dp[-1][0])


if __name__ == "__main__":
    s = "dvdf"
    sol = Solution()
    print(sol.lengthOfLongestSubstring(s))