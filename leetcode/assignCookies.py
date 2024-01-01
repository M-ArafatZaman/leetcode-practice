from typing import List

# https://leetcode.com/problems/assign-cookies/
class Solution:
    def findContentChildren(self, g: List[int], s: List[int]) -> int:
        res = 0

        g.sort()
        s.sort()

        g_ptr = 0
        s_ptr = 0

        while g_ptr < len(g) and s_ptr < len(s):
            if g[g_ptr] <= s[s_ptr]:
                res += 1
                g_ptr += 1
                
            s_ptr += 1

        return res


if __name__ == "__main__":
    sol = Solution()
    print(sol.findContentChildren([1,2,3], [1,1]))
    print(sol.findContentChildren([1,2], [1,2,3]))
    print(sol.findContentChildren([10,9,8,7], [5,6,7,8]))