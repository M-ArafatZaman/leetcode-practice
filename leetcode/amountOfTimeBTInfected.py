from typing import Optional

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def amountOfTime(self, root: Optional[TreeNode], start: int) -> int:
        pass


if __name__ == "__main__":
    l9 = TreeNode(9)
    l2 = TreeNode(2)
    l4 = TreeNode(4, l9, l2)
    l5 = TreeNode(5, None, l4)
    l10 = TreeNode(10)
    l6 = TreeNode(6)
    l3 = TreeNode(3, l10, l6)
    l1 = TreeNode(1, l5, l3)

    runner = Solution()
    print(runner.amountOfTime(l1, 3))

