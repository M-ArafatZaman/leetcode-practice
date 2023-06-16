import java.util.ArrayList;
import java.lang.Math;

// https://leetcode.com/problems/minimum-absolute-difference-in-bst/
// Definition for a binary tree node.
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
};

class Solution {
    ArrayList<Integer> values = new ArrayList<Integer>();
    
    public int getMinimumDifference(TreeNode root) {
        // Get values
        getValues(root);
        int n = values.size();
        int min = Integer.MAX_VALUE;
        int diff = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                diff = Math.abs(values.get(i) - values.get(j));
                if (diff < min && i != j) {
                    min = diff;
                }
            }
        }

        return min;
    }

    public void getValues(TreeNode root) {
        values.add(root.val);

        if (root.left != null) getValues(root.left);
        if (root.right != null) getValues(root.right);
        return;
    }
}