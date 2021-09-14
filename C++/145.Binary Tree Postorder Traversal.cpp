My solution:
�Ҿ�Ȼ��list˫���������stack���ܲ�רҵ��
������������������ǿվ�ѹջ������������ΪҪ�ȷ�����
��ջ������������1��ջ���ڵ�����Ҷ��ǿսڵ� 2���շ�����ջ���ڵ���ӽڵ�
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
            if(cur -> right == last || cur -> left == last ||		//�ղŷ��ʵ����ӽڵ�
				((cur -> right == NULL) && (cur -> left == NULL)))	//û���ӽڵ��˾�pop
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

��רҵ��solution��
class Solution {
public:
	vector<int> postorderTraversal(TreeNode *root) {
		vector<int> result;
		/* p�����ڷ��ʵĽ�㣬q���ոշ��ʹ��Ľ��*/
		const TreeNode *p, *q;
		stack<const TreeNode *> s;
		p = root;
		do {
			while (p != nullptr) { /* ��������*/
				s.push(p);
				p = p->left;
			}
			q = nullptr;
			while (!s.empty()) {
				p = s.top();
				s.pop();
				/* �Һ��Ӳ����ڻ��ѱ����ʣ�����֮*/
				if (p->right == q) {
					result.push_back(p->val);
					q = p; /* ����շ��ʹ��Ľ��*/
				} 
				else {
					/* ��ǰ��㲻�ܷ��ʣ���ڶ��ν�ջ*/
					s.push(p);
					/* �ȴ���������*/
					p = p->right;
					break;
				}
			}
		} while (!s.empty());
		return result;
	}
};

�Ҿ����������������û�ҵĺã���Ϊwhile������2��while��̫����
�һ�����stack����д�µ�һ�δ����
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
            if(cur -> right == last || cur -> left == last ||		//�ղŷ��ʵ����ӽڵ�
				((cur -> right == NULL) && (cur -> left == NULL)))	//û���ӽڵ��˾�pop
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
