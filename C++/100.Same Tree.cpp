First Try:
/**
* Definition for binary tree
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/
//use recursion
class Solution {
public:
   bool isSameTree(TreeNode *p, TreeNode *q) {
       // Note: The Solution object is instantiated only once and is reused by each test case.
       if(p == nullptr && q == nullptr) return true;
       if(p == nullptr || q == nullptr) return false;
       return (p->val == q->val) && isSameTree(p->right,q->right) && isSameTree(p->left,q->left);
   }
};

Second Try:
//use iteration
class Solution {
public:
	bool isSameTree(TreeNode *p, TreeNode *q) {
		stack<TreeNode *> s;
		s.push(p);
		s.push(q);
		while(!s.empty()){
			p = s.top(); s.pop();
			q = s.top(); s.pop();
			if(p == nullptr && q == nullptr) continue;
			if(p == nullptr || q == nullptr) return false;
			if(p->val != q->val) return false;
			s.push(p->left);
			s.push(q->left);
			s.push(p->right);
			s.push(q->right);
		}
		return true;
	}
};