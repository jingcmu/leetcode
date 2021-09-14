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
��i�ڵ�Ϊ����BST�ĸ�����������������������������������
������3��ѭ���ӵݹ鹹���ķ�����ÿ������д�begin��end�Ľڵ��������й���
*/
class Solution {
public:
	//���ص���BST������������ŵĶ��Ƿ����ǲ��BST
    vector<TreeNode *> generateTrees(int begin, int end){
        vector<TreeNode *> ret(0);
        if(begin>end) return ret;
        for(int i=begin; i<=end; i++){
			//�õ����������Ĳ�ͬBST���
            vector<TreeNode *> left = generateTrees(begin, i-1);
            vector<TreeNode *> right = generateTrees(i+1, end);
            for(int j=0; j<left.size(); j++){
                for(int k=0; k<right.size(); k++){
                    TreeNode *Node = new TreeNode(i);
                    Node->left = left[j]; //�������ĵ�j��BST
                    Node->right = right[k]; //�������ĵ�k��BST
                    ret.push_back(Node); //�õ�һ����ǰ��Χ��BST
                }
            }
        }
        return ret;
    }
    vector<TreeNode *> generateTrees(int n) {
        return generateTrees(1,n);
    }
};