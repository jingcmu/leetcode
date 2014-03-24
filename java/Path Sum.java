/**
 * Definition for binary tree
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
public class Solution {
    public boolean helper(TreeNode root, int sum, int sum2now) {
        if(root == null) return false;
        sum2now += root.val;
        if(root.left == null && root.right == null) {
            if(sum2now == sum) return true;
        }
        else {
            if(helper(root.left, sum, sum2now) || helper(root.right, sum, sum2now)) {
                return true;
            }
        }
        return false;
    }
    
    public boolean hasPathSum(TreeNode root, int sum) {
        return helper(root, sum, 0);
    }
}