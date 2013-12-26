First Try:
//用vector模拟队列操作，太傻了
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
     vector<vector<int> > levelOrderBottom(TreeNode *root) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        vector<vector<int> > v_res;
        vector<int> v;
        vector<TreeNode*> tree;
        int head = 0, tail = 0;
        if(root){
            tree.push_back(root);
            tail++;
        }
        while(head!=tail){
            int tail_current = tail;
            for(; head<tail_current; head++){
                v.push_back(tree[head]->val);
                if(tree[head]->left){
                    tree.push_back(tree[head]->left);
                    tail++;
                }
                if(tree[head]->right){
                    tree.push_back(tree[head]->right);
                    tail++;
                }
            }
            v_res.push_back(v);
            v.clear();
        }
        reverse(v_res.begin(), v_res.end());
        return v_res;
    }
};

Second Try:
//用队列实现, 很清楚的过程, 无需多言
class Solution {
public:
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        vector<vector<int>> v_res;
        vector<int> v;
        queue<TreeNode *> q;
        if(root != nullptr) q.push(root);
        while(!q.empty()){
            int size = q.size();
            for(int i = 0; i < size; i++) {
                TreeNode *t = q.front(); q.pop(); //得到队列头
                v.push_back(t->val);
                if(t->left) q.push(t->left);
                if(t->right) q.push(t->right);
            }
            v_res.push_back(v);
            v.clear();
        }
        reverse(v_res.begin(), v_res.end());
        return v_res;
    }
};