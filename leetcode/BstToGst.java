/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */

// https://leetcode.com/problems/binary-search-tree-to-greater-sum-tree/
class BstToGst {
    public class TreeNode {
        int val;
        TreeNode left;
        TreeNode right;
        TreeNode() {}
        TreeNode(int val) { this.val = val; }
        TreeNode(int val, TreeNode left, TreeNode right) {
            this.val = val;
            this.left = left;
            this.right = right;
        }
    }
    
    public TreeNode bstToGst(TreeNode root) {
        outOrder(root, 0);
        return root;
    }
    
    // Essentially an inorder trevarsal from right to left
    public int outOrder(TreeNode node, int num) {
        // Right child first
        if (node.right != null) {
            num = outOrder(node.right, num);
        }
        num += node.val;
        node.val = num;
        // Left child 
        if (node.left != null) {
            num = outOrder(node.left, num);
        }
        
        return num;
    }
}