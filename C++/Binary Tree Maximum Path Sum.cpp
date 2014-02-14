/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int maxPathSum(TreeNode *root) {  
        int res = INT_MIN;  
        maxPathSumRe(root, res);  
        return res;  
    }  
  
    int maxPathSumRe(TreeNode *node, int &res)  
    {  
        if (!node) return 0;  
        int l = maxPathSumRe(node->left, res);  //返回左边单线最大值
        int r = maxPathSumRe(node->right, res); //返回右边单线最大值
        int sum = max(node->val, max(l, r) + node->val);  //以当前节点为终点的最大可能值（单线）
		//更新最大和
        res = max(res, sum);    //用单线最大值试试
        res = max(res, l + r + node->val);    //用双线最大值试试
        return sum;  
    }  
};

/*可以利用“最大连续子序列和”问题的思路，见Maximum Subarray。如果说Array 只有一个方向的话，
那么Binary Tree 其实只是左、右两个方向而已，我们需要比较两个方向上的值。
不过，Array 可以从头到尾遍历，那么Binary Tree 怎么办呢，我们可以采用Binary Tree 最常用
的dfs 来进行遍历。先算出左右子树的结果L 和R，如果L 大于0，那么对后续结果是有利的，我们
加上L，如果R 大于0，对后续结果也是有利的，继续加上R。*/
class Solution {
public:
	int maxPathSum(TreeNode *root) {
		max_sum = INT_MIN;
		dfs(root);
		return max_sum;
	}
private:
	int max_sum;
	int dfs(const TreeNode *root) {
		if (root == nullptr) return 0;
		//计算左右子树的最大值
		int l = dfs(root->left);
		int r = dfs(root->right);
		int sum = root->val;
		//左右子树的贡献
		if (l > 0) sum += l;
		if (r > 0) sum += r;
		//更新最大和
		max_sum = max(max_sum, sum);
		//返回当前树中单一路径能得到的最大值
		return max(r, l) > 0 ? max(r, l) + root->val : root->val;
	}
};