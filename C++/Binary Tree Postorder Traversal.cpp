My solution:
我居然用list双向链表代替stack，很不专业啊
过程是如果左右子树非空就压栈（先右再左，因为要先访问左）
出栈有两个条件：1、栈顶节点的左右都是空节点 2、刚访问了栈顶节点的子节点
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
    vector<int> postorderTraversal(TreeNode *root) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        vector<int> ans;
        TreeNode *last = root, *cur;
        list<TreeNode*> node_list;
        if(root == NULL) return ans;
        node_list.push_front(root);
        while(!node_list.empty())
        {
            cur= node_list.front();
            if(cur -> right == last || cur -> left == last ||		//刚才访问的是子节点
				((cur -> right == NULL) && (cur -> left == NULL)))	//没有子节点了就pop
            {
                node_list.pop_front();
                ans.push_back(cur -> val);
                last = cur;
            }
            else {
                if(cur -> right != NULL) node_list.push_front(cur -> right);//right son first
                if(cur -> left != NULL) node_list.push_front(cur -> left); //left son second
            }
        }
    }
};

更专业的solution：
class Solution {
public:
	vector<int> postorderTraversal(TreeNode *root) {
		vector<int> result;
		/* p，正在访问的结点，q，刚刚访问过的结点*/
		const TreeNode *p, *q;
		stack<const TreeNode *> s;
		p = root;
		do {
			while (p != nullptr) { /* 往左下走*/
				s.push(p);
				p = p->left;
			}
			q = nullptr;
			while (!s.empty()) {
				p = s.top();
				s.pop();
				/* 右孩子不存在或已被访问，访问之*/
				if (p->right == q) {
					result.push_back(p->val);
					q = p; /* 保存刚访问过的结点*/
				} 
				else {
					/* 当前结点不能访问，需第二次进栈*/
					s.push(p);
					/* 先处理右子树*/
					p = p->right;
					break;
				}
			}
		} while (!s.empty());
		return result;
	}
};

我觉得上面这个方法还没我的好，因为while里面套2个while，太绕了
我还是用stack来改写下第一段代码吧
class Solution {
public:
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> ans;
        const TreeNode *last = root, *cur;
        stack<const TreeNode *> node_list;
        if(root == NULL) return ans;
        node_list.push(root);
        while(!node_list.empty())
        {
            cur= node_list.top();
            if(cur -> right == last || cur -> left == last ||		//刚才访问的是子节点
				((cur -> right == NULL) && (cur -> left == NULL)))	//没有子节点了就pop
            {
                node_list.pop();
                ans.push_back(cur -> val);
                last = cur;
            }
            else {
                if(cur -> right != NULL) node_list.push(cur -> right);//right son first
                if(cur -> left != NULL) node_list.push(cur -> left); //left son second
            }
        }
    }
};
