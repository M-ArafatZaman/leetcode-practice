// https://leetcode.com/problems/binary-tree-postorder-traversal/
class Solution {
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

    public static void main(String[] args) {
        // Todo: Add testcase
    }

    public List<Integer> postorderTraversal(TreeNode root) {
        List<Integer> res = new ArrayList<>();
        Stack<TreeNode> stack = new Stack<>();
        stack.push(root);
        // Do a pre order, root, right, left
        while (stack.size() > 0) {
            TreeNode curr = stack.pop();
            if (curr == null) continue;
            if (curr.left != null) stack.push(curr.left);
            if (curr.right != null) stack.push(curr.right);
            res.add(curr.val);
        }
        // Reverse the modified pre order -> left, right, root
        Collections.reverse(res);
        return res;
    }
}