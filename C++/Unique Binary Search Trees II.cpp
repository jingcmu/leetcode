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
以i节点为根的BST的个数等于其左子树个数乘以右子树个数，
此题用3重循环加递归构建的方法，每层对所有从begin到end的节点做根进行构建
*/
class Solution {
public:
	//返回的是BST的向量，里面放的都是返回那层的BST
    vector<TreeNode *> generateTrees(int begin, int end){
        vector<TreeNode *> ret(0);
        if(begin>end) return ret;
        for(int i=begin; i<=end; i++){
			//得到左右子树的不同BST组合
            vector<TreeNode *> left = generateTrees(begin, i-1);
            vector<TreeNode *> right = generateTrees(i+1, end);
            for(int j=0; j<left.size(); j++){
                for(int k=0; k<right.size(); k++){
                    TreeNode *Node = new TreeNode(i);
                    Node->left = left[j]; //左子树的第j个BST
                    Node->right = right[k]; //右子树的第k个BST
                    ret.push_back(Node); //得到一个当前范围的BST
                }
            }
        }
        return ret;
    }
    vector<TreeNode *> generateTrees(int n) {
        return generateTrees(1,n);
    }
};