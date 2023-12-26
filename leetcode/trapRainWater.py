from typing import List

# https://leetcode.com/problems/trapping-rain-water/
class Solution:
    def trap(self, height: List[int]) -> int:
        max_suffix = [height[-1]] * len(height)
        max_prefix = [height[0]] * len(height)
        
        # Build prefix and suffix
        for i in range(1, len(height)):
            max_prefix[i] = max(height[i], max_prefix[i-1])

        for i in range(len(height)-2,-1,-1):
            max_suffix[i] = max(height[i], max_suffix[i+1])

        water = 0
        
        for i in range(1, len(height)-1):
            if height[i] < max_prefix[i-1] and height[i] < max_suffix[i+1]:
                water += min(max_prefix[i-1], max_suffix[i+1]) - height[i]
        
        return water


if __name__ == "__main__":
    sol = Solution()
    inputs = [
        [0,1,0,2,1,0,1,3,2,1,2,1],
        [4,2,0,3,2,5]
    ]
    [print(sol.trap(i)) for i in inputs]