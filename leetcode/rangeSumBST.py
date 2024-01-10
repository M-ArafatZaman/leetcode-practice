from typing import Optional


# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

# https://leetcode.com/problems/range-sum-of-bst/
class Solution:
    def rangeSumBST(self, root: Optional[TreeNode], low: int, high: int) -> int:
        if not root: return 0
        result = root.val if low <= root.val <= high else 0
        result += self.rangeSumBST(root.left, low, high) if low <= root.val else 0
        result += self.rangeSumBST(root.right, low, high) if root.val <= high else 0
            
        return result
        
    
if __name__ == "__main__":
    # [10,5,15,3,7,null,18]
    l3 = TreeNode(3)
    l7 = TreeNode(7)
    l18 = TreeNode(18)
    n5 = TreeNode(5, l3, l7)
    n15 = TreeNode(15, None, l18)
    r = TreeNode(10, n5, n15)

    sol = Solution()
    print(sol.rangeSumBST(r, 7, 15))
        
        