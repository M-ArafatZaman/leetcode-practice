# https://leetcode.com/problems/container-with-most-water/description/
class Solution:
    def maxArea(self, height: List[int]) -> int:
        m = 0
        l, r = 0, len(height) - 1

        while l < r:
            a = (r - l) * min(height[l], height[r])

            if a > m:
                m = a
            
            if height[l] < height[r]:
                l += 1
            else:
                r -= 1

        return m