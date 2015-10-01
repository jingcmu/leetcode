
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
public class Solution {
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        if (root == null) return null;
        int i = Integer.compare(root.val, p.val);
        int j = Integer.compare(root.val, q.val);
        if (i < 0 && j < 0) {
            return lowestCommonAncestor(root.right, p, q);
        } else if (i > 0 && j > 0) {
            return lowestCommonAncestor(root.left, p, q);
        } else {
            return root;
        }
    }
}
