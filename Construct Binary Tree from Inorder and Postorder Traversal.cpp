/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/*
思路：中序是  左子树 根 右子树 
      后序是  左子树 右子树 根 
	  所以，先知道根节点了，然后怎么知道左子树和右子树的根节点呢，
	  只需要在中序里面找到根节点（遍历），继而得到左子树长度，
	  就可以构造递归函数，构建起整个二叉树了
*/
class Solution {
public:
    TreeNode *buildTree(vector<int> &inorder, int h1, int t1, vector<int> &postorder, int h2, int t2){
        TreeNode *node;
        if(h1 > t1) return NULL;
        node = new TreeNode(postorder[t2]);
        int index, left_len;
        for(int i=h1; i<=t1; i++){ //在inorder里面找到postorder最后一个元素，这个是父节点
            if(inorder[i] == postorder[t2]){
                index = i;
            }
        }
        left_len = index-h1; //左子树长度
        node->left = buildTree(inorder, h1, index-1, postorder, h2, h2+left_len-1);
        node->right = buildTree(inorder, index+1, t1, postorder, h2+left_len, t2-1);
        return node;
    }
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        int size1 = inorder.size(), size2 = postorder.size();
        if(size1 == 0 || size1 != size2){
            return NULL;
        }
        return buildTree(inorder, 0, size1-1, postorder, 0, size1-1);
    }
};