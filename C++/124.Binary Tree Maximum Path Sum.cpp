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
        int l = maxPathSumRe(node->left, res);  //������ߵ������ֵ
        int r = maxPathSumRe(node->right, res); //�����ұߵ������ֵ
        int sum = max(node->val, max(l, r) + node->val);  //�Ե�ǰ�ڵ�Ϊ�յ��������ֵ�����ߣ�
		//��������
        res = max(res, sum);    //�õ������ֵ����
        res = max(res, l + r + node->val);    //��˫�����ֵ����
        return sum;  
    }  
};

/*�������á�������������к͡������˼·����Maximum Subarray�����˵Array ֻ��һ������Ļ���
��ôBinary Tree ��ʵֻ����������������ѣ�������Ҫ�Ƚ����������ϵ�ֵ��
������Array ���Դ�ͷ��β��������ôBinary Tree ��ô���أ����ǿ��Բ���Binary Tree ���
��dfs �����б�������������������Ľ��L ��R�����L ����0����ô�Ժ�������������ģ�����
����L�����R ����0���Ժ������Ҳ�������ģ���������R��*/
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
		//�����������������ֵ
		int l = dfs(root->left);
		int r = dfs(root->right);
		int sum = root->val;
		//���������Ĺ���
		if (l > 0) sum += l;
		if (r > 0) sum += r;
		//��������
		max_sum = max(max_sum, sum);
		//���ص�ǰ���е�һ·���ܵõ������ֵ
		return max(r, l) > 0 ? max(r, l) + root->val : root->val;
	}
};