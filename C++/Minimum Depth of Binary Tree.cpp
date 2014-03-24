/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/*这一题其实最好用BFS，不过我用了DFS*/
class Solution {
public:
    int minDepth(TreeNode *root, int depth) {
        int l_depth, r_depth;
		//终止条件
        if(!root->left && !root->right){
            return depth;
        }
        if(root->left && root->right){
            l_depth = minDepth(root->left,depth+1);
            r_depth = minDepth(root->right,depth+1);
            return l_depth>r_depth?r_depth:l_depth; //返回小的
        }
        else if(root->left){
            return minDepth(root->left,depth+1);
        }
        else if(root->right){
            return minDepth(root->right,depth+1);
        }
    }
    int minDepth(TreeNode *root) {
        if(root == NULL) return 0;
        return minDepth(root, 1);
    }
};

/*Second try：
  BFS的解法 - 用vector模拟队列操作，为啥不用queue呢？queue居然木有clear()函数，不好用啊！
*/
class Solution {
public:
    int minDepth(TreeNode *root) {
        if(root == NULL) return 0;
		vector<TreeNode *> q1, q2;
		q1.push_back(root); //先把root放到队列
		int depth = 1;
		while(!q1.empty()) {
			for(int i=0; i<q1.size(); i++) {
				TreeNode *node = q1[i];
				if(!node->right && !node->left) return depth; //提前返回
				if(node->right) q2.push_back(node->right);
				if(node->left) q2.push_back(node->left);
			}
			q1 = q2; 
			q2.clear();
			++depth; //深度增加一层
		}
		return depth;
    }
};

/*Third try*/
class Solution {
public:
    int minDepth(TreeNode *root) {
        queue<TreeNode *> q;
        if(root == NULL) return 0;
        q.push(root);
        int depth = 1;
        while(!q.empty()) {
            int size = q.size();
            for(int i=0; i<size; i++) {
                TreeNode *node = q.front();
                q.pop();
                if(node->left == NULL && node->right == NULL) {
                    return depth;
                }
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            depth++;
        }
        return 0;
    }
};