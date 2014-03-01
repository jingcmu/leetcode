------------3Sum.cpp-------------   -1
//跟2sum思路一样，2sum是线性复杂度，3sum是平方复杂度
//关于“一定要跳过重复元素”：例如, -2 -1 -1 0 1 2 中的-1，
//取过了第一个-1，则第二个-1完全没必要再取做第一个元素了
class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        int len = num.size();
        vector<int> v, v_last;
        vector<vector<int> > v_res;
        if(len<3) return v_res;
		//为了后面用两头逼近法，先要排个序
        sort(num.begin(), num.end());
        for(int i=0; i<len-2; i++) {
            int target = 0-num[i]; //计算target
            int head = i+1, tail = len - 1;
			//一定要跳过重复元素
            if(i>0 && num[i] == num[i-1]){
                continue;
            }
			//这里用了2sum的算法
            while(head < tail){
                v.clear();
				//如果找到了一个结果
                if(num[head]+num[tail] == target){
                    v.push_back(num[i]);
                    v.push_back(num[head++]);
                    v.push_back(num[tail--]);
					//v_last记录上一个结果，因为有重复元素，所以需要判重
                    if(v_last != v){
                        v_res.push_back(v);
                        v_last = v;
                    }
                }
                else if(num[head]+num[tail] < target){
                    head++;
                }
                else if(num[head]+num[tail] > target){
                    tail--;
                }
            }
        }
        return v_res;
    }
};

------------3Sum Closest.cpp------------0
//跟3sum没什么不一样
class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        int len = num.size();
        int sum = 0, target_2sum, head, tail;
        int diff, diff_min = (1<<31)-1;
        if(len<=3){
            for(int i=0; i<len; i++){
                sum += num[i];
            }
            return sum;
        }
		//先排序
        sort(num.begin(),num.end());
        for(int i=0; i<len-2; i++){
            target_2sum = target - num[i];
            head = i+1;
            tail = len-1;
			//2sum左右逼近
            while(head < tail){
                sum = num[i]+num[head]+num[tail];
                diff = target - sum;
                if(diff == 0){
                    return target;
                }
                if(diff<0){
                    tail--;
                }
                else if(diff>0){
                    head++;
                }
				//更新最小差距
                if(abs(diff_min)>abs(diff)){
                    diff_min = diff;
                }
            }
        }
        return target - diff_min;
    }
};
--------------end--------------

------------3Sum.cpp------------1
//跟2sum思路一样，2sum是线性复杂度，3sum是平方复杂度
//关于“一定要跳过重复元素”：例如, -2 -1 -1 0 1 2 中的-1，
//取过了第一个-1，则第二个-1完全没必要再取做第一个元素了
class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        int len = num.size();
        vector<int> v, v_last;
        vector<vector<int> > v_res;
        if(len<3) return v_res;
		//为了后面用两头逼近法，先要排个序
        sort(num.begin(), num.end());
        for(int i=0; i<len-2; i++) {
            int target = 0-num[i]; //计算target
            int head = i+1, tail = len - 1;
			//一定要跳过重复元素
            if(i>0 && num[i] == num[i-1]){
                continue;
            }
			//这里用了2sum的算法
            while(head < tail){
                v.clear();
				//如果找到了一个结果
                if(num[head]+num[tail] == target){
                    v.push_back(num[i]);
                    v.push_back(num[head++]);
                    v.push_back(num[tail--]);
					//v_last记录上一个结果，因为有重复元素，所以需要判重
                    if(v_last != v){
                        v_res.push_back(v);
                        v_last = v;
                    }
                }
                else if(num[head]+num[tail] < target){
                    head++;
                }
                else if(num[head]+num[tail] > target){
                    tail--;
                }
            }
        }
        return v_res;
    }
};
--------------end--------------

------------4Sum.cpp------------2
class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        int len = num.size(), target2;
        vector<vector<int> > v_res;
        vector<int> v;
        if(len < 4) return v_res; //如果len小于4，则返回空vector
        sort(num.begin(), num.end()); //对数组排序

		//枚举的时候，位置不发生变化
        for(int i=0; i<len-3; i++){
            for(int j=i+1; j<len-2; j++){
                target2 = target - (num[i]+num[j]);
                int head = j+1, tail = len-1;
                while(head < tail){
                    if(num[head]+num[tail] < target2){
                        head++;
                    }
                    else if(num[head]+num[tail] > target2){
                        tail--;
                    }
                    else{
                        v.push_back(num[i]);
                        v.push_back(num[j]);
                        v.push_back(num[head]);
                        v.push_back(num[tail]);
                        v_res.push_back(v);
                        v.clear();
                        head++;
                        tail--;
                    }
                }
            }
        }
        set<vector<int> > s(v_res.begin(), v_res.end());
        v_res.assign(s.begin(), s.end());
        return v_res;
    }
};
--------------end--------------

------------Add Binary.cpp------------3
//很简单，就是模拟相加，开始的时候先知道那个串更长，这样好做点
class Solution {
public:
    string addBinary(string a, string b) {
        int len_a = a.length(), temp;
        int len_b = b.length();
        int carry = 0;
        string c = "";
        if(len_a < len_b) {
            return addBinary(b, a);
        }
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        for(int i = 0; i < len_a; i++){
			if(i < len_b)
				temp = (a[i]-'0')+(b[i]-'0')+carry;
			else
				temp = (a[i]-'0')+carry;
            if(temp >= 2) carry = 1;
            else carry = 0;
            temp %= 2;
            c += (temp+'0');
        }
        if(carry){
            c += (carry+'0');
        }
        reverse(c.begin(), c.end());
        return c;
    }
};

//另一种写法
class Solution {
public:
	string addBinary(string a, string b) {
		string result;
		const size_t n = a.size() > b.size() ? a.size() : b.size();
		reverse(a.begin(), a.end());
		reverse(b.begin(), b.end());
		int carry = 0;
		for (size_t i = 0; i < n; i++) {
			const int ai = i < a.size() ? a[i] - '0' : 0;
			const int bi = i < b.size() ? b[i] - '0' : 0;
			const int val = (ai + bi + carry) % 2;
			carry = (ai + bi + carry) / 2;
			result.insert(result.begin(), val + '0');
		}
		if (carry == 1) {
			result.insert(result.begin(), '1');
		}
		return result;
	}
};
--------------end--------------

------------Add Two Numbers.cpp------------4
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 /*
 思路：考察基本的链表操作，一种不太好的做法是另外分配一个空间放结果，
 我决定不使用额外空间， 所以第一次写了70多行代码才AC，
 后来经过改进，就变成了下面的40多行代码
 */
class Solution {
public:
    int add(int a, int b, int *carry){
        int res = a+b+*carry;
        if(res >= 10){
            *carry = 1;
            return res%10;
        }
        else{
            *carry = 0;
            return res;
        }
    }
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        int carry = 0;
        ListNode *ll1 = l1, *ll2 = l2, *last;
        if(l1 == NULL){
            return l2;
        }
        if(l2 == NULL){
            return l1;
        }
        while(l1 && l2){
            l2->val = l1->val = add(l1->val, l2->val, &carry);
            last = l1;
            l1 = l1->next;
            l2 = l2->next;
        }
        ListNode *remain = l2?l2:l1, *res = l2?ll2:ll1;
        while(remain){
            remain->val = add(remain->val, 0, &carry);
            last = remain;
            remain = remain->next;
        }
        if(carry){
            last->next = new ListNode(1);
        }
        return res;
    }
};
--------------end--------------

------------Anagrams.cpp------------5
//貌似如果有重复的词也一律认为是anagram，
//而且，只要是anagram一律存到vector里不用担心顺序问题
//思路：对单词排序，然后存入map，如果map中有，则连同
//原有的词一起push到vector
//技巧：如果map中原来没有，则value存的是第一个出现的词的index
//这是为了找到第二个的时候，连同上一个一起存到vector，
//如果已经有了，就存-1，表明之前已经有了
class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        int size = strs.size();
        vector<string> res;
        map<string, int> mp_anagram;
        for(int i=0; i<size; i++){
            string tmp = strs[i];
            sort(tmp.begin(), tmp.end());
            map<string, int>::iterator it = mp_anagram.find(tmp);
            if(it == mp_anagram.end()){
                mp_anagram[tmp] = i;
            }
            else {
                if(mp_anagram[tmp] == -1) {
                    res.push_back(strs[i]);
                }
                else {
					//mp_anagram[tmp]存的是第一个词的index
                    res.push_back(strs[mp_anagram[tmp]]);
                    mp_anagram[tmp] = -1;
                    res.push_back(strs[i]);
                }
            }
        }
        return res;
    }
};
--------------end--------------

------------Balanced Binary Tree.cpp------------6
First Try:
//递归计算两边的深度，深度差不大于1才算平衡
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
    int getDepth(TreeNode *root){
        if(root == NULL)
            return 0;
        else{
            int l, r;
            l = getDepth(root->left);
            r = getDepth(root->right);
            return max(l,r)+1; 
        }
    }
    bool isBalanced(TreeNode *root) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if(root == NULL)
            return true;
        int diff = getDepth(root->left) - getDepth(root->right);
        if(diff > 1  || diff < -1)
            return false;
        if(!isBalanced(root->left) || !isBalanced(root->right))
            return false;
        return true;
    }
};
--------------end--------------

------------Best Time to Buy and Sell Stock II.cpp------------7
First Try:
/*
* find all accending sub-sequence in the vector and get all the profit in each sub-sequence
* sum them up 所有上升子序列相加
*/
class Solution {
public :
   int maxProfit( vector< int> & prices) {
       // Note: The Solution object is instantiated only once and is reused by each test case.
       vector< int> accending;
       int profit = 0;
       if( prices.size()){    
           accending.push_back( prices[0]);  // if prices not null, push first price to vector
       }
       for( int i=0; i<( int) prices.size()-1; i++){
           if( prices[i] > prices[i+1]){  // if the price descend
                profit += accending.back()-accending.front();
                accending.clear();       // clear the vector to save next accending vector
                accending.push_back( prices[i+1]); // push the first price in next sequence
           }
           else {                                  // if the price accend
               accending.push_back( prices[i+1]); // continue to push into vector
           }
       }
       if(accending.size()){
           profit += accending.back()-accending.front(); // for the last accending vector
       }
       return profit;
   }
};

Second Try:
//先把原始价格序列变成差分序列，贪心法，低进高出，把所有正的价格差价相加起来。
class Solution {
public :
	int maxProfit( vector< int> & prices) {
		int sum = 0;
		for(int i=1; i<prices.size(); i++) {
			int diff = prices[i] - prices[i-1];
			if(diff > 0) sum += diff;
		}
		return sum;
	}
}
--------------end--------------

------------Best Time to Buy and Sell Stock III.cpp------------8
/*
思路：O(n平方)的方法，对每个点进行分割，算出这个点两边的最大利润相加
O(n)的方法，先正向算出从起点开始到每个点的最大利润，再逆向算出从每个点开始到终点的最大利润
进而就得出了最大利润，以第i点进行分割，i点不可能同时为前段的终点和后段的起点，所以不用担心
*/
class Solution {
public:
    int maxProfit(vector<int> &prices) 
	{
		vector<int> profit(prices.size());
		int min_price = INT_MAX;
		//先得到从左到右的最大利润(起点固定)
		for (int i = 0; i < prices.size(); i++) {
			if (prices[i] < min_price) min_price = prices[i]; //更新左起最小price
			profit[i] = max(profit[i], prices[i]-min_price); //更新最大利润
		}
		//再得到从右到左的最大利润(终点固定)
		int max_price = INT_MIN , max_profit = 0, res = 0;
		for (int i = prices.size() - 1; i >= 0 ; i--) {
			if (prices[i] > max_price) max_price = prices[i]; //更新右起最大price
			else max_profit = max(max_profit, max_price - prices[i]); //更新最大利润
			res = max(profit[i]+ max_profit, res); 
		}
		return res;
	}
};
--------------end--------------

------------Best Time to Buy and Sell Stock.cpp------------9
/*
扫描一遍，记录下遇到的min price，拿当前price减去min price，
记录下最大的profit
*/
class Solution {
public :
    int maxProfit(vector< int> &prices) {
        int min_price, profit = 0, len = prices.size();
        if(len) min_price = prices[0]; //初始化最小价格
        for(int i=1; i<len; i++){
			//更新最小价格
			min_price = min(prices[i], min_price);
			//用当前最小价格计算最大利润
            profit = prices[i]-min_price > profit? prices[i]-min_price : profit;
        }
        return profit;
    }
};

--------------end--------------

------------Binary Tree Inorder Traversal.cpp------------10
First Try：
递归，只使用一个函数
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
    vector<int> inorderTraversal(TreeNode *root) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        vector<int> v;
        if(root == NULL){
            return v;
        }
        if(root->left){
            vector<int> v_t;
            v_t = inorderTraversal(root->left);
            v.insert(v.end(), v_t.begin(), v_t.end());
        }
        v.push_back(root->val);
        if(root->right){
            vector<int> v_t;
            v_t = inorderTraversal(root->right);
            v.insert(v.end(), v_t.begin(), v_t.end());
        }
        return v;
    }
};

Second Try：
递归, 两个函数
class Solution {
public:
    void inorderTraversal(TreeNode *root, vector<int> &v) {
        if(root->left) inorderTraversal(root->left, v);
        v.push_back(root->val);
        if(root->right) inorderTraversal(root->right, v);
    }
    
    vector<int> inorderTraversal(TreeNode *root) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        vector<int> v;
        if(root == NULL){
            return v;
        }
        inorderTraversal(root, v);
        return v;
    }
};

Thrid Try:
非递归，栈
class Solution {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        stack<TreeNode *> s;
        vector<int> v;
        TreeNode *p = root;
        while(p != nullptr || !s.empty()) {
            if(p != nullptr) {
                s.push(p);
                p = p->left;
            }
            else {
                p = s.top(); s.pop();
                v.push_back(p->val);
                p = p->right;
            }
        }
        return v;
    }
};
--------------end--------------

------------Binary Tree Level Order Traversal II.cpp------------11
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
--------------end--------------

------------Binary Tree Maximum Path Sum.cpp------------12
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
--------------end--------------

------------Binary Tree Postorder Traversal.cpp------------13
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

--------------end--------------

------------Binary Tree Preorder Traversal.cpp------------14
First Try:  非递归，用栈实现
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 //先序遍历只需要一个栈
 //先访问当前节点，然后把当前节点入栈
 //接着访问左节点并入栈直到再无左节点
 //出栈开始对右节点的访问，这个流程要烂熟于心
class Solution {
public:
    vector<int> preorderTraversal(TreeNode *root) {
        stack<TreeNode *> s;
        vector<int> v;
		TreeNode *p = root;
        while(p != nullptr || !s.empty()){
            if(p != nullptr){
                v.push_back(p->val); 
                s.push(p);
                p = p->left;
            }
            else{
                p = s.top();
                s.pop();
                p = p->right;
            }
        }
        return v;
    }
};

Second Try：
class Solution {
public:
	void preorderTraversal(TreeNode *root, vector<int> &v) {
		v.push_back(root->val);
		if(root->left != nullptr) preorderTraversal(root->left, v);
		if(root->right != nullptr) preorderTraversal(root->right, v);
	}

    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> v;
        v.clear();
		if(root == nullptr) return v;
        preorderTraversal(root, v);
        return v;
    }
};

Third Try:
class Solution {
public:
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> result;
        const TreeNode *p;
        stack<const TreeNode *> s;
        p = root;
        if (p != nullptr) s.push(p);
        while (!s.empty()) {
            p = s.top();
            s.pop();
            result.push_back(p->val);
            if (p->right != nullptr) s.push(p->right);
            if (p->left != nullptr) s.push(p->left);
        }
        return result;
    }
};
--------------end--------------

------------Binary Tree Zigzag Level Order Traversal.cpp------------15
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
其实就是按层访问的变形，用一个队列，用一个变量记录行号，
对奇数行逆序，对偶数行保留原来的顺序不变
*/
class Solution {
public:
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        vector<vector<int> > ret;
        queue<TreeNode *> TreeQueue;
        TreeNode *temp;
        TreeQueue.push(root);
        int size;
        if(!root) return ret;
        while(size = TreeQueue.size()) { //得到当前队列的size
            vector<int> v;
			//把当前队列全部出列，并放到ret中，同时push下一层的节点
            for(int i=0; i<size; i++){ 
                temp = TreeQueue.front();
                TreeQueue.pop();
                v.push_back(temp->val);
                if(temp->left) TreeQueue.push(temp->left);
                if(temp->right) TreeQueue.push(temp->right);
            }
            ret.push_back(v);
        }
        for(int i=0; i<ret.size(); i++){
            if(i%2){ //奇数行逆序
                reverse(ret[i].begin(), ret[i].end());
            }
        }
        return ret;
    }
};
--------------end--------------

------------Candy.cpp------------16
/*
从不同方向扫描两遍即可
*/
class Solution {
public:
    int candy(vector<int> &ratings) {
        int size = ratings.size();
		//给每个人一个糖
        vector<int> candy(size, 1);
		//先从左向右扫描
        for(int i=1; i<size; i++){
           if(ratings[i] > ratings[i-1]){
               candy[i] = candy[i-1] + 1;
           } 
        }
        int res = candy[size-1];
		//再从右向左扫描
        for(int i=size-2; i>=0; i--){
           if(ratings[i] > ratings[i+1] && candy[i] <= candy[i+1]){
               candy[i] = candy[i+1] + 1;
           }
           res += candy[i];
        }
        return res;
    }
};
--------------end--------------

------------Climbing Stairs.cpp------------17
First Try:
//最简单的动态规划
class Solution {
public:
    int climbStairs(int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int *k = new int[n+1];
        k[1] = 1; k[2] = 2;
        for(int i=3; i<=n; i++){
            k[i] = k[i-1] + k[i-2];
        }
        return k[n];
    }
};

Second Try：
//O(1)的空间复杂度
class Solution {
public:
    int climbStairs(int n) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        int a = 1, b = 2, c;
        if(n==1) return a;
        if(n==2) return b;
        for(int i=3; i<=n; i++){
            c = a+b;
            a = b;
            b = c;
        }
        return c;
    }
};
--------------end--------------

------------Clone Graph.cpp------------18
/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
/*
这里只能克隆连通图（当然）
方法：从一个点开始克隆，然后开始neighbor的克隆，用一个map记录visited，避免重复访问
*/
class Solution {
private:
    map<UndirectedGraphNode *, UndirectedGraphNode *> visited;
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if(node == NULL){
            return NULL;
        }
        if(visited[node]){
            return visited[node];
        }
        UndirectedGraphNode *first_node = new UndirectedGraphNode(node->label);
        visited[node] = first_node;
        for(int i=0; i<node->neighbors.size(); i++){
            first_node->neighbors.push_back(cloneGraph(node->neighbors[i]));
        }
        
        return first_node;
    }
};
--------------end--------------

------------Combination Sum II.cpp------------19
//1.这个写法太巧妙了！！！
//每个元素是先取，再不取，不取的话，后面出现的重复元素也不取
//取的话，后面递归进到下一级了，仍然可以取，这样就不必写复杂的判断
//不需要统计每个元素出现的次数，居然也不必给结果排序和去重！！！
//2.其实也可以先统计元素出现的次数，然后按照Combination Sum I的写法来做
//那样的话就必须给结果排序和去重，代码容易理解但是会比较长
class Solution {
public:
	vector<vector<int> > combinationSum2(vector<int> &nums, int target) {
		sort(nums.begin(), nums.end());
		vector<int> intermediate;
		dfs(nums, target, 0, intermediate);
		return result;
	}
private:
    vector<vector<int> > result;
	// 使用nums[start, nums.size()) 之间的元素，能找到的所有可行解
	void dfs(vector<int> &nums, int target, int start, vector<int> &intermediate){
		if (target == 0) { // 找到一个合法解
			result.push_back(intermediate);
			return;
		}
		int previous = -1;
		for (size_t i = start; i < nums.size(); i++) {
			//如果之前出现的没有取的话，后面的相同元素也不必取
			if (previous == nums[i]) continue;
			if (target < nums[i]) return; // 剪枝
			previous = nums[i];
			intermediate.push_back(nums[i]);
			dfs(nums, target - nums[i], i + 1, intermediate);
			intermediate.pop_back(); // 恢复环境
		}
	}
};

--------------end--------------

------------Combination Sum.cpp------------20
//深度优先搜索
//这一题用动归不好做，因为要记录
class Solution {
private:
    vector<vector<int> > ret;
    vector<int> count;          
public:
	//参数：当前操作的数的索引currentIndex，数组的长度len，目标和target，数组candidates
    void helper(int currentIndex, int len, int target, vector<int> &candidates){
        vector<int> v;
        if(target < 0) return; //不满足条件退出
        if(currentIndex == len){ //得到答案退出
            if(target == 0){ //如果和等于0,得到一组解
                for(int i=0; i<currentIndex; i++){
                    for(int j=0; j<count[i]; j++){
                        v.push_back(candidates[i]);
                    }
                }
                ret.push_back(v);
            }
            return;
        }
		//
        int num = target/candidates[currentIndex]; //当前数最大的循环次数
        for(int i=0; i<=num; i++) { //循环从0开始，代表不取
            count[currentIndex] = i;
            helper(currentIndex+1, len, target-candidates[currentIndex]*i, candidates);
        }
    }

    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        int len = candidates.size();
        ret.clear();
        if(len == 0) ret;
        sort(candidates.begin(), candidates.end());
        count.resize(len);
        count.clear();
        helper(0, len, target, candidates);
        return ret;
    }
};
--------------end--------------

------------Combinations.cpp------------21
/*
第一种方法：用STL中的next_permutation函数
*/
class Solution {
public:
	vector<vector<int> > combine(int n, int k) {
		vector<int> v(n, 0);
		vector<vector<int> > v_res;
		fill_n(v.begin(), k, 1);
		do {
			vector<int> v_tmp;
			for(int i=0; i<n; i++) {
				if(v[i] == 1) {
					v_tmp.push_back(i+1);
				}
			}
			v_res.push_back(v_tmp);
		} while(prev_permutation(v.begin(), v.end())) ; //prev_permutation是原地操作
		return v_res;
	}
};

/*
第二种方法：
位运算，很tricky其实也快不了多少，没必要看了
*/
class Solution {
public:
	int next(int n, int com){
		int t = com&(-com);
		int b = t+com;
		int res = (((b^com)>>2)/t)|b;
		if(res >= (1<<n)) return 0;
		else return res;
	}
	vector<vector<int> > combine(int n, int k) {
		int com = (1<<k)-1;
		vector<vector<int> > v_res;
		while(com)
		{
			vector<int> v;
			for(int i=0; i<n; i++)
			{
				if(com&(0x1<<i)){
					v.push_back(i+1);
				}
			}
			v_res.push_back(v);
			com = next(n,com);
		}
		return v_res;
	}
};

/*
第三种方法：
递归，DFS，其实类似背包，有选和不选两个选择，
完成条件：选择了k个元素
终止条件：无
*/
class Solution {
public:
	vector<vector<int> > combine(int n, int k) {
		vector<vector<int> > result;
		vector<int> path;
		dfs(n, k, 1, 0, path, result);
		return result;
	}
private:
	// start，开始的数, cur，已经选择的数目
	static void dfs(int n, int k, int start, int cur, vector<int> &path, vector<vector<int> > &result) {
		if (cur == k) {	//任务完成
			result.push_back(path);
		}
		for (int i = start; i <= n; ++i) { //对剩下的所有元素进行选和不选的尝试
			path.push_back(i);
			dfs(n, k, i + 1, cur + 1, path, result);
			path.pop_back();
		}
	}
};
--------------end--------------

------------Construct Binary Tree from Inorder and Postorder Traversal.cpp------------22
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
--------------end--------------

------------Construct Binary Tree from Preorder and Inorder Traversal.cpp------------23
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
跟后序+中序构建二叉树是一样的
*/
class Solution {
public:
    TreeNode *buildTree(vector<int> &inorder, int h1, int t1, vector<int> &preorder, int h2, int t2) {
        if(h1>t1) return NULL;
        TreeNode *node = new TreeNode(preorder[h2]);
        int index, left_len;
        for( int i=h1; i<=t1; i++){
            if(inorder[i] == preorder[h2]){
                index = i;
            }
        }
        left_len = index-h1;
        node->left = buildTree(inorder, h1, index-1, preorder, h2+1, h2+left_len);
        node->right = buildTree(inorder, index+1, t1, preorder, h2+left_len+1, t2);
        return node;

    }
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        int size1 = inorder.size(), size2 = preorder.size();
        int size = size1;
        if(size1 == 0 || size1 != size2){
            return NULL;
        }
        return buildTree(inorder, 0, size-1, preorder, 0, size-1);

    }
};
--------------end--------------

------------Container With Most Water.cpp------------24
//开始板子处在两端，然后让短的往中间移动
//过程中算出最大的容积，直到两个板子碰头
class Solution {
public:
    int maxArea(vector<int> &height) {
        int len = height.size(), res = 0;
        int i = 0, j=len-1;
        while(i<j){
            res = max(res, min(height[i],height[j])*(j-i));
            height[i]>height[j]? j--:i++;
        }
        return res;
    }
};
--------------end--------------

------------Convert Sorted Array to Binary Search Tree.cpp------------25
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
    TreeNode *sortedArrayToBST(vector<int> &num, int l, int r){
        TreeNode *root;
        int mid = l+(r-l)/2;
        if(l>r) return NULL；
        root = new TreeNode(num[mid]);
        root->left = sortedArrayToBST(num, l, mid-1);
        root->right = sortedArrayToBST(num, mid+1, r);
        return root;
    }
    
    TreeNode *sortedArrayToBST(vector<int> &num) {
        return sortedArrayToBST(num, 0, num.size()-1);
    }
};

--------------end--------------

------------Convert Sorted List to Binary Search Tree.cpp------------26
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
把链表的节点放到vector中，然后对vector进行操作
每次把中间的点拿出来生成TreeNode，然后对两段链表进行递归
*/
class Solution {
private:
    vector<int> v;
public:
    TreeNode *helper(int left, int right){
        if(left>right){
            return NULL;
        }
        int middle = (left+right)>>1; //中间节点坐标
        TreeNode *node = new TreeNode(v[middle]); //用中间节点构造TreeNode
        node->left = helper(left,middle-1);
        node->right = helper(middle+1,right);
    }
    TreeNode *sortedListToBST(ListNode *head) {
        v.clear();
		//先把ListNode都放到vector中
        while(head){
            v.push_back(head->val);
            head = head->next;
        }
        int len = v.size();
        if(!len){
            return NULL;
        }
        return helper(0, len-1);
    }
};

--------------end--------------

------------Copy List with Random Pointer.cpp------------27
/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
/*
扫描两遍：
第一遍的时候，就简单得把新节点插入到相应的旧节点后面，
第二遍的时候，拷贝random指针
然后，把得到的链表分拆成新旧两个链表
*/
class Solution {
public:
	//分拆链表，下面还有另外一种写法
    RandomListNode* removeClone(RandomListNode* head) {
        RandomListNode* ptr1 = head, *ptr2 = head->next, *ptr;
        ptr = ptr2;
        while(ptr1) { 
            ptr1->next = ptr1->next->next;
            ptr1 = ptr1->next;
            if(ptr2->next) {
                ptr2->next = ptr2->next->next;
            }
            ptr2 = ptr2->next;
        }  
        return ptr; 
    }
	
    RandomListNode *copyRandomList(RandomListNode *head) {
        if(!head) return nullptr;
        RandomListNode *ptr1 = head, *ptr2, *ptr;
		//扫描第一遍，把新节点插入到相应的旧节点后面
        while(ptr1) {
            ptr2 = new RandomListNode(ptr1->label);
            ptr2->next = ptr1->next;  
            ptr1->next = ptr2; //拷贝节点插入到ptr1后面
            ptr1 = ptr2->next;
        }
        //扫描第二遍，拷贝random指针
        ptr1 = head;
        while(ptr1) {
            if(ptr1->random) {
                ptr1->next->random = ptr1->random->next;
            }
            ptr1 = ptr1->next->next;
        }
        //分拆两个链表
        return removeClone(head);
    }
};

	//分拆链表的第二种写法
    RandomListNode* removeClone(RandomListNode* head) {
        RandomListNode* ptr1 = head, *ptr2 = head->next, *ptr;
        ptr = ptr2;
        while(ptr2->next) { 
            ptr1->next = ptr1->next->next;
            ptr1 = ptr1->next;
            ptr2->next = ptr2->next->next;
            ptr2 = ptr2->next;
        }  
        ptr1->next = ptr2->next = NULL;
        return ptr; 
    }
--------------end--------------

------------Count and Say.cpp------------28
//模拟
/*
传入字符串，模拟数的动作，计算有几个连续的，记录下来，然后返回字符串
*/
class Solution {
public:
    string countAndSay(string str){
        string s = "";
        int count, len = str.length();
        count = 1;
        for(int i=0; i<=len-1; i++){
            if(i<len-1 && str[i] == str[i+1]){
                count++; //记录有几个连续的字符
            }
            else{
                s += (char)(count+48);
                s += str[i];
                count = 1;
            }
        }
        return s;
    }
    string countAndSay(int n) {
        string s_res = "1";
        for(int i=2; i<=n; i++){
            s_res = countAndSay(s_res);
        }
        return s_res;
    }
};
--------------end--------------

------------Decode Ways.cpp------------29
//跟Climbing Stairs很类似，不过多加一些判断逻辑
class Solution {
public:
    int numDecodings(string s) {
        int len = s.length();
        vector<int> v;
        v.resize(len+1);
        if(len == 0 || s[0] == '0'){
            return 0;
        }
        v[0] = v[1] = 1;
        for(int i=2; i<=len; i++){
            if(s[i-1] == '0') { //如果当前的字符是0，则必须是10或者20才有解
                if(s[i-2]-'0' <= 2 && s[i-2]-'0' > 0) {
                    v[i] = v[i-2]; //有解，但是只能是2个数一起解
                }
                else {
                    return 0; //否则无解
                }
            }
            else if(s[i-2] == '0') {
                v[i] = v[i-1]; //前面一个字符是0，则当前字符加在后面解法并不增加
            }
            else if(s[i-2]=='1' || (s[i-2] == '2' && s[i-1]-'0'<7)) {
                    v[i] = v[i-1]+v[i-2]; //只有这种情况解法等于前面两个的和：11-19，21-26
            }
            else if(s[i-2]-'0'>2 || (s[i-2] == '2' && s[i-1]-'0'>6)) {
                v[i] = v[i-1]; //大于26的情况
            }
        }
        return v[len];
    }
};
--------------end--------------

------------Distinct Subsequences.cpp------------30
/*
字符串处理题很多都可以使用动态规划。
设状态为f(i,j)，表示T[0,j]在S[0,i]里出现的次数。首先，无论S[i]和T[j]是
否相等，若不使用S[i]，则f(i,j) = f(i-1,j)；若S[i]==T[j]，则可以使用S[i]，此时
f(i,j) = f(i-1,j) + f(i-1,j-1)，f(i-1,j)代表不使用S[i]，f(i-1,j-1)代表使用S[i]
*/
class Solution {
public:
    int numDistinct(string S, string T) {
        int lenS = S.length();
        int lenT = T.length();
        if(lenS < lenT) return 0;
        vector<vector<int> > res(lenS, vector<int>(lenT, 0));
        if(S[0] == T[0]) res[0][0] = 1;
		//初始化第一列，第一行都是0不需要额外初始化
        for(int i=1; i<lenS; i++){
            if(S[i] == T[0]){
                res[i][0] = res[i-1][0] + 1;
            }
            else{
				res[i][0] = res[i-1][0];
			}
        }
        for(int i=1; i<lenS; i++){
            for(int j=1; j<lenT; j++){
				//根据状态转移方程...
                if(S[i] == T[j]){
                    res[i][j] = res[i-1][j] + res[i-1][j-1];
                }
                else{
                    res[i][j] = res[i-1][j];
                }
            }
        }
        return res[lenS-1][lenT-1];
    }
};

// 二维动规+ 滚动数组
// 时间复杂度O(m*n)，空间复杂度O(n)
class Solution {
public:
	int numDistinct(const string &S, const string &T) {
		vector<int> f(T.size() + 1);
		f[0] = 1;
		for (int i = 0; i < S.size(); ++i) {
			for (int j = T.size() - 1; j >= 0; --j) {
				f[j + 1] += S[i] == T[j] ? f[j] : 0;
			}
		}
		return f[T.size()];
	}
};
--------------end--------------

------------Divide Two Integers.cpp------------31
//很简单，像发TCP包那样，每次增大一倍
class Solution {
public:
    int divide(int dividend, int divisor) {
        int res = 0, multior = 0;
		//一定要先转成long long, 不然会被INT_MIN烦死
        long long a = abs((long long)dividend);
        long long b = abs((long long)divisor);
        while(a >= b){
            if(a >= (b<<multior)) {
                res += (1<<multior);
                a -= (b<<multior);
                ++multior;
            }
            else {
                multior = 0;
            }
        }
		//判断两个数符号是否相同，不相同则返回负数
        return ((dividend^divisor)>>31)? 0-res:res;
    }
};
--------------end--------------

------------Edit Distance.cpp------------32
/*
二维动态规划：
设状态为f[i][j]，表示A[0,i] 和B[0,j] 之间的最小编辑距离。
设A[0,i] 的形式是str1c，B[0,j] 的形式是str2d，
1. 如果c==d，则f[i][j]=f[i-1][j-1]；这种情况最简单
2. 如果c!=d，
(a) 如果将c 替换成d，则f[i][j]=f[i-1][j-1]+1； 这种情况第二简单
(b) 如果在c 后面添加一个d，则f[i][j]=f[i][j-1]+1；注意是在c后面添加d，不是前面
(c) 如果将c 删除，则f[i][j]=f[i-1][j]+1；
*/
class Solution {
public:
    #define min(a,b,c) min(a,min(b,c))
    int minDistance(string word1, string word2) {
        int len1 = word1.length(), len2 = word2.length();
        vector<vector<int> > matrix(len1+1, vector<int>(len2+1));
		//初始化，从word1的空串到word2的最小编辑距离
        for(int i=0; i<=len2; i++){
            matrix[0][i] = i;
        }
		//初始化，从word2的空串到word1的最小编辑距离
        for(int i=0; i<=len1; i++){
            matrix[i][0] = i;
        }
		//取4种情况的最小值
        for(int i=1; i<=len1; i++){
            for(int j=1; j<=len2; j++){
                int flag = (word1[i-1]==word2[j-1]?0:1);
                matrix[i][j] = min(matrix[i-1][j]+1,matrix[i][j-1]+1,
                                   matrix[i-1][j-1]+flag );
            }
        }
		//返回A[0,len1]到B[0,len2]的编辑距离
        return matrix[len1][len2];
    }
};
--------------end--------------

------------Evaluate Reverse Polish Notation.cpp------------33
/*
stoi可以把字符串转成数字，是c++的库函数
这题其实很简单，遇到数字就压栈，遇到操作符就出栈两个数进行运算，把结果压栈
*/
class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        stack<int> num;
        for(int i=0; i<tokens.size(); i++){
            if(tokens[i].size() > 1 || (tokens[i][0] >= '0' && tokens[i][0] <= '9')){
                num.push(stoi(tokens[i]));
            }
            else{
                int a, b;
                b = num.top(); num.pop();
                a = num.top(); num.pop();
                switch(tokens[i][0]){
                    case '+':
                    num.push(a+b);
                    break;
                    case '-':
                    num.push(a-b);
                    break;
                    case '*':
                    num.push(a*b);
                    break;
                    case '/':
                    num.push(a/b);
                    break;
                }
            }
        }
        return num.top();
    }
};
--------------end--------------

------------First Missing Positive.cpp------------34
/*
思路：
大于n或者小于0的不可能占据正数的位置，所以直接pass
如果遇到A[i] == i+1，说明这个数A[i]正好在它应该在的位置，pass
如果遇到A[i] == A[A[i]-1]，说明不需要交换，pass
如果不是上面的情况，则交换A[i] 和 A[A[i]-1]，就是把A[i]放到它应该在的位置
对所有数进行了以上操作之后，再从头遍历一遍，返回第一个放错数的位置
*/
class Solution {
public :
    int firstMissingPositive( int A[], int n) {
        int i = 0;
        while(i < n){
            if(A[i] == i+1 || A[i] <= 0 || A[i] > n || A[i] == A[A[i]-1]){
                i++;
            }
            else{  //swap two number without using extra space
                swap(A[i], A[A[i]-1]);
            }
        }
        for(i=0; i<n; i++){
            if(A[i] != i+1){
                return i+1;
            }
        }
        return n+1;
    }
};

--------------end--------------

------------Flatten Binary Tree to Linked List.cpp------------35
/*
理论上这个也不是原地算法，但是空间是O(log n)
比下面的算法好，help返回值是链表的最后一个节点
为什么？
*/
class Solution {
public:
    void flatten(TreeNode *root) {
        if(!root) return;
        else help(root);
    }
    
    TreeNode * help(TreeNode *cur) {
        if(!cur) return NULL;
        if(cur->right == NULL && cur->left == NULL) return cur;
        TreeNode *left = cur->left;
        TreeNode *right = cur->right;
        cur->left = NULL; //左指针一律置为null
        if(left) {
            cur->right = left; //右指针先指向左孩子
            cur = help(left);  //把左孩子捋顺，返回的是左孩子的最后一个节点
        }
        if(right) {
            cur->right = right;//右指针再指向右孩子
            cur = help(right); //再把右孩子捋顺，返回的是右孩子的最后一个节点
        }
        return cur;
    }
};


//下面这个不是原地算法，因为空间用了O(n+log(n))，
//原地算法是空间只用O(1)
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
private:
    vector<TreeNode *> v;
public:
    void helper(TreeNode *root){
        if(!root){
            return;
        }
        v.push_back(root);
        if(root->left){
            helper(root->left);
            root->left = NULL;
        }
        if(root->right){
            helper(root->right);
            root->right = NULL;
        }
    }
    void flatten(TreeNode *root) {
        if(!root) return;
        }
        v.clear();
        helper(root);
        int len = v.size();
        for(int i=1; i<len; i++){
            v[i-1]->right = v[i];
        }
    }
};
--------------end--------------

------------Gas Station.cpp------------36
/*
首先想到的是O(N2) 的解法，对每个点进行模拟。
O(N) 的解法是，设置两个变量，sum 判断当前起点的有效性；total 则判断整个数组是否有解，
有就返回通过sum 得到的下标，没有则返回-1。
*/
class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int len = gas.size(), total_gas=0, sum=0, index = -1;
        for(int i=0; i<len; i++){
            gas[i] -= cost[i];
            sum += gas[i];
            if(sum < 0) { //如果sum为0，说明当前起点无效
                sum = 0;
                index = i;
            }
            total_gas += gas[i]; //下面用来判断是否有解
        }
        return total_gas >= 0? index+1:-1;
    }
};
--------------end--------------

------------Generate Parentheses.cpp------------37
My solution:
//小括号串是一个递归结构，跟单链表、二叉树等递归结构一样，首先想到用递归。
//一步步构造字符串。当左括号出现次数< n 时，就可以放置新的左括号。当右括号出现次数小
//于左括号出现次数时，就可以放置新的右括号。
class Solution {
public:
    void gen(vector<string> &v, int left, int right, string tmp, int n){
        if(left < right || left > n) return;
        if(left == right && left == n) 
            v.push_back(tmp);
        gen(v, left+1, right, tmp+'(', n);
        gen(v, left, right+1, tmp+')', n);
    }
    vector<string> generateParenthesis(int n) {
        vector<string> v_ret;
        gen(v_ret, 0, 0, "", n);
        return v_ret;
    }
};

--------------end--------------

------------Gray Code.cpp------------38
//位运算法:
//记住即可
class Solution {
public:
    vector<int> grayCode(int n) {
        int range = 1 << n;
        vector<int> v;
        v.resize(range);
        for(int i=0; i<range; i++){
            v[i] = i ^ (i>>1);
        }
        return v;
    }
};
--------------end--------------

------------Implement strStr.cpp------------39
1. 暴力匹配法
关于那个等于号，考虑下从m-n到m-1正好长度是n
class Solution {
public:
    char *strStr(char *haystack, char *needle)  
    {  
        if(!haystack || !needle) return nullptr;
        int m = strlen(haystack);
        int n = strlen(needle);
        for(int i=0; i<=m-n; i++){ //用暴力法的话，注意这里的等于
            int j = 0;
            for(; j<n; j++){
                if(haystack[i+j] != needle[j]){
                    break;
                }
            }
            if(j == n) return haystack+i;
        }
        return nullptr;
    }  
};

2. KMP
class Solution {
public:
	char *strStr(const char *haystack, const char *needle) {
		int pos = kmp(haystack, needle);
		if (pos == -1) return nullptr;
		else return (char*)haystack + pos;
	}
private:
	/*
	* @brief 计算部分匹配表，即next 数组.
	**
	@param[in] pattern 模式串
	* @param[out] next next 数组
	* @return 无
	*/
	static void compute_prefix(const char *pattern, int next[]) {
		int i;
		int j = -1;
		const int m = strlen(pattern);
		next[0] = j;
		for (i = 1; i < m; i++) {
			while (j > -1 && pattern[j + 1] != pattern[i]) {
				//用前面匹配过的前缀试验
				j = next[j];
			}

			if (pattern[i] == pattern[j + 1]) j++;
			next[i] = j;
		}
	}
	/*
	* @brief KMP 算法.
	**
	@param[in] text 文本
	* @param[in] pattern 模式串
	* @return 成功则返回第一次匹配的位置，失败则返回-1
	*/
	static int kmp(const char *text, const char *pattern) {
		int i;
		int j = -1;
		const int n = strlen(text);
		const int m = strlen(pattern);
		if (n == 0 && m == 0) return 0; /* "","" */
		if (m == 0) return 0; /* "a","" */
		int *next = (int*)malloc(sizeof(int) * m);
		compute_prefix(pattern, next);
		for (i = 0; i < n; i++) {
			while (j > -1 && pattern[j + 1] != text[i]) {
				//如果不匹配 回退到前一个最大前缀
				j = next[j];
			}
			if (text[i] == pattern[j + 1]) j++;
			if (j == m - 1) {
				free(next);
				return i-j;
			}
		}
		free(next);
		return -1;
	}
};
--------------end--------------

------------Insert Interval.cpp------------40
/**
* Definition for an interval.
* struct Interval {
*     int start;
*     int end;
*     Interval() : start(0), end(0) {}
*     Interval(int s, int e) : start(s), end(e) {}
* };
*/
class Solution {
public :
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        vector<Interval> res; //开始是空的
        bool merged = false; //标示是否已经成功merge
        int size = intervals.size();
        for( int i=0; i<size; i++) {
			//newInterval.start在intervals[i].end之前，就代表需要merge了，
            if(!merged && newInterval.start <= intervals[i].end){
				//update新Interval的起点
                newInterval.start = newInterval.start < intervals[i].start? newInterval.start : intervals[i].start;
				//newInterval.end 在 intervals[i].start之后，则把新interval变大
                if(newInterval.end >= intervals[i].start) {
                    //update新Interval的终点
                    newInterval.end = newInterval.end > intervals[i].end? newInterval.end : intervals[i].end;
                    if(i == size-1) { //如果后面没有interval了
                        merged = true;
                        res.push_back(newInterval);
						break；
                    }
                    continue;
                }
                else { //如果newInterval.end 在 intervals[i].start之前，则插入newInterval，标记为已merge
                    merged = true; //marked as "have merged"
                    res.push_back(newInterval);
                }
            }
            res.push_back(intervals[i]); //对于没有merge的或者在新interval之前的老intervals，都push到res中
        }
        if(!merged) {
            res.push_back(newInterval);
        }
        return res;
    }
};

--------------end--------------

------------Insertion Sort List.cpp------------41
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *insertionSortList(ListNode *head) {
        ListNode *cur, *cur_left = head, *ptr_left, *ptr;
		bool flag;
        if(!head || !head->next){ //0个或1个节点的情况
            return head;
        }
        cur = cur_left->next;
        while(cur) {
			flag = true;
            if(cur->val < head->val) {
                cur_left->next = cur->next;
                cur->next = head;
                head = cur;
                cur = cur_left->next;
				continue;
            }
            ptr_left = head;
            ptr = ptr_left->next;
            while(cur && ptr != cur) {
                if(cur->val < ptr->val){
                    cur_left->next = cur->next;
                    cur->next = ptr;
                    ptr_left->next = cur;
                    cur = cur_left->next;
					flag = false;
					break;
                }
                ptr_left = ptr_left->next;
                ptr = ptr_left->next;
            }
			if(flag){
				cur_left = cur_left->next;
				if(cur_left){
					cur = cur_left->next;
				}
			}
        }
        return head;
    }
};
--------------end--------------

------------Integer to Roman.cpp------------42
My naive solution:
class Solution {
public:
    string intToRoman(int num) {
        // Note: The Solution object is instantiated only once and is reused by each test case.    
        int thousand, hundred, ten, unit;
        string res;
        thousand = num/1000;
        num %= 1000;
        hundred = num/100;
        num %= 100;
        ten = num/10;
        num %= 10;
        unit = num;
        for(int i=0; i<thousand; i++){
            res += "M";
        }
        if(hundred == 9){
            res += "CM";
        }
        else if(hundred >= 5){
            res += "D";
            hundred -= 5;
            for(int i=0; i<hundred; i++){
                res += "C";
            }
        }
        else if(hundred == 4){
            res += "CD";
        }
        else{
            for(int i=0; i<hundred; i++){
                res += "C";
            }
        }
        if(ten == 9){
            res += "XC";
        }
        else if(ten >= 5){
            res += "L";
            ten -= 5;
            for(int i=0; i<ten; i++){
                res += "X";
            }
        }
        else if(ten == 4){
            res += "XL";
        }
        else {
            for(int i=0; i<ten; i++){
                res += "X";
            }
        }
        if(unit == 9){
            res += "IX";
        }
        else if(unit >= 5){
            res += "V";
            unit -= 5;
            for(int i=0; i<unit; i++){
                res += "I";
            }
        }
        else if(unit == 4){
            res += "IV";
        }
        else{
            for(int i=0; i<unit; i++){
                res += "I";
            }
        }
        return res;
    }
};

Much better solution:
class Solution {
public:
    string intToRoman(int num) {
        const int radix[] = {1000, 900, 500, 400, 100, 90,
                             50, 40, 10, 9, 5, 4, 1};
        const string symbol[] = {"M", "CM", "D", "CD", "C", "XC",
                                 "L", "XL", "X", "IX", "V", "IV", "I"};
        string roman;
        for (size_t i = 0; num > 0; ++i) {
            int count = num / radix[i];
            num %= radix[i];
            for (; count > 0; --count) roman += symbol[i];
        }
        return roman;
    }
};
--------------end--------------

------------Interleaving String.cpp------------43
/*
这题有点像unique path II那题，可以用动态规划或者DFS来做
动态规划的方法状态转移方程为：
isReachable[i][j] = ( (isReachable[i-1][j] && s3[i+j-1]==s2[i-1]) ||
                      (isReachable[i][j-1] && s3[i+j-1]==s1[j-1]))
isReachable下标没减一，s1、s2、s3下标减一是因为isReachable下标是0 0的时候代表没走，
而字符串下标是从0开始算的
*/
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int len1 = s1.length(), len2 = s2.length(), len3 = s3.length();
        if(len1+len2 != len3){
            return false;
        }
        vector<vector<bool> > isReachable;
        vector<bool> v;
        v.resize(len1+1);
        for(int i=0; i<=len2; i++){
            isReachable.push_back(v);
        }
        isReachable[0][0] = true;
        for(int i=1; i<=len1; i++){
            isReachable[0][i] = (isReachable[0][i-1] && s3[i-1]==s1[i-1])? true:false;
        }
        for(int i=1; i<=len2; i++){
            isReachable[i][0] = (isReachable[i-1][0] && s3[i-1]==s2[i-1])? true:false;
        }
        for(int i=1; i<=len2; i++){             //line
            for(int j=1; j<=len1; j++){         //col
                isReachable[i][j] = ( (isReachable[i-1][j] && s3[i+j-1]==s2[i-1]) ||
                                    (isReachable[i][j-1] && s3[i+j-1]==s1[j-1]))? true:false;
            }
        }
        return isReachable[len2][len1];
    }
};
--------------end--------------

------------Jump Game II.cpp------------44
//贪心法，每次走能走的最远的一步
class Solution {
public:
    int jump(int A[], int n) {
        int longest, step = 1;
        int i = 0;
        if(n <= 1){
            return 0;
        }
        longest = A[0];
        while(longest < n-1 && i < n) {
            int l = longest;
            while(i <= l){
                if(i+A[i] > longest){
                    longest = i+A[i];
                }
                i++;
            }
            step++;
        }
        return step;
    }
};
--------------end--------------

------------Jump Game.cpp------------45
//贪心法
class Solution {
public:
    bool canJump(int A[], int n) {
        int longest;
        if(n == 0) return true;
        longest = A[0];
        for(int i=1; i<n; i++){
            if(i>longest) return false;
			//贪心法：当前最远能走多远
            if(A[i] + i > longest){
                longest = A[i]+i;
            }
        }
        return true;
    }
};
--------------end--------------

------------Largest Rectangle in Histogram.cpp------------46
/*
O(n^2)的解法：对每个柱子，左右扩展，直到碰到比自己矮的，
计算这个矩形的面积，用一个变量记录最大的面积，会超时。

通过记录高度的起始index，降低复杂度
Actually, we can decrease the complexity by 
using stack to keep track of the height and start indexes. 
Compare the current height with previous one.

Case 1: current > previous (top of height stack)
Push current height and index as candidate rectangle start position.

Case 2: current = previous
Ignore.

Case 3: current < previous
Need keep popping out previous heights, and compute the 
candidate rectangle with height and width
(current index - previous index). Push the height and index to stacks
*/
class Solution {
public :
    int largestRectangleArea( vector< int> & height) {
        int len = height.size();
        if (len == 0) return 0; 
     
        int maxArea = 0; 
        stack< int> stackHeight; 
        stack< int> stackIndex; 
         
        for ( int i = 0; i < len; i++) { 
            //case 1：把更高的height放到栈里，index也放到对应的栈里
            if (stackHeight.size() == 0 || height[i] > stackHeight.top()) { 
                stackHeight.push( height[i]); 
                stackIndex.push(i); 
            } else if ( height[i] < stackHeight.top()) { 
                // case 3：遇到低的height，开始计算之前的矩形
                int lastIndex = 0; 
                while (stackHeight.empty() == false && height[i] < stackHeight.top()) { 
                    lastIndex = stackIndex.top(); 
                    stackIndex.pop();
                    int tempArea = stackHeight.top() * (i - lastIndex); 
                    stackHeight.pop();
                    if (maxArea < tempArea) { 
                        maxArea = tempArea; 
                    } 
                } 
                stackHeight.push( height[i]); 
                stackIndex.push(lastIndex); 
            } 
        } 
         
        while(stackHeight.empty() == false) { 
            int tempArea = stackHeight.top() * (len - stackIndex.top()); 
            stackHeight.pop();
            stackIndex.pop();
            if (tempArea > maxArea) { 
                maxArea = tempArea; 
            } 
        } 
        return maxArea; 
    }
};
--------------end--------------

------------Length of Last Word.cpp------------47
My solution:
//从后往前读，先把后面的空格丢掉
class Solution {
public:
    int lengthOfLastWord(const char *s) {
        int len = strlen(s), len_last = 0;
        int cur = len-1;
        if(!len){
            return 0;
        }
        while(s[cur]==' ' && cur-->=0);
        while(s[cur]!=' ' && cur-->=0){
            len_last++;
        }
        return len_last;
    }
};

Other solution:
//从前往后读, 实现比较猥琐，s++还是不++，非常绕
class Solution {
public:
	int lengthOfLastWord(const char *s) {
		int len = 0;
		while (*s) {
			if (*s++ != ' ') //如果没遇到空格len就++
				++len;
			else if (*s && *s != ' ')//如果遇到空格，再次遇到不是空格的len清零
				len = 0;
		}
		return len; 
	}
};

//用STL
class Solution {
public:
	int lengthOfLastWord(const char *s) {
		const string str(s);
		//从后往前找第一个字母
		auto first = find_if(str.rbegin(), str.rend(), ::isalpha);
		//从最后一个字母往前找第一个非字母
		auto last = find_if_not(first, str.rend(), ::isalpha);
		//计算两者差距
		return distance(first, last);
	}
};
--------------end--------------

------------Letter Combinations of a Phone Number.cpp------------48
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        string d[8] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"}, str;
        int len[8] = {3,3,3,3,3,4,3,4}, len_i = digits.length();
        vector<string> vs;
        vs.clear();
        if(len_i == 0){
            vs.push_back("");
            return vs;
        }
		//先把第一个数字键上的字母push入队列
        for(int i=0; i<len[digits[0]-'2']; i++){
			str = "";
            str += d[digits[0]-'2'][i];
            vs.push_back(str);
        }
		/*
		对每个vector中的元素，往其后追加下个数字键上的每个字母，
		并push入vector，然后把老的元素全部清空
		*/
        for(int i=1; i<len_i; i++){
            int size = vs.size();
            for(int j=0; j<size; j++){
                for(int k=0; k<len[digits[i]-'2']; k++){
                    str = vs[j]+d[digits[i]-'2'][k];
                    vs.push_back(str);
                }
            }
            vs.erase(vs.begin(), vs.begin()+size);
        }
        return vs;
    }
};

//换种写法，看是不是更好懂些
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        string d[8] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"}, str;
        int len[8] = {3,3,3,3,3,4,3,4}, len_i = digits.length();
        vector<string> vs1, vs2;
        vs1.clear(); 
        vs2.clear();
        if(len_i == 0){
            vs1.push_back("");
            return vs1;
        }
		//先把第一个数字键上的字母push入队列
        for(int i=0; i<len[digits[0]-'2']; i++){
			str = "";
            str += d[digits[0]-'2'][i];
            vs1.push_back(str);
        }
		/*
		对每个vector中的元素，往其后追加下个数字键上的每个字母，
		并push入vector，然后把老的元素全部清空
		*/
        for(int i=1; i<len_i; i++){
            int size = vs1.size();
            for(int j=0; j<size; j++){
                for(int k=0; k<len[digits[i]-'2']; k++){
                    str = vs1[j]+d[digits[i]-'2'][k];
                    vs2.push_back(str);
                }
            }
            swap(vs1, vs2); //或 vs1 = vs2;
            vs2.clear();
        }
        return vs1;
    }
};
--------------end--------------

------------Linked List Cycle II.cpp------------49
My solution:
//快慢指针+（起点到环入口的距离等于环入口到快慢指针相遇点的距离）
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        ListNode *fast, *slow;
        slow = fast = head;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
            if(fast == slow){
                slow = head;
                while(1){
                    if(slow == fast){
                        return slow;
                    }
                    slow = slow->next;
                    fast = fast->next;
                }
            }
        }
        return NULL;
    }
};
--------------end--------------

------------Linked List Cycle.cpp------------50
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 //蹇參鎸囬拡
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *fast, *slow;
        fast = slow = head;
        while(fast!=nullptr && fast->next!=nullptr){
            fast = fast->next->next;
            slow = slow->next;
            if(fast == slow) return true;
        }
        return false;
    }
};

--------------end--------------

------------Longest Common Prefix.cpp------------51
//从位置0 开始，对每一个位置比较所有字符串（跟第一个字符串比），直到遇到一个不匹配。
class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        string str=""; //存公共前缀
        bool flag = true;
		if(strs.empty()) return str;
        for(int i=0; i<strs[0].length(); i++){
            for(int j=1; j<strs.size(); j++){
                //每个都跟第一个字符串比较
                if(strs[j].length() < i || strs[j][i] != strs[0][i]){
                    flag = false;
                    break;
                }
            }
            if(flag) str += strs[0][i];
            else break;
        }
        return str;
    }
};
--------------end--------------

------------Longest Consecutive Sequence.cpp------------52
/*
用count函数来判定关键字是否出现，其缺点是无法定位数据出现位置,，
由于map的特性一对一的映射关系，就决定了count函数的返回值只有两个，
要么是0，要么是1，出现的情况，当然是返回1了
unordered_map不允许有重复元素，但是输入的vector却可能有，因此在
初始化的时候，需要先判断num[i]是否出现过
*/
class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        unordered_map<int, int> map;
        int len = num.size();
		//因为vector可能有重复元素，而unordered_map不能有
        for(int i=0; i<len; i++){
            if(map.count(num[i])){
                map[num[i]]++;
            }
            else{
                map[num[i]] = 1;
            }
        }
        int max_len = 0;
        for(int i=0; i<len; i++){
            int element1 = num[i]+1, element2 = num[i]-1;
            int count_biger = 0;//记录向右延伸的结果
            int count_smaller = 0;//记录向左延伸的结果
			//向右边延伸
            while(map.count(element1)){
                count_biger++;
                map.erase(element1++); //要从map中去掉
            }
			//向左边延伸
            while(map.count(element2)){
                count_smaller++;
                map.erase(element2--); //要从map中去掉
            }
            map.erase(num[i]);
            max_len = max(max_len, count_biger + count_smaller + 1);
        }
        return max_len;
    }
};

/*
如果允许O(n log n) 的复杂度，那么可以先排序，可是本题要求O(n)。
由于序列里的元素是无序的，又要求O(n)，首先要想到用哈希表。
用一个哈希表unordered_map<int, bool> used 记录每个元素是否使用，对每个元素，以该
元素为中心，往左右扩张，直到不连续为止，记录下最长的长度。
*/
class Solution {
public:
	int longestConsecutive(vector<int> const& num) {
		unordered_map<int, bool> used;
		for (auto i : num) used[i] = false;
		int longest = 0;
		for (auto i : num) {
			if (used[i]) continue; //如果访问过了就continue
			int length = 1;
			used[i] = true;
			//对unordered_map调用find可以不增加成员！！！
			for (int j = i + 1; used.find(j) != used.end(); ++j) {
				used[j] = true;
				++length;
			}
			for (int j = i - 1; used.find(j) != used.end(); --j) {
				used[j] = true;
				++length;
			}
			longest = max(longest, length);
		}
		return longest;
	}
};
--------------end--------------

------------Longest Palindromic Substring.cpp------------53
//思路就是，以每个字符为中点向两边延伸（只要满足回文）
//能延展的最长的保留下来输出，要考虑奇数回文和偶数回文的情况
class Solution {
public:
    string palindrome(string s, int i, int j, int len){
        string str;
        int start, end;
        start = i;
        end = j;
        while(start >= 0 && end < len){
            if(s[start] != s[end]){
                break;
            }
			start--; end++;
        }
        start++;
        end--;
        return s.substr(start, end-start+1);
    }
    
    string longestPalindrome(string s) {
        int len = s.length();
        string longestString = "";
        for(int i=0; i<len; i++){
            string str1 = palindrome(s, i, i, len); //奇数回文
            if(str1.length() > longestString.length()){
                longestString = str1;
            }
            if(i+1 < len && s[i] == s[i+1]){
                string str2 = palindrome(s, i, i+1, len);//偶数回文
                if(str2.length() > longestString.length()){
                    longestString = str2;
                }
            }
        }
        return longestString;
    }
};
--------------end--------------

------------Longest Substring Without Repeating Characters.cpp------------54
//假设子串里含有重复字符，则父串一定含有重复字符，单个子问题就可以决定父问题，因此可
//以用贪心法。跟动规不同，动规里，单个子问题只能影响父问题，不足以决定父问题。
//从左往右扫描，当遇到重复字母时，以上一个重复字母的index+1，作为新的搜索起始位置，
//直到最后一个字母，复杂度是O(n)。
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        bool flag[32];
        int head=0, tail=head, len = s.length(), max = 1;
        if(!len){
            return 0;
        }
        for(int i=0; i<32; i++){
            flag[i] = false;
        }
        flag[s[head]-'a'] = true;
        while(tail < len-1){
            while(flag[s[tail+1]-'a']){ //existed
                flag[s[head++]-'a'] = false;
            }
            flag[s[++tail]-'a'] = true;
            if(tail-head+1>max){
                max = tail-head+1;
            }
        }
        return max;
    }
};
--------------end--------------

------------Longest Valid Parentheses.cpp------------55
/*
last_valid是这里的关键，理解了这个变量设置的意义，
这个题就懂了
*/
class Solution {
public:
    int longestValidParentheses(string s) {
        int len = s.length(), last_valid = -1, max_len = 0;
        stack<int> left; //只用来保存'('
        for(int i=0; i<len; i++){
            if(s[i] == '(') { 
                left.push(i);
            }
            else {  //如果是')',则看栈里面有没有对应的'('
                if(left.empty()) {
                    last_valid = i;
                }
                else {
                    left.pop(); //用掉一个'('
                    if(left.empty()) { //如果栈为空,说明能一直匹配到上个匹配不了的')'
                        max_len = max(max_len, i - last_valid);
                    }
                    else { //否则,只能用上个'('的位置算
                        max_len = max(max_len, i - left.top());
                    }
                }
            }
        }
        return max_len;
    }
};
--------------end--------------

------------LRU Cache.cpp------------56
/*
这一题主要考察对数据结构特性的了解
get函数显然应该以O(1)的复杂度实现，那么只能用unordered_map
而且 这里map里面存的是list的迭代器！！！
get函数要做的事情是：在map里查找key，如果找不到就返回-1；
如果找到了，就把当前访问的节点放到list最前面，返回当前值
set函数需要经常删除、插入，所以需要一个链表，在stl中当然是list了
set函数要做的事情是：
*/
struct CacheNode{
    int key;
    int value;
    CacheNode(int k, int v): key(k), value(v) {}
};

class LRUCache{
    
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if(cacheMap.find(key) == cacheMap.end()){ //cacheMap[key] == 0
            return -1;
        }
		//假如在map中找到了key: 1.把节点放到链表头, 2.更新map中的记录, 3.返回value
        else { 
			//把cacheList的cacheMap[key]位置的点插入到cacheList.begin()
            cacheList.splice(cacheList.begin(), cacheList, cacheMap[key]); 
            cacheMap[key] = cacheList.begin();//更新map中的记录
            return cacheList.front().value; //返回value
        }
    }
    
    void set(int key, int value) {
		//没有找到节点: 1.插入节点并更新list和map, 2.要检查是否已满
        if(cacheMap.find(key) == cacheMap.end()) {    
            if(cacheList.size() == capacity){ //已满, 删除末尾的节点
                cacheMap.erase(cacheList.back().key); //map要先调整
                cacheList.pop_back();   
            }
            //新节点插到头部, 调整map
            cacheList.push_front(CacheNode(key, value));
            cacheMap[key] = cacheList.begin(); //更新节点位置
        }
        else{   //找到节点的话, 只需要把节点调整到头部, 更新map
            cacheList.splice(cacheList.begin(), cacheList, cacheMap[key]);
            cacheMap[key] = cacheList.begin(); //更新map
            cacheMap[key]->value = value;   //更新value
        }
    }
private:
    int capacity;
    list<CacheNode> cacheList;
    unordered_map<int, list<CacheNode>::iterator> cacheMap;  //map里面存的是<key, 节点位置(迭代器)>
};
--------------end--------------

------------Max Points on a Line.cpp------------57
/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
/*
思路：
以每个点为中心，计算其他点与之连线的斜率，斜率相同的就在一条线上
注意重合点的处理，数据结构使用unordered_map便于查找，以每个点为中心
算出来之后都要查找所有其他点到它的斜率，查找频繁！
只需要算当前点之后的点与之的连线斜率，之前的点不需要算
*/
class Solution {
public:
    int maxPoints(vector<Point> &points) {
        int size = points.size();
        unordered_map<float, int> mp; //斜率 点数
        int max_point = 0;
        for(int i=0; i<size; i++) {
            int duplicate = 1;
            mp.clear();
            mp[INT_MIN] = 0;
            for(int j = i+1; j<size; j++) {
                float k;
                //计算重合点数(有可能有重)
                if(points[i].x == points[j].x && points[i].y == points[j].y) {
                    duplicate++;
                    continue; //重合点不必算斜率
                }
                //计算斜率
                if(points[i].x == points[j].x) {
                    k = INT_MAX; //y坐标不同，x坐标相同，斜率无穷大
                }
                else {
                    k = (float)(points[j].y - points[i].y)/(points[j].x - points[i].x);
                }
                mp[k]++; //统计相同斜率的点
            }
            unordered_map<float, int>::iterator it;
            for(it = mp.begin(); it != mp.end(); it++) {
                max_point = max(it->second + duplicate, max_point);
            }
        }
        return max_point;
    }
};
--------------end--------------

------------Maximal Rectangle.cpp------------58
/*
用一个二维数组记录每行到当前点连续1的个数，
然后以每个点为矩阵右下角去计算面积
*/
class Solution {
public:
    int maximalRectangle(vector<vector<char> > &matrix) {
        if(matrix.empty()) return 0;
        int n = matrix.size();
        int m = matrix[0].size();
        int one2now = 0, max_area = 0;
        vector<vector<int> > oneinline(n, vector<int>(m));
        
        for(int i=0; i<n; i++){
            one2now = 0;
            for(int j=0; j<m; j++){
                if(matrix[i][j] == '1'){
                    ++one2now;
                }
                else{
                    one2now = 0;
                }
                oneinline[i][j] = one2now;
            }
        }
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                int width = oneinline[i][j];
                if(!width){
                    continue;
                }
                //从当前行往上推,一层层算出最大面积
                for(int k=i; k>=0; k--){
                    width = min(oneinline[k][j], width); //如果当前行的width小则更新width
                    if(!width) break; //width为0,则矩阵中断
                    max_area = max(max_area, width*(i-k+1));
                }
            }
        }
        return max_area;
    }
};
--------------end--------------

------------Maximum Depth of Binary Tree.cpp------------59
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
class Solution {
public :
   int maxDepth(TreeNode * root) {
       // Note: The Solution object is instantiated only once and is reused by each test case.
       int length, length_left, length_right;
       if( root){                     //whether root is NoNULL
           length = 1;
       }
       else{
           return 0;
       }
       length_left = maxDepth( root->left);   //recursion to left tree
       length_right = maxDepth( root->right); //recursion to right tree
       length += length_right>length_left?length_right:length_left; //add the larger to length
       return length;
   }
};

Second Try:
class Solution {
public :
   int maxDepth(TreeNode * root) {
       if(root == nullptr) return 0;
       return max(maxDepth(root->left), maxDepth(root->right)) + 1;
   }
};
--------------end--------------

------------Maximum Subarray.cpp------------60
//记录下当前sum，小于0，则对后面无贡献，归零
class Solution {
public:
    int maxSubArray(int A[], int n) {
        int sum = 0, m;
        if(n == 0) return 0;
        m = A[0];
        for(int i=0; i<n; i++) {
            sum = max(sum, 0);
            sum += A[i];
            m = max(sum, m);
        }
        return m;
    }
};
--------------end--------------

------------Median of Two Sorted Arrays.cpp------------61
/*
这是一道非常经典的题。这题更通用的形式是，给定两个已经排序好的数组，找到两者所有元
素中第k 大的元素。
O(m + n) 的解法比较直观，直接merge 两个数组，然后求第k 大的元素。
不过我们仅仅需要第k 大的元素，是不需要“排序”这么复杂的操作的。可以用一个计数器，
记录当前已经找到第m 大的元素了。同时我们使用两个指针pA 和pB，分别指向A 和B 数组的第
一个元素，使用类似于merge sort 的原理，如果数组A 当前元素小，那么pA++，同时m++；如果
数组B 当前元素小，那么pB++，同时m++。最终当m 等于k 的时候，就得到了我们的答案，O(k)
时间，O(1) 空间。但是，当k 很接近m + n 的时候，这个方法还是O(m + n) 的。
有没有更好的方案呢？我们可以考虑从k 入手。如果我们每次都能够删除一个一定在第k 大元
素之前的元素，那么我们需要进行k 次。但是如果每次我们都删除一半呢？由于A 和B 都是有序
的，我们应该充分利用这里面的信息，类似于二分查找，也是充分利用了“有序”。
假设A 和B 的元素个数都大于k/2，我们将A 的第k/2 个元素（即A[k/2-1]）和B 的第k/2
个元素（即B[k/2-1]）进行比较，有以下三种情况（为了简化这里先假设k 为偶数，所得到的结
论对于k 是奇数也是成立的）：
• A[k/2-1] == B[k/2-1]
• A[k/2-1] > B[k/2-1]
• A[k/2-1] < B[k/2-1]
如果A[k/2-1] < B[k/2-1]，意味着A[0] 到A[k/2-1 的肯定在A [ B 的top k 元素的范围
内，换句话说，A[k/2-1 不可能大于A [ B 的第k 大元素。留给读者证明。
因此，我们可以放心的删除A 数组的这k/2 个元素。同理，当A[k/2-1] > B[k/2-1] 时，可
以删除B 数组的k/2 个元素。
当A[k/2-1] == B[k/2-1] 时，说明找到了第k 大的元素，直接返回A[k/2-1] 或B[k/2-1]
即可。
因此，我们可以写一个递归函数。那么函数什么时候应该终止呢？
• 当A 或B 是空时，直接返回B[k-1] 或A[k-1]；
• 当k=1 是，返回min(A[0], B[0])；
• 当A[k/2-1] == B[k/2-1] 时，返回A[k/2-1] 或B[k/2-1]
*/
class Solution {
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        int total = m + n;
        if(total & 0x1) { //奇数个元素,取中间元素
            return find_kth(A, m, B, n, total/2 + 1);
        }
        else { //偶数个元素,取中间两个元素的平均
            return (find_kth(A, m, B, n, total/2) + find_kth(A, m, B, n, total/2 + 1))/2;
        }
    }
private:
    double find_kth(int A[], int m, int B[], int n, int k) {
        if(m > n) return find_kth(B, n, A, m, k); //假定m小于等于n,这样处理更方便
		//按照前面的分析，下面是两个终止的情况
        if(m == 0) return B[k-1];
        if(k == 1) return min(A[0], B[0]);
        //pa取k/2，如果m比k/2小，pa取m
        int pa = min(k/2, m), pb = k - pa; //二分法的变形
        if(A[pa-1] < B[pb-1]) { 
			//这种情况可以放心去掉A的pa个元素（k/2或者全部）
            return find_kth(A+pa, m-pa, B, n, k-pa);
        }
        else if(A[pa-1] > B[pb-1]) { 
			//这种情况可以放心去掉B的pb个元素（k/2或者更多）
            return find_kth(A, m, B+pb, n-pb, k-pb);
        }
        else {
            return A[pa-1];
        }
    }
}; 
--------------end--------------

------------Merge Intervals.cpp------------62
/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
/*
先对interval排序（利用sort，需提供一个compare函数），然后不断逐个插入
*/
class Solution {
public:
    static bool compare1 (const Interval &a, const Interval &b){
        return a.start < b.start;
    }
    vector<Interval> merge(vector<Interval> &intervals) {
        int size = intervals.size();
        vector<Interval> res;
        //res.clear();
        if(size == 0) {
            return res;
        }
		//对interval排序
        sort(intervals.begin(), intervals.end(), compare1);
        res.push_back(intervals[0]);
        for(int i=1; i<size; i++) {
            int temp_size = res.size() - 1;
            if(res[temp_size].end >= intervals[i].start) { //如果有重叠
				//合并interval
                res[temp_size].end = max(res[temp_size].end:intervals[i].end);
            }
            else{ //如果没有重叠，加入一个新的interval
                res.push_back(intervals[i]);
            }
        }
        return res;
    }
};
--------------end--------------

------------Merge k Sorted Lists.cpp------------63
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

/*
merge k 列其实就是不断的merge两列，
merge两列，用了点技巧，不需要判断队列NULL了
*/
class Solution {
public:
    ListNode *merge2Lists(ListNode *list1, ListNode *list2){
        ListNode head(-1), *curList = &head;
        while(list1 != NULL || list2 != NULL){
            int value1 = (list1 == NULL? INT_MAX:list1->val);
			int value2 = (list2 == NULL? INT_MAX:list2->val);
            if(value1 < value2){
                curList->next = list1;
                list1 = list1->next;
				curList = curList->next;
            }
            else{
                curList->next = list2;
                list2 = list2->next;
				curList = curList->next;
            }
        }
        return head.next;
    }
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        int len = lists.size();
        if(!len) return NULL;
        for(int i=1; i<len; i++){
            lists[i] = merge2Lists(lists[i-1], lists[i]);
        }
        return lists[len-1];
    }
};
--------------end--------------

------------Merge Sorted Array.cpp------------64
First Try:
//from back to front
class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        int length = m+n;
        int i, j, k, t;
        for(i=length-1, j=m-1, k=n-1; i>=0; i--){
            if(j < 0){
                for(t=k; t>=0; t--){
                    A[i--] = B[t];
                }
                return;  
            } 
            if(k < 0){
                for(t=j; t>=0; t--){
                    A[i--] = A[t];
                }
                return;
            }
            if(A[j] > B[k]){
                A[i] = A[j--];
            }
            else{
                A[i] = B[k--];
            }
        }
    }
};

Second Try:
class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        int length = m+n;
        int i, j, k, t;
        for(i=length-1, j=m-1, k=n-1; i>=0; i--){
            if(k<0) break;
            if(j >= 0 && A[j] > B[k]){
                A[i] = A[j--];
            }
            else{
                A[i] = B[k--];
            }
        }
    }
};

Better Solution:
class Solution {
public:
	void merge(int A[], int m, int B[], int n) {
		int ia = m - 1, ib = n - 1, icur = m + n - 1;
		while(ia >= 0 && ib >= 0) {
			A[icur--] = A[ia] >= B[ib] ? A[ia--] : B[ib--];
		}
		while(ib >= 0) {
			A[icur--] = B[ib--];
		}
	}
};
--------------end--------------

------------Merge Two Sorted Lists.cpp------------65
First Try:
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        ListNode *cur, *head;
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;
        if(l1->val > l2->val){
            head = l2;
            l2 = l2->next;
        }
        else{
            head = l1;
            l1 = l1->next;
        }
        cur = head;
        while(l1 != NULL && l2 != NULL){
            if(l1->val > l2->val){
                cur->next = l2;
                l2 = l2->next;
            }
            else{
                cur->next = l1;
                l1 = l1->next;
            }
            cur = cur -> next;
        }
        if(l1) cur->next = l1;
        if(l2) cur->next = l2;
        return head;
    }
};

Second Try:
思路一样就是写得好一点,不过其实效率略低
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode head(-1);
        for (ListNode* p = &head; l1 != nullptr || l2 != nullptr; p = p->next) {
            int val1 = l1 == nullptr ? INT_MAX : l1->val;
            int val2 = l2 == nullptr ? INT_MAX : l2->val;
            if (val1 <= val2) {
                p->next = l1;
                l1 = l1->next;
            } else {
                p->next = l2;
                l2 = l2->next;
            }
        }
        return head.next;
    }
};
--------------end--------------

------------Minimum Depth of Binary Tree.cpp------------66
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
--------------end--------------

------------Minimum Path Sum.cpp------------67
My solution:
//二维动态规划,直接在grid上做了,缺点是grid被修改了
class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int height = grid.size();
        if(height == 0) return 0;
        int width = grid[0].size();
        //first line
        for(int j=1; j<width; j++){
            grid[0][j] = grid[0][j-1] + grid[0][j];
        }
        //first column
        for(int i=1; i<height; i++){
            grid[i][0] = grid[i-1][0] + grid[i][0];
        }
        for(int i=1; i<height; i++){
            for(int j=1; j<width; j++){
                grid[i][j] = grid[i][j] + (grid[i-1][j]<grid[i][j-1]?grid[i-1][j]:grid[i][j-1]);
            }
        }
        return grid[height-1][width-1];
    }
};

//动态规划+滚动数组,不修改grid
//巧妙之处是这里不需要计算第一行和第一列的值
class Solution {
public:
	int minPathSum(vector<vector<int> > &grid) {
		const int m = grid.size();
		const int n = grid[0].size();
		int f[n];
		fill(f, f+n, INT_MAX); // 初始值是INT_MAX，因为后面用了min 函数。
		f[0] = 0;
		for (int i = 0; i < m; i++) {
			f[0] += grid[i][0];
			for (int j = 1; j < n; j++) {
				// 左边的f[j]，表示更新后的f[j]，与公式中的f[i][j] 对应
				// 右边的f[j]，表示老的f[j]，与公式中的f[i-1][j] 对应
				f[j] = min(f[j - 1], f[j]) + grid[i][j];
			}
		}
		return f[n - 1];
	}
};
--------------end--------------

------------Minimum Window Substring.cpp------------68
//这题展示了怎么样即简单又易懂的写出一个好的算法来，
//把独立的功能用函数封装出去，这样问题规模就会缩小
class Solution {
public:
	//判断S是否能包住T，即T中的字符个数要小于S中对应的字符个数
	bool valid(int num1[], int num2[]){
        for(int i=0; i<256; i++){
            if(num1[i]<num2[i]){
                return false;
            }
        }
		return true;
    }
    string minWindow(string S, string T) {
        int s_num[256], t_num[256], c_num[256];
        int lenS = S.length(), lenT = T.length();
        int head = 0, tail = 0, minLen = lenS, head_min=0;
		memset(s_num,0,sizeof(s_num));
		memset(t_num,0,sizeof(s_num));
		memset(c_num,0,sizeof(s_num));
        if(lenS<lenT) return "";
		//统计S中各字符的个数
        for(int i=0; i<lenS; i++){
            s_num[S[i]]++;
        }
		//统计T中各字符的个数
        for(int i=0; i<lenT; i++) {
            t_num[T[i]]++;
        }
        if(!valid(s_num, t_num)){
            return "";
        }
        c_num[S[0]]++;
        while(tail<lenS){
            //如果不能包住,tail右移
            if(!valid(c_num, t_num)) {
                c_num[S[++tail]]++;
            }
            //如果全包住,head右移
            else{
                if(tail-head+1 < minLen) { //刷新最小window长度
                    minLen = tail-head+1;
                    head_min = head;
                }
                c_num[S[head++]]--;
            }
        }
        return S.substr(head_min, minLen); //返回最小window
    }
};
--------------end--------------

------------Multiply Strings.cpp------------69
/*
采用字符串操作：
string multiply(string num1, string num2) 完成两个字符串相乘，调用如下两个函数：
string multiply(string num, char c) 和 string add(string num1, string num2)
分别完成一个字符串和一个char相乘 以及 两个字符串相加，
这些都是基本的。
*/
class Solution {
public:
	//模拟加法操作，一位一位加，最后不要忘了判断进位
    string add(string num1, string num2) {
        int len_a = num1.length(), temp;
        int len_b = num2.length();
        int carry = 0;
        string res = "";
        if(len_a < len_b) { //保证第一个字符串更长
            return add(num2, num1);
        }
        for(int i=0; i<len_b; i++) { 
            temp = (num1[i]-'0')+(num2[i]-'0')+carry;
            carry = temp/10;
            temp%=10;
            res += (temp+'0');
        }
        for(int i=len_b; i<len_a; i++) {
            temp = (num1[i]-'0')+carry;
            carry = temp/10;
            temp%=10;
            res += (temp+'0');
        }
        if(carry){
            res += (carry+ '0');
        }
        return res;
    }
    
	//比上面的加法更简单
    string multiply(string num, char c) {
        int len = num.length(), carry = 0, temp;
        string res = "";
        for(int i=0; i<len; i++){
            temp = (num[i]-'0')*(c-'0')+carry;
            carry = temp/10;
            temp%=10;
            res += (temp+'0');
        }
        if(carry){
            res += (carry+'0');
        }
        return res;
    }
    //通过调用上面两个函数实现
    string multiply(string num1, string num2) {
        int len_a = num1.length(), temp;
        int len_b = num2.length();
        int carry = 0;
        string c = "", num = "0";
        if(len_a<len_b){
            return multiply(num2, num1);
        }
		//把数的顺序反过来，便于操作
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        for(int i=0; i<len_b; i++){
            if(num2[i] != '0'){
                c = multiply(num1, num2[i]);
            
                for(int j=0; j<i; j++){
                    c = c.insert(0, "0");
                }
                num = add(num, c);
            }
        }
        reverse(num.begin(), num.end());
        return num;
    }
};
--------------end--------------

------------N-Queens II.cpp------------70
//省空间了，只用一个长度为n的数组记录每行选的列号，当然用vector也可以
//感觉N-Queens也可以这样做，省空间，而且速度可能更快

class Solution {
public:
	//参数：当前行row，记录每行放置列号的数组colArray
    bool check(int row, int* colArray) {  
		//遍历之前行的放置情况，检查当前
        for (int i = 0; i < row; ++i) {  
            int diff = abs(colArray[i] - colArray[row]); //diff记录列号差
            if (diff == 0 || diff == row - i) {          // int a row or line  
                return false;  
            }  
        }  
        return true;  
    }  
  
    void placeQueens(int row, int n, int &count, int* colArray) {  
        if (row == n) {  
            ++count;  
            return;  
        }  
          
        for (int col = 0; col < n; ++col) {  
            colArray[row] = col;  //尝试每列
            if (check(row, colArray)){ //如果合法则往下递归
                placeQueens(row+1, n, count, colArray);  
            }  
        }  
    }  
      
    int totalNQueens(int n) {  
        int *colArray = new int[n];  
        int count = 0;            
        placeQueens(0, n, count, colArray);            
        return count;  
    } 
};
--------------end--------------

------------N-Queens.cpp------------71
//方法一：
//用二维vector记录棋盘放置情况
class Solution {
private:
    vector<vector<string> > ret;
public:
    bool valid(vector<vector<int> > &maxtrix, int row, int col, int n){
        int i, j;
		//检查有没有同列的（只要检查之前行即可）
        for(i=0; i<row; i++)
            if(maxtrix[i][col])
                return false;
        //检查左上对角
        i = row; j = col;
        while(i && j){
            if(maxtrix[--i][--j])
                return false;
		//检查右上角
        i = row; j = col;
        while(i && j<n-1){
            if(maxtrix[--i][++j]){
                return false;
        return true;
    }

	//深度优先，逐行逐列试探，行是递归往下，列是循环试探
	//参数：棋盘大小n，记录当前放置信息的matrix，当前操作的行row
    void solveNQueens(int n, vector<vector<int> > &matrix, int row) {
        vector<string> v(n);
        string str;
		//DFS的终止条件
        if(line == n){ //如果已经成功，就把1和0翻译成Q和.
            for(int i=0; i<n; i++){
                str = "";
                for(int j=0; j<n; j++){
					str += (matrix[i][j] == 1? 'Q':'.');
                }
                v[i] = str;
            }
            ret.push_back(v);
			return;
        }
		//DFS核心，对当前行的每一列进行试探，如果合法，则往下一行递归
        for(int j=0; j<n; j++){
            matrix[row].clear();
            if(valid(matrix, row, j, n)){ //如果当前列合法
                matrix[line][j] = 1; //当前行、列置为1
                solveNQueens(n, matrix, row+1); //递归下一层
                matrix[row][j] = 0;  //清除当前行、列
            }
        }
    }

    vector<vector<string> > solveNQueens(int n) {
        vector<vector<int> > matrix(n, vector<int>(n));
        ret.clear();
        solveNQueens(n, matrix, 0);
        return ret;
    }
};

//方法二：
//用一维vector记录棋盘放置情况
class Solution {
private:
	vector<vector<string> > ret;
public:
	//参数：当前行row，记录每行放置列号的数组colArray
    bool check(int row, vector<int> &colArray) {  
		//遍历之前行的放置情况，检查当前
        for (int i = 0; i < row; ++i) {  
            int diff = abs(colArray[i] - colArray[row]); //diff记录列号差
            if (diff == 0 || diff == row - i) {          // int a row or line  
                return false;  
            }  
        }  
        return true;  
    }  
  
    void placeQueens(int row, int n, vector<int> &colArray) {
		vector<string> v(n);
        string str;
        if (row == n) {  
            for(int i=0; i<n; i++){
                str = "";
                for(int j=0; j<n; j++){
					str += (j == colArray[i]? 'Q':'.');
                }
                v[i] = str;
            }
            ret.push_back(v);
            return;  
        }  
          
        for (int col = 0; col < n; ++col) {  
            colArray[row] = col;  //尝试每列
            if (check(row, colArray)){ //如果合法则往下递归
                placeQueens(row+1, n, colArray);  
            }  
        }  
    }  
      
    vector<vector<string> > solveNQueens(int n) {  
        vector<int> colArray(n);             
        placeQueens(0, n, colArray);            
        return ret;  
    } 
};
--------------end--------------

------------Next Permutation.cpp------------72
/*
函数实现原理：
在当前序列中，从尾端往前寻找两个相邻元素，前一个记为*i，后一个记为*ii，并且满足*i < *ii。
然后再从尾端寻找另一个元素*j，如果满足*i < *j，即将第i个元素与第j个元素对调，
并将第ii个元素之后（包括ii）的所有元素颠倒排序，即求出下一个序列了。
*/
class Solution {
public:
    void swap(vector<int> &num, int i, int j)  
    {  
        int temp = num[i];  
        num[i] = num[j];  
        num[j] = temp;  
    } 
    void nextPermutation(vector<int> &num) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int len = num.size(), index = -1;
        //从后往前找出现的第一个升序排列的数对
        for(int i=len-2; i>=0; i--){
            if(num[i] < num[i+1]){
                index = i;//记录下较小数的位置
                break;
            }
        }
        if(index == -1){ //找不到升序排列的数对,i < ii
            sort(num.begin(),num.end());
            return;
        }
        //在顺序数对后，从最右边找一个大于i的数，跟i交换
        for(int i=len-1; i>index; i--){
            if(num[i] > num[index]){
                swap(num, index, i);
                break;      //记得要break，这里WA了一次
            }
        }
		//然后，从ii开始往右排序，就得到next_permutation了
        sort(num.begin()+index+1, num.end());
    }
};
--------------end--------------

------------Palindrome Number.cpp------------73
//水题，把整数反转一下，对比即可
class Solution {
public:
	//把整数反转
    int reverse(int x) {
       int res = 0;
       while(x){
           res = res*10+x%10;
           x/=10;
       }
       return res;
    }
    bool isPalindrome(int x) {
        if(x<0) return false;
        return x == reverse(x);
    }
};
--------------end--------------

------------Palindrome Partitioning II.cpp------------74
//动态规划，判断回文也用动规，非常经典的题，状态转移方程很不错
class Solution {  
public:  
	//res[i] 区间[i,n]之间最小的cut数，n为字符串长度，则
	//res[i] = min(1+res[j+1], res[i] ) 若 i<=j <n，且s[i..j]是回文
	//因为，可以从j后面分割，j+1到n的之前分过了（子问题）
    int minCut(string s) {  
        int n = s.size();  
        vector<int > res(n+1);  
        vector<vector<bool> > p(n, vector<bool>(n, false));  
        for(int i = 0; i <= n; ++i) {  
            res[i] = n - i - 1; //比如res[0]开始应初始化为n-1次 
        } 
		//从后往前数
        for(int i = n - 1; i >=0; --i) {  
            for(int j = i; j < n; ++j) {  
                if(s[i] == s[j] && (j - i < 2 || p[i + 1][j - 1])) { //判断回文
                    p[i][j] = true; //s[i..j]是回文
                    res[i] = min(res[i], res[j + 1] + 1);  
                }  
            }  
        }  
        return res[0];  
    }  
};
--------------end--------------

------------Palindrome Partitioning.cpp------------75
//直接上最好的方法吧
//因为这个题目要求对整个字符串进行各种划分，所以最好能够得到从任意i到j位置是否为回文的一个表
//所以，上来先调用setIsPalin得到这个表
//tmp.push_back(s.substr(start, end-start+1))这句放的位置很好，如果放在循环里面，
//则push进去还要pop出来，太麻烦
class Solution {
    vector<vector<string>> result;
public:
    void setIsPalin(string s, vector<vector<bool>> &f, int N){
        for(int i = N-2; i >= 0; i--) //必须从N-2循环到0
            for(int j = i+1; j < N; j++)
                f[i][j] = s[i] == s[j] && f[i+1][j-1];
    }
    
    void part(int start, int end, vector<string> tmp, string &s, vector<vector<bool>> &isPalin, int N){
        tmp.push_back(s.substr(start, end-start+1)); //push放在这里很好，因为是拷贝，所以不会影响原值
        if(end == N-1){ //如果已经对字符串遍历完了，则记录
            result.push_back(tmp); 
            return;
        }
        for(int i = end+1; i < N; i++){
            if(isPalin[end+1][i]){
                part(end+1, i, tmp, s, isPalin);
            }
        }
    }

    vector<vector<string>> partition(string s) {
        result.clear();
        int N = s.size();
        vector<vector<bool>> isPalin(N, vector<bool>(N, true));
        setIsPalin(s, isPalin, N);
        vector<string> tmp;
        for(int i = 0; i < N; i++){
            if(isPalin[0][i]){ //如果从0到i是回文，则对余下字符串判断是否能划分
                part(0, i, tmp, s, isPalin, N);
            }
        }
        return result;
    }
};

其中，
	void setIsPalin(string s, vector<vector<bool>> &f, int N){
        for(int i = N-2; i >= 0; i--)
            for(int j = i+1; j < N; j++)
                f[i][j] = s[i] == s[j] && f[i+1][j-1];
    }
绝不可以写成：
	void setIsPalin(string s, vector<vector<bool>> &f, int N){
        for(int i = 0; i < N-1; i++)
            for(int j = i+1; j < N; j++)
                f[i][j] = s[i] == s[j] && f[i+1][j-1];
    }
但是可以写成：
	void setIsPalin(string s, vector<vector<bool>> &f, int N){
        for(int i = N-2; i >= 0; i--)
            for(int j = N-1; j >= i+1; j--)
                f[i][j] = s[i] == s[j] && f[i+1][j-1];
    }
为什么？
	想一下，如果要计算f[1][6]必须要知道f[2][5]，
	f[2][5]的计算要知道f[3][4]，所以i是从后往前倒着求才行，
	j的话没关系，本行之内没有依赖关系

--------------end--------------

------------Partition List.cpp------------76
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/*
Given 1->4->3->2->5->2 and x = 3,
return 1->2->2->4->3->5.
把数据分成2个链表，小于x的放到smaller中，大于x的放到bigger中
因为，链表是顺序放的，所以他们之间的相对顺序是不会变的
smaller_head和biger_head是头指针，smaller_ptr和biger_ptr是用来遍历的指针
返回的时候，注意两个链表是否为空的情况即可
*/
class Solution {
public:
    ListNode *partition(ListNode *head, int x) {
        ListNode *smaller_head, *biger_head, *smaller_ptr, *biger_ptr;
        smaller_head = biger_head = smaller_ptr = biger_ptr = NULL;
        while(head) {
			//把小于x的元素放到smaller这个链表中
            if(head->val < x){
				//根据smaller是否为空链表来操作
                if(!smaller_head) smaller_head = smaller_ptr = head;
                else{
                    smaller_ptr->next = head;
                    smaller_ptr = smaller_ptr->next;
                } 
            }
			//把大于等于x的元素放到bigger这个链表中
            else{
				//根据biger是否为空链表来操作
                if(!biger_head) biger_head = biger_ptr = head;
                else{
                    biger_ptr->next = head;
                    biger_ptr = biger_ptr->next;
                } 
            }
            head = head->next;
        }
		//根据链表为空的情况返回结果
        if(!smaller_head && !biger_head) return NULL;
        if(biger_head) biger_ptr->next = NULL;
        if(smaller_head){
            smaller_ptr->next = biger_head;
            return smaller_head;
        }
        return biger_head;
    }
};
--------------end--------------

------------Pascal's Triangle II.cpp------------77
/*
只需要两个vector即可，
用v来进行计算，用v_last来存上一行的
rowIndex是从0th开始算的
*/
class Solution {
public:
     vector<int> getRow( int rowIndex) {
        vector< int> v, v_last;
        rowIndex++; //先加1，从1开始算，这样行数和元素数相等
        v.push_back(1);
        v_last = v;
        if(rowIndex == 1) return v;
        for( int i=2; i<=rowIndex; i++){ //从第2行到第rowIndex行
            v.clear();
            v.push_back(1);
            for( int j=0; j<i-2; j++) { //中间有i-2个元素
                v.push_back(v_last[j]+v_last[j+1]);
            }
            v.push_back(1);
            v_last = v;
        }
        return v;
    }
};
--------------end--------------

------------Pascal's Triangle.cpp------------78
class Solution {
public:
    vector<vector< int> > generate( int numRows) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        vector<vector< int> > v_res;
        vector< int> v, v_last;
        if(numRows == 0){
            return v_res;
        }
        v.push_back(1);
        v_last = v;
        v_res.push_back(v);
        for( int i=2; i<=numRows; i++){
            v.clear();
            v.push_back(1);
            for( int j=0; j<i-2; j++){
                v.push_back(v_last[j]+v_last[j+1]);
            }
            v.push_back(1);
            v_last = v;
            v_res.push_back(v);
        }
        return v_res;
    }
};

--------------end--------------

------------Path Sum II.cpp------------79
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
典型的DFS，没啥好说的
*/
class Solution {
private:
    vector<vector<int> > ret;
public:
    void pathSum(TreeNode *node, int sum2now, vector<int> temp, int sum){
        if(!node) return;
        sum2now += node->val;
        temp.push_back(node->val);
        if(!node->left && !node->right){
            if(sum2now == sum){
                ret.push_back(temp);
                return;
            }
        }
        else{
            pathSum(node->left, sum2now, temp, sum);
            pathSum(node->right, sum2now, temp, sum);
        }
    }
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        vector<int> temp;
        ret.clear();
        pathSum(root, 0, temp, sum);
        return ret;
    }
};
--------------end--------------

------------Path Sum.cpp------------80
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
用DFS和BFS都行吧，不过因为不是求最短XX，所以深搜就行了，深搜也好写一点
终止条件：1、传进来的指针为NULL 2、无子节点，且到当前节点的和不等于目标
完成条件：无子节点且到当前节点的和等于目标
*/
class Solution {
public:
    bool hasPathSum(TreeNode *root, int sum, int sumToNow) {
        if(!root) return false; //终止条件
        sumToNow += root->val;  //得到到当前节点的和
        if(!root->right && !root->left) { //无子节点
            if(sumToNow == sum) return true; //完成条件
            else return false;	//终止条件
        }
        if(hasPathSum(root->right, sum, sumToNow) || //分别对左右子节点递归
			hasPathSum(root->left, sum, sumToNow)) return true;
        else return false;
    }
    bool hasPathSum(TreeNode *root, int sum) {
        int sumToNow = 0;
        return hasPathSum(root, sum, sumToNow);
    }
};
--------------end--------------

------------Permutation Sequence.cpp------------81
/*
n在[1,9]范围，最快的方法如下。
思路：
我们把a1 去掉，那么剩下的排列为a2; a3; :::; an, 共计n-1 个元素，n-1 个元素共有(n-1)!
个排列，于是就可以知道a1 = k/(n-1)!。以此类推。。。
*/
class Solution {
public:
    string getPermutation(int n, int k) {
        int n_x[10];
        vector<char> v;
        string s = "";
        if(n == 1){
            return "1";
        }
        n_x[0] = 1; //0的阶乘
        for(int i=1; i<=n; i++){
            n_x[i] = n_x[i-1]*i; //计算i的阶乘
            v.push_back(i+48);   //把数字的字符放到v中
        }
        while(v.size()){
            int i = 0;
            while(k - n_x[v.size()-1] > 0){ //k-(n-1)!
                i++;
				k -= n_x[v.size()-1];
            }
            s += v[i];
            v.erase(v.begin()+i);
        }
        return s;
    }
};

//暴力枚举法，调用k-1 次next_permutation()。
//暴力枚举法把前k 个排列都求出来了，比较浪费，而我们只需要第k个排列。
--------------end--------------

------------Permutation.cpp------------82
First Try:
//利用交换，DFS
class Solution {
public:    
    void permute(vector<vector<int> > &v_res, vector<int> &num, int k, int len){
        vector<int> v;
        if(k == len){
            for(int i=0; i<=len; i++){
                v.push_back(num[i]);
            }
            v_res.push_back(v);
        }
        else{
            for(int i=k; i<=len; i++){ 
                swap(num+k, num+i); //第k个元素跟它后面的所有元素(包括k)依次交换
                permute(v_res, num, k+1, len);
                swap(num+k, num+i); //依次交换回来
            }
        }
    }
    vector<vector<int> > permute(vector<int> &num) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        vector<vector<int> > v_res;
        permute(v_res, num, 0, num.size()-1);
        return v_res;
    }
};

Second Try:
//利用next_permutation
class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
        vector<vector<int> > result;
        sort(num.begin(), num.end());
        do {
            result.push_back(num);
        } while(next_permutation(num.begin(), num.end()));
        return result;
    }
};
--------------end--------------

------------Permutations II.cpp------------83
/*
利用stl的next_permutation函数，加上去重，
next_permutation和prev_permutation要能熟练的自己实现
*/
class Solution {
public:
    vector<vector<int> > permuteUnique(vector<int> &num) {
        vector<vector<int> > result;
        sort(num.begin(), num.end());
        do {
            result.push_back(num);
        } while(next_permutation(num.begin(), num.end()));
        result.erase(unique(result.begin(),result.end()), result.end());
        return result;
    }
};

/*
回溯法，现在的LC上会超时了，以前不会
*/
class Solution {
public:
    void permute(vector<vector<int> > &v_res, vector<int> num, int k, int len){
        if(k == len){
            v_res.push_back(num);
        }
        else{
            for(int i=k; i<=len; i++){
                swap(num[k], num[i]);
                permute(v_res, num, k+1, len);
                swap(num[k], num[i]);
            }
        }
    }
    vector<vector<int> > permuteUnique(vector<int> &num) {
        vector<vector<int> > v_res;
        permute(v_res, num, 0, num.size()-1);
		v_res.erase(unique(v_res.begin(),v_res.end()), v_res.end());
        return v_res;
    }
};
--------------end--------------

------------Plus One.cpp------------84
My solution:
//很简单，用carry不断的进位，如果不需要进位就返回即可，
//如果一直都要进位，就最后在开头插入个1
class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        int len = digits.size();
        int carry = 1;
        for(int i=len-1; i>=0; i--){
            digits[i] += carry;
            if(digits[i] >= 10){
                digits[i] %= 10;
            }
            else{
                return digits;
            }
        }
        digits.insert(digits.begin(), 1);
        return digits;
    }
};
--------------end--------------

------------Populating Next Right Pointers in Each Node II.cpp------------85
/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
//思路：用vector模拟queue操作，把每一层的连起来即可
class Solution {
public:
    void levelOrder(TreeLinkNode *root) {
        vector<TreeLinkNode*> tree; //用vector模拟队列操作
        int head = 0, tail = 0;
        if(root){ //如果root不是空，先push进去
            tree.push_back(root);
            tail++;
        }
        while(head!=tail){
            int tail_current = tail; //记录下当前的tail位置，从head到tail_current是一层
            for(; head<tail_current; head++){
                if(tree[head]->left){ //先左
                    tree.push_back(tree[head]->left);
                    tail++;
                }
                if(tree[head]->right){ //后右
                    tree.push_back(tree[head]->right);
                    tail++;
                }
            }
			//把刚才push进去的节点连起来
            for(int i=head; i<tail-1; i++){
                tree[i]->next = tree[i+1];
            }
        }
    }

    void connect(TreeLinkNode *root) {
        levelOrder(root);
    }
};


--------------end--------------

------------Populating Next Right Pointers in Each Node.cpp------------86
First Try:
/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
//递归解法
class Solution {
public:
    void connect(TreeLinkNode *left, TreeLinkNode *right) {
        if(left == NULL) return;
        left->next = right;
        connect(left->left, left->right);
        connect(left->right, right->left);
        connect(right->left, right->right);
    }
    
    void connect(TreeLinkNode *root) {
        if(root == NULL || root->right == NULL) return;
        connect(root->left, root->right);
    }
};

Second Try:
//非递归解法-使用队列
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(root == nullptr) return;
        queue<TreeLinkNode *> q;
        q.push(root);
        while(!q.empty()) {
            TreeLinkNode *ptr_l, *ptr_r;
            int size = q.size();
            ptr_l = q.front(); q.pop();
            if(ptr_l->left) q.push(ptr_l->left);
            if(ptr_l->right) q.push(ptr_l->right);
            for(int i=1; i<size; i++) { //在循环中清掉上一层节点
                ptr_r = q.front(); q.pop();
                if(ptr_r->left) q.push(ptr_r->left);
                if(ptr_r->right) q.push(ptr_r->right);
                ptr_l->next = ptr_r; //连接节点
                ptr_l = ptr_r; //指针右移
            }
        }
    }
};
--------------end--------------

------------Pow(x, n).cpp------------87
//采用了二分法，因为计算复杂度锐减为log n
//如果用循环连乘，计算复杂度是线性
class Solution {
public:
    double pow(double x, int n) {  
        if (n == 0) return 1.0;  
        // Compute x^{n/2} and store the result into a temporary  
        // variable to avoid unnecessary computing  
        double half = pow(x, n / 2);  
        if (n % 2 == 0)  
            return half * half;  
        else if (n > 0)  
            return half * half * x;  
        else  
            return half * half / x;  
    }
};
--------------end--------------

------------Recover Binary Search Tree.cpp------------88
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
O(n) 空间的解法是，开一个指针数组，中序遍历，将节点指针依次存放到数组里，然后寻找两
处逆向的位置，先从前往后找第一个逆序的位置，然后从后往前找第二个逆序的位置，交换这两个
指针的值。
*/

/*
O(log n) 空间的解法如下：
用递归中序遍历，中序遍历的特点是元素访问是按照从小到大被访问的，如果碰到一个逆序的，
则这个逆序的两个点有一个肯定是错了的，那么到底是哪个呢？
从中序遍历的特点可知，第一个错误的节点肯定是逆序对中的较大的，第二个则是逆序对中较小的
*/
class Solution { 
public : 
    TreeNode *first, *second, *pre; 
    void inorder(TreeNode *root) {  
		if(root->left) inorder(root->left);
		if(pre == NULL) pre = root;
		else if(pre->val > root->val) {
            if(first == NULL)   //如果first还没被赋值，则将大的那个赋给first
                first = pre;    
            second = root; //如果first已经赋值过了，则将小的那个赋给second
        } 
        pre = root; 
        if(root->right) inorder(root->right); 
    } 
    void recoverTree(TreeNode *root) { 
        if(!root) return;
        first = second = pre = NULL; 
        inorder(root);
        swap(first->val, second->val); //交换两个错误节点
    }
};  

/*
O(1) 空间的解法：Morris 中序遍历
*/

--------------end--------------

------------Regular Expression Matching.cpp------------89
/*p是正则表达式，s为字符串
1.如果p为空串 则s必须为空串才匹配
2.如果非空, 则分2种情况讨论
  a.如果下一个字符非*号，则当前的字符要么相等要么p以.来取代s中的字符，且s中必须有字符（.不能匹配/0）
    如果满足以上条件，则递归从s+1，p+1进行判断
  b.如果下一个字符是*号，则当前p的字符也要与s的字符相同或以.取代，不同的是p中的*号可以不断蚕食s中的字符直到/0
    因此递归是s++，p+2，直到s为\0时
*/
class Solution {
public:
    bool isMatch(const char *s, const char *p) {  
        if(*p == '\0') return *s == '\0';
        if(*(p+1) != '*') {
            //当前的字符要么相等要么以.来取代
            if(*p == *s || (*p == '.' && *s != '\0')){
                return isMatch(s+1, p+1);
            }
            else{
                return false;
            }
        }
        else{
            //若下个字符为*，当前p的字符也要与s的字符相同或以.取代
            while(*p == *s || (*p == '.' && *s != '\0')){
                //取代的字符个数尝试增加
                if(isMatch(s++, p+2)){
                    return true;
                }
            }
            //当*s == '\0'时
            return isMatch(s, p+2);
        }
    }  
};
--------------end--------------

------------Remove Duplicates from Sorted Array II.cpp------------90
//用一个变量记录出现的次数
class Solution {
public:
    int removeDuplicates(int A[], int n) {
        int index = 1, count = 1, len = 1;
        if(!n) return 0;
        for(int i=1; i<n; i++) {
            if(A[i]!=A[i-1]) {
                count = 1;
                A[index++] = A[i];
                len++;
            }
            else if(count < 2) {
                A[index++] = A[i];
                count++;
                len++;
            }
            else {
                count++;
            }
        }
        return len;
    }
};
--------------end--------------

------------Remove Duplicates from Sorted Array.cpp------------91
First Try:
//double pointer, 注意n为0的情况
class Solution {
public :
    int removeDuplicates( int A[], int n) {
        int length = 1;
        if(!n) return 0;
        for( int i=1; i<n; i++){
            if(A[i] != A[i-1]){
               A[length++] = A[i]; 
            }
        }
        return length;
    }
};

Second Try:
//一种奇特的方法
class Solution {
public:
    int removeDuplicates(int A[], int n) {
        return distance(A, unique(A, A + n));
    }
};
注：distance返回两个迭代器的距离，unique函数把相邻的重复元素移到末尾，返回交界位置
--------------end--------------

------------Remove Duplicates from Sorted List II.cpp------------92
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/*第一种方法太弱了，弱爆了，用vector放ListNode，
搞得这题像是数组操作*/
class Solution {
private:
    vector<int> v;
public:
    ListNode *deleteDuplicates(ListNode *head) {
        int n;
        ListNode *ptr = head;
        n = 0;
        v.clear();
        while(ptr){
            if(ptr->next && ptr->next->val == ptr->val){
                n++;
            }
            else if(n){
                n = 0;
            }
            else{
                v.push_back(ptr->val);
            }
            ptr = ptr->next;
        }
        int len = v.size();
        if(!len){
            return NULL;
        }
        head->val = v[0];
        ptr = head;
        for(int i=1; i<len; i++) {
            ptr->next = new ListNode(v[i]);
            ptr = ptr->next;
        }
        ptr->next = NULL;
        return head;
    }
};

Second Try:
/*
第二种方法正常一些，用一个指针before放在重复元素之前，
因为知道重复元素的值，所以遍历把重复元素删除完
*/
class Solution {
	public:
	   ListNode *deleteDuplicates(ListNode *head) {
		ListNode h(-1); //一定要多一个节点
		ListNode *ptr = head;
		ListNode *before = &h; //before开始的时候指向这个节点
		int val;
		h.next = head;
		while(ptr && ptr->next) { //ptr不为空且不为最后一个节点
			if(ptr->val != ptr->next->val) {
				before = ptr;
				ptr = ptr->next;
			}
			else {
				val = ptr->val;
				while(ptr->val == val) { //删除所有重复元素
					before->next = ptr = ptr->next;
					if(ptr == NULL) break;
				}
			}
		}
		return h.next;
	}
};
--------------end--------------

------------Remove Duplicates from Sorted List.cpp------------93
First Try:
/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/
/*
其实第一种解法还不如第二种解法好, 因为delete操作没有顺便做
*/
class Solution {
public:
   ListNode *deleteDuplicates(ListNode *head) {
       ListNode *cur1, *cur2;
       cur1 = cur2 = head;				// both points are in the begining
       while(cur1) {
           while(cur1->next && cur1->val == cur1->next->val){ // if duplicate, move cur1 forward 
               cur1 = cur1->next;
           }
           cur2->next = cur1->next; // link cur2 to next element
           cur2 = cur2->next;		// move cur2 forward
		   cur1 = cur1->next;		// move cur1 forward
       }
       return head;
   }
};

Second Try:
class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        ListNode *ptr = head;
        while(ptr != nullptr && ptr->next != nullptr) {
            if(ptr->val == ptr->next->val) { //如果重复就跳过一个元素
                delete ptr->next;
				ptr->next = ptr->next->next;
			}
            else ptr = ptr->next;		//否则forward一个元素
        }
        return head;
    }
};
--------------end--------------

------------Remove Element.cpp------------94
//double pointer
class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int length = 0;
        for(int i=0; i<n; i++){
            if(A[i] != elem){
                A[length++] = A[i];
            }
        }
        return length;
    }
};
--------------end--------------

------------Remove Nth Node From End of List.cpp------------95
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

/*
先让current往前走n-1步，再让remove往前跟着走，
为什么是n-1步，只要一画图就知道了，因为remove要指向删除的节点的前一个节点
*/
class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode beforeHead(-1);
        ListNode *current = head, *remove = &beforeHead;
        beforeHead.next = head;
        for(int i=0; i<n-1; i++) {
            current = current->next; //先让current往前走n-1步
			if(current == NULL) return head;
        }
        while(current->next) {
            current = current->next;
            remove = remove->next;
        }
        remove->next = remove->next->next;
        return beforeHead.next;
    }
};
--------------end--------------

------------Reorder List.cpp------------96
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/*
思路：
把链表分成2部分，把后一半单链表reverse，再合并两个单链表
*/
class Solution {
public:
    void reorderList(ListNode *head) {
        ListNode *fast, *slow, *half;
        half = fast = slow = head;
        if(!head || !head->next){ //小于2个节点直接返回
            return;
        }
        while(fast && fast->next) {
            half = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        half->next = NULL;
		//逆序后一半链表
        half = reverse(slow);
		//合并前一半链表和逆序后的后一半链表
		//前面的逆序能保证前一半不会比后一半长
		//(奇数节点时，后一半会多一个节点)
        merge(head, half);
    }
    
	//merge两个链表
    void merge(ListNode *head, ListNode *half){
        ListNode *p1 = head, *p2 = half;
        while(p1->next){ 
            ListNode *tmp;
            tmp = p1->next;
            p1->next = p2;
            p2 = p2->next;
            p1->next->next = tmp;
            p1 = tmp;
        }
		p1->next = p2;
    }
    
	//逆序是老生常谈了，小心点就行了
    ListNode *reverse(ListNode *head){
        ListNode *p0, *p1, *p2;
        if(!head || !head->next) { //小于2个节点直接返回
            return head;
        }
		//逆序肯定是要3个指针的，一画图就明白了，2个指针是不行的
        p0 = head;
        p1 = p0->next;
        p2 = p1->next;
		while(p2){
            p1->next = p0;
            p0 = p1;
            p1 = p2;
            p2 = p2->next;
        }
		//逆序最后的收尾工作，如果只有两个节点，while是进不去的，
		//这里做两个节点的逆序
        p1->next = p0;
        head->next = NULL;
        return p1;
    }
};
--------------end--------------

------------Restore IP Addresses.cpp------------97
class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        string ip;
        dfs(s, 0, 0, ip, res);
        return res;
    }
private:
    //start: 从s的哪里开始 step: 当前ip段号, ip: 中间ip结果
    void dfs(string s, int start, int step, string ip, vector<string> &res){
        int len = s.length();
        //dfs终止条件
		if(len == start && step == 4){
            ip.resize(ip.size()-1); //去掉最后一个'.'
            res.push_back(ip);
            return;
        }
        
        //剪枝:如果剩余字串长度太长，或者太短，就不用继续搜了
        if((len - start > (4-step)*3) || (len - start < 4 - step)){
            return;
        }
        //dfs核心代码
		//ip一级只有3位，所以循环只需3次
        int num = 0;
        for(int i=start; i<start+3; i++){
            num = num*10 + (s[i]-'0');
            ip += s[i]; //当前ip
            if(num <= 255){ //满足小于等于255的数才是合法的ip段
                dfs(s, i+1, step+1, ip+'.', res); //合法ip段后面加.进入下一级递归
            }
            if(!num) break;  //允许单个0，不允许前缀0
        }
    }
};
--------------end--------------

------------Reverse Integer.cpp------------98
class Solution {
public:
   int reverse(int x) {
       // Note: The Solution object is instantiated only once and is reused by each test case.
       int res = 0;
       while(x){
           res = res*10+x%10;  //no matter positive or negative
           x/=10;
       }
       return res;
   }
};
--------------end--------------

------------Reverse Linked List II.cpp------------99
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 /*
 思路：细心，画图
 */
class Solution {
public:
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        ListNode *start, *end, *beforeStart, *afterEnd, *ptr;
        start = end = beforeStart = afterEnd = NULL;
        ptr = head; //ptr指向head，head就可以保持不动了
		//找到beforeStart的位置
        for(int i=1; i<m; i++){
            beforeStart = ptr;
            ptr = ptr->next;
        }
        start = end = ptr;
		//逆转
        for(int i=m; i<=n; i++){
            afterEnd = ptr->next;
            ptr->next = end;
            end = ptr;
            ptr = afterEnd;
        }
        if(beforeStart == NULL){
            head = end;
        }
        else{
            beforeStart->next = end;
        }
        start->next = afterEnd;
        return head;
    }
};
--------------end--------------

------------Reverse Nodes in k-Group.cpp------------100
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/*
递归版：
很巧妙，要记住
*/
class Solution {
public:
	ListNode *reverseKGroup(ListNode *head, int k) {
		if (head == nullptr || head->next == nullptr || k < 2)
			return head;
		ListNode *next_group = head;
		//如果剩余的节点个数不足k个，则返回head
		for (int i = 0; i < k; ++i) {
			if (next_group)
				next_group = next_group->next;
			else
				return head;
		}
		// next_group is the head of next group
		// new_next_group is the new head of next group after reversion
		ListNode *new_next_group = reverseKGroup(next_group, k);
		ListNode *prev = NULL, *cur = head;
		while (cur != next_group) {
			ListNode *next = cur->next;
			//第一个节点后继指向new_next_group，后面每个节点后继指向前一个节点
			cur->next = prev ? prev : new_next_group;
			//prev和cur向后移动一个元素
			prev = cur; 
			cur = next;
		}
		return prev; // prev will be the new head of this group
	}
};

/*迭代版*/
class Solution {
public:
	ListNode *reverseKGroup(ListNode *head, int k) {
		if (head == nullptr || head->next == nullptr || k < 2) return head;
		ListNode dummy(-1);
		dummy.next = head;
		//prev指向反转序列前的一个节点
		for(ListNode *prev = &dummy, *end = head; end; end = prev->next) {
			for (int i = 1; i < k && end; i++)
				end = end->next;
			if (end == nullptr) break; // 不足k 个，end是闭区间
			prev = reverse(prev, prev->next, end); //返回
		}
		return dummy.next;
	}
	// prev 是first 前一个元素, [begin, end] 闭区间，保证三者都不为null
	// 返回反转后的倒数第1 个元素
	ListNode* reverse(ListNode *prev, ListNode *begin, ListNode *end) {
		ListNode *end_next = end->next;
		//这段写的太不平易近人了，不推荐，下面有重写此函数的版本
		for (ListNode *p = begin, *cur = p->next, *next = cur->next;
			cur != end_next;
			p = cur, cur = next, next = next ? next->next : nullptr) {
			cur->next = p;
		}
		begin->next = end_next;
		prev->next = end;
		return begin;
	}
};

//重写迭代版的反转函数
class Solution {
public:
	ListNode *reverseKGroup(ListNode *head, int k) {
		if (head == nullptr || head->next == nullptr || k < 2) return head;
		ListNode dummy(-1);
		dummy.next = head;
		//prev指向反转序列前的一个节点
		for(ListNode *prev = &dummy, *end = head; end; end = prev->next) {
			for (int i = 1; i < k && end; i++)
				end = end->next;
			if (end == nullptr) break; // 不足k 个，end是闭区间
			prev = reverse(prev, prev->next, end); //返回
		}
		return dummy.next;
	}
	// prev 是first 前一个元素, [begin, end] 闭区间，保证三者都不为null
	// 返回反转后的倒数第1 个元素
	ListNode* reverse(ListNode *prev, ListNode *begin, ListNode *end) {
		ListNode *end_next = end->next;
		ListNode *before_cur = begin, *cur = begin->next, *next = cur->next;
		while(cur != end_next) {	//注意这里的条件！！！
			cur->next = before_cur; //cur后继指向before_cur
			before_cur = cur;
			cur = next;
			next = next? next->next:NULL;
		}
		begin->next = end_next;
		prev->next = end;
		return begin;
	}
};

/*
这种做法不符合要求，但是能过，
把节点都放到vector中，利用vector进行反转，然后再连起来，也容易实现
*/
class Solution {
public:
    ListNode *reverseKGroup(ListNode *head, int k) {
        vector<ListNode *> vk, v;
        int n = 0;
        vk.clear();
        v.clear();
        if(!head){
            return NULL;
        }
        while(head){
            vk.push_back(head);
            n++;
            if(n == k){
                n = 0;
                reverse(vk.begin(), vk.end());
                for(int i=0; i<k; i++){
                    v.push_back(vk[i]);
                }
                vk.clear();
            }
            head = head->next;
        }
        if(vk.size()){
            for(int i=0; i<vk.size(); i++){
                v.push_back(vk[i]);
            }
            vk.clear();
        }
        for(int i=0; i<(int)v.size()-1; i++){
            v[i]->next = v[i+1];
        }
        v[v.size()-1]->next = NULL;
        return v[0];
    }
};
--------------end--------------

------------Roman to Integer.cpp------------101
My solution:
class Solution {
public:
    int romanToInt(string s) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int res = 0;
        for(int j=0; j<s.length(); j++){
			switch (s[j])
			{
			case 'M':
				res += 1000;
				break;
			case 'D':
				res += 500;
				break;
			case 'L':
				res += 50;
				break;
			case 'V':
				res += 5;
				break;
			case 'C':
				if(j+1 < s.length() && ((s[j+1] == 'D')||(s[j+1] == 'M'))){
                    res -= 100;
                }
                else{
                    res += 100;
                }
				break;
			case 'X':
				if(j+1 < s.length() && ((s[j+1] == 'L') || (s[j+1] == 'C'))){
                    res -= 10;
                }
                else {
                    res += 10;
                }
				break;
			case 'I':
				if(j+1 < s.length() && ((s[j+1] == 'V') || (s[j+1] == 'X'))){
                    res -= 1;
                }
                else {
                    res += 1;
                }
				break;
			}
        }
        return res;
    }
};

Better solution:
class Solution {
public:
	inline int map(const char c) {
		switch (c) {
			case 'I': return 1;
			case 'V': return 5;
			case 'X': return 10;
			case 'L': return 50;
			case 'C': return 100;
			case 'D': return 500;
			case 'M': return 1000;
			default: return 0;
		}
	}

	int romanToInt(string s) {
		int result = 0;
		for (size_t i = 0; i < s.size(); i++) {
			if (i > 0 && map(s[i]) > map(s[i - 1])) {
				result += (map(s[i]) - 2 * map(s[i - 1]));
			} else {
				result += map(s[i]);
			}
		}
		return result;
	}
};
--------------end--------------

------------Rotate Image.cpp------------102
My naive solution:
//没想到原地转置的办法,用了额外的空间
class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
		// Note: The Solution object is instantiated only once and is reused by each test case.
		vector<vector<int> > matrix_r;
		int n = matrix.size();
		matrix_r.resize(n);
		for(int i=0; i<n; i++){
			vector<int> v = matrix[n-i-1];
			for(int j=0; j<n; j++){
				matrix_r[j].push_back(v[j]);
			}
		}
		for(int i=0; i<n; i++){
			matrix[i] = matrix_r[i];
		}
		return;
	}
};

Better solutions:
Solution 1:
//沿副对角线反转+沿水平轴反转 
class Solution {
public:
	void rotate(vector<vector<int>>& matrix) {
		const int n = matrix.size();
		for (int i = 0; i < n; ++i) // 沿着副对角线反转
			for (int j = 0; j < n - i; ++j)
				swap(matrix[i][j], matrix[n - 1 - j][n - 1 - i]);
		for (int i = 0; i < n / 2; ++i) // 沿着水平中线反转
			for (int j = 0; j < n; ++j)
				swap(matrix[i][j], matrix[n - 1 - i][j]);
	}
};

Solution 2:
//沿水平轴反转+沿主对角线反转
class Solution {
public:
	void rotate(vector<vector<int>>& matrix) {
		const int n = matrix.size();
		for (int i = 0; i < n / 2; ++i) // 沿着水平中线反转
			for (int j = 0; j < n; ++j)
				swap(matrix[i][j], matrix[n - 1 - i][j]);
		for (int i = 0; i < n; ++i) // 沿着主对角线反转
			for (int j = i + 1; j < n; ++j)
				swap(matrix[i][j], matrix[j][i]);
	}
};
--------------end--------------

------------Rotate List.cpp------------103
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/*
思路：一个指针先移动k，接着两个指针一起移动，最后断开重连
难点：链表长度不足k时的处理
*/
class Solution {
public:
   ListNode *rotateRight(ListNode *head, int k) {
        ListNode *ptr1, *ptr2, *res;
        int i, len;
        ptr1 = ptr2 = head;
        if(!k || !head) return head;
		//ptr1先往前走k个节点
        for(i=0; i<k; i++) {
            ptr1 = ptr1->next;
            if(!ptr1){ //如果已经是NULL了，则说明List长度还不足k
				i++;
                break;
            }
        }
		//如果list长度小于等于k
        if(ptr1 == NULL) {
            len = i; //得到链表长度
            k = k%len; //重新得到k
            if(!k) return head; //如果k是0，则返回head
			//否则ptr1重新往前走k个节点
            ptr1 = head;
            for(i=0; i<k; i++) {
                ptr1 = ptr1->next;
            }
        }
		//ptr2随着ptr1一同往前移动，直到ptr1移动到最后一个节点
        while(ptr1->next) {
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
		//断开重连
        res = ptr2->next;
        ptr2->next = NULL;
        ptr1->next = head;
        return res;
    }
};
--------------end--------------

------------Same Tree.cpp------------104
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
--------------end--------------

------------Scramble String.cpp------------105
/*
思路：
首先想到的是递归（即深搜），对两个string 进行分割，然后比较四对字符串。代码虽然简单，
但是复杂度比较高。有两种加速策略，一种是剪枝，提前返回；一种是加缓存，缓存中间结果，即
memorization（翻译为记忆化搜索）。
剪枝可以五花八门，要充分观察，充分利用信息，找到能让节点提前返回的条件。例如，判断
两个字符串是否互为scamble，至少要求每个字符在两个字符串中出现的次数要相等，如果不相等
则返回false。
加缓存，可以用数组或HashMap。本题维数较高，用HashMap，map 和unordered_map 均可。
既然可以用记忆化搜索，这题也一定可以用动规。设状态为f[n][i][j]，表示长度为n，起
点为s1[i] 和起点为s2[j] 两个字符串是否互为scramble，则状态转移方程为
f[n][i][j] = (f[k][i][j] && f[n-k][i+k][j+k]) || (f[k][i][j+n-k] && f[n-k][i+k][j])
*/
class Solution {
public:
    bool isScramble(string s1, string s2) {
        int len = s1.length();
        if(len != s2.length()) return false;
        bool res[len+1][len][len];
        memset(res, false, sizeof(bool)*(len+1)*len*len);
		//初始化
        for(int i=0; i<len; i++){
            for(int j=0; j<len; j++){
                res[1][i][j] = s1[i]==s2[j]; //长度为1，起点为s1[i]和s2[j]的字符串是否互为scramble
            }
        }
        
        for(int l=2; l<=len; l++){ //l stand for length
            for(int i=0; i<=len-l; i++){  //注意等于号，s1的起点
                for(int j=0; j<=len-l; j++){ //s2的起点
                    for(int divlen=1; divlen<l && !res[l][i][j]; divlen++){ //遍历分割点
                        if((res[divlen][i][j] && res[l-divlen][i+divlen][j+divlen]) 
                            || (res[divlen][i][j+l-divlen] && res[l-divlen][i+divlen][j])){
                            res[l][i][j] = true;
                            break;   //有一次true就可以了
                        }
                    }
                }
            }
        }
        return res[len][0][0];
    }
};
--------------end--------------

------------Search for a Range.cpp------------106
/*
方法一：
利用STL的lower_bound，upper_bound和distance函数
*/
class Solution {
public:
	vector<int> searchRange(int A[], int n, int target) {
		const int l = distance(A, lower_bound(A, A + n, target));
		const int u = distance(A, prev(upper_bound(A, A + n, target)));
		if (A[l] != target) // not found
			return vector<int> { -1, -1 };
		else
			return vector<int> { l, u };
	}
};

/*
方法二：
重新实现lower_bound和upper_bound算法
*/
class Solution {
public:
	vector<int> searchRange (int A[], int n, int target) {
		auto lower = lower_bound(A, A + n, target);
		auto uppper = upper_bound(lower, A + n, target);
		if (lower == A + n || *lower != target)
			return vector<int> { -1, -1 };
		else
			return vector<int> {distance(A, lower), distance(A, prev(uppper))};
	}

	template<typename ForwardIterator, typename T>
	ForwardIterator lower_bound (ForwardIterator first, ForwardIterator last, T target) {
		while (first != last) {
			auto mid = next(first, distance(first, last) / 2);
			if (*mid < target) first = ++mid; 
			else last = mid; //等于跟大于一样，都移动last
		}
		return first;
	}

	template<typename ForwardIterator, typename T>
	ForwardIterator upper_bound (ForwardIterator first, ForwardIterator last, T value) {
		while (first != last) {
			auto mid = next(first, distance (first, last) / 2);
			if (*mid <= target) first = ++mid; // 与lower_bound 仅此不同，等于跟小于一样，都移动last
			else last = mid;
		}
		return first;
	}
};
--------------end--------------

------------Search in Rotated Sorted Array II.cpp------------107
//允许重复元素，则上一题中如果A[m]>=A[l], 那么[l,m] 为递增序列的假设就不能成立了，比
//如[1,3,1,1,1]。
//如果A[m]>=A[l] 不能确定递增，那就把它拆分成两个条件：
//若A[m]>A[l]，则区间[l,m] 一定递增
//若A[m]==A[l] 确定不了，那就l++，即跳过最左边的重复元素
//很显然，这不会影响结果
class Solution {
public:
	bool search(int A[], int n, int target) {
		int first = 0, last = n;
		while (first != last) {
			const int mid = (first + last) / 2;
			if (A[mid] == target) return true;		
			if (A[first] < A[mid]) {
				if (A[first] <= target && target < A[mid])
					last = mid;
				else
					first = mid + 1;
			} else if (A[first] > A[mid]) {
				if (A[mid] <= target && target <= A[last-1])
					first = mid + 1;
				else
					last = mid;
			} else
				//跳过重复元素, A[start] == A[mid]
				first++;
		}
		return false;
	}
};
--------------end--------------

------------Search in Rotated Sorted Array.cpp------------108
//二分法查找的变形, 时间复杂度log n
//分别讨论各种情况
//与普通二分查找的区别是：普通二分法只需要将target和mid位置的数比较就可以排除一半元素
//而此题首先判断出那边是连续的段，然后判断target是否在连续的段中，进而排除一半元素
//因为如果不得到连续的段，就没法进行判断
class Solution {
public:
	int search(int A[], int n, int target) {
		int first = 0, last = n;
		while (first != last) {
			const int mid = (first + last) / 2;
			if (A[mid] == target)
				return mid;
			//左半边是连续的
			if (A[first] <= A[mid]) {
				//判断target是否在左段
				if (A[first] <= target && target < A[mid])
					last = mid;
				else
					first = mid + 1;
			} 
			//右边是连续的
			else {
				//判断target是否在右段
				if (A[mid] < target && target <= A[last-1])
					first = mid + 1;
				else
					last = mid;
			}
		}
		return -1;
	}
};
--------------end--------------

------------Search Insert Position.cpp------------109
First Try:
//using binary search
class Solution {
public:
    int searchInsert( int A[], int n, int target) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        int head = 0, tail = n-1, mid;
        if(! n || target < A[0]) return 0; 
        if( target > A[ n-1]) return n;
        while(1) {
            if( A[head] == target){
                return head;
            }
            if( A[tail] == target){
                return tail;
            }
			//mid = ((head+tail+1)>>1);
            //if(mid == tail) return tail;
            mid = ((head+tail)>>1);
            if(mid == head) return tail;
            if( A[mid] <= target){
                head = mid;
            }
            else {
                tail = mid;
            }
        }
    }
};

Second Try:
class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        int index = 0;
        for(int i=0; i<n; i++) {
            if(target > A[i]) index++;
            else break;
        }
        return index;
    }
};
--------------end--------------

------------Set Matrix Zeroes.cpp------------110
//O(m + n) 空间的方法很简单，设置两个数组，记录每行和每列是否存在0。
//想要常数空间，可以复用第一行和第一列。
O(m+n)空间的方法:
class Solution {
public:
	void setZeroes(vector<vector<int> > &matrix) {
		const size_t m = matrix.size();
		const size_t n = matrix[0].size();
		vector<bool> row(m, false); // 标记该行是否存在0
		vector<bool> col(n, false); // 标记该列是否存在0
		for (size_t i = 0; i < m; ++i) {
			for (size_t j = 0; j < n; ++j) {
				if (matrix[i][j] == 0) {
					row[i] = col[j] = true;
				}
			}
		}
		for (size_t i = 0; i < m; ++i) {
			if (row[i])
				fill(&matrix[i][0], &matrix[i][0] + n, 0);
		}
		for (size_t j = 0; j < n; ++j) {
			if (col[j]) {
				for (size_t i = 0; i < m; ++i) {
					matrix[i][j] = 0;
				}
			}
		}
	}
};

O(1)空间的方法:
思路：用第一行记录每一列（除第一列外）是不是应该置零，
用第一列记录每一行（除第一行外）是不是应该置零
class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        bool first_line = false, first_column = false;
        int height = matrix.size();
        if(!height){
            return;
        }
        int width = matrix[0].size();
		//先判断第一行第一列是否应置零
        for(int i=0; i<width; i++){
            if(!matrix[0][i]){
                first_line = true;
                break;
            }
        }
        for(int i=0; i<height; i++){
            if(!matrix[i][0]){
                first_column = true;
                break;
            }
        }
		//跟方法一差不多，只是结果记录地方不同
        for(int i=1; i<height; i++){
            for(int j=1; j<width; j++){
                if(!matrix[i][j]){
                    matrix[i][0] = matrix[0][j] = 0;
                }
            }
        }
		//下面开始置零
        for(int i=1; i<height; i++){            
            for(int j=1; j<width; j++){
				if(!matrix[i][0] || !matrix[0][j])
                matrix[i][j] = 0;
            }
        }
        
        if(first_line){
            for(int j=0; j<width; j++){
                matrix[0][j] = 0;
            }
        }
        if(first_column){
            for(int i=0; i<height; i++){
                matrix[i][0] = 0;
            }
        }
        return;
    }
};
--------------end--------------

------------Simplify Path.cpp------------111
//思路其实很简单，就是去找/之间的有效路径，并把有效路径放到vector或者队列中
//显然这里vector就够了
//怎么样找有效路径呢，其实就是找两个/之间的字符串，有几种情况：
//1.中间的字符串为.或者空（出现了连续的/）则直接忽略
//2.中间的字符串为..，则抵消掉上一段路径（要检查有木有上一个路径）
//3.其他字符串一律认为是正常的，加入到vector
//统计完所有路径之后，输出即可，注意如果路径为空则输出根目录/
class Solution {
public:
    string simplifyPath(string path) {
        vector<string> dirs;
        string dir;
        
        for(auto it = path.begin(); it != path.end(); ) {
			//这句要是放到循环里面就会runtime error, 
			//因为it如果是end()了(it = jt)，++会出错
			++it; 
            auto jt = find(it, path.end(), '/'); //从it到end找'/'
            dir = string(it, jt); //用iterator构造string
            if(!dir.empty() && dir != "."){
                if(dir == ".."){
                    if(!dirs.empty()) {
                        dirs.pop_back();
                    }
                }
                else{
                    dirs.push_back(dir);
                }
            }
            it = jt;
        }
        
        string res = "";
        if(dirs.empty()) return "/";
        else{
            for(int i=0; i<dirs.size(); i++){
                res = res+"/"+dirs[i];
            }
        }
        return res;
    }
};
--------------end--------------

------------Single Number II.cpp------------112
//这题跪了, 下面列出2个方法, 第一个方法好写好记, 两个方法没有数量级上的差别
//第一个方法：
//创建一个长度为sizeof(int) 的数组count[sizeof(int)]，count[i] 表示所有元
//素的1 在i 位出现的次数。如果count[i] 是3 的整数倍，则忽略；
//否则就把该位取出来组成答案。
class Solution {
public:
	int singleNumber(int A[], int n) {
		const int W = sizeof(int) * 8; // 整数字长
		int count[W]; // 每个位上1 出现的次数
		fill_n(&count[0], W, 0);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < W; j++) {
				count[j] += (A[i] >> j) & 1;
				count[j] %= 3;
			}
		}
		int result = 0;
		for (int i = 0; i < W; i++) 
		    if(count[i]) result += (1 << i);
		return result;
	}
};

//方法2：用ones 记录到当前处理的元素为止，二进制1 出现“1 次”（mod 3 之后的1）的
//有哪些二进制位；用twos 记录到当前计算的变量为止，二进制1 出现“2 次”（mod 3 之后的2）
//的有哪些二进制位。当ones 和twos 中的某一位同时为1 时表示该二进制位上1 出现了3 次，
//此时需要清零。即用二进制模拟三进制运算。最终ones 记录的是最终结果。
class Solution {
public:
    int singleNumber(int A[], int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int twos = 0, ones = 0, xthrees;
        for(int i=0; i<n; i++){
            twos |= ones&A[i];
            ones ^= A[i];
            xthrees = ~(ones & twos);
            ones &= xthrees;
            twos &= xthrees;
        }
        return ones;
    }
};
--------------end--------------

------------Single Number.cpp------------113
First Try:
//using exclusive or to remove all bits which appear even times.
class Solution {
public:
   int singleNumber(int A[], int n) {
	// Note: The Solution object is instantiated only once and is reused by each test case.
	   int res = 0;
	   for(int i=0; i<n; i++){
		   res ^= A[i];
	   }
	   return res;
   }
};

Second Try:
//using exclusive or to remove all bits which appear even times.
//totally without extra space
class Solution {
public:
   int singleNumber(int A[], int n) {
	// Note: The Solution object is instantiated only once and is reused by each test case.
	   for(int i=1; i<n; i++){
		   A[0] ^= A[i];
	   }
	   return A[0];
   }
};
--------------end--------------

------------Sort Color.cpp------------114
//这一题有非常多的解题办法
1. 利用STL multiset的自动排序, 但是要用到线性空间复杂度, 时间复杂度是红黑树的O(nlogn)
不过题目有说不要用stl的sort, 这样算作弊吧
class Solution {
public:
    void sortColors(int A[], int n) {
        multiset<int> m;
        int i;
        for(i=0; i<n; i++) {
            m.insert(A[i]);
        }
        i=0;
        for(multiset<int>::iterator it = m.begin(); i<n; i++, it++) {
            A[i] = *it;
        }
    }
};

2. 计数排序
因为范围已知，而且范围巨小，所以计数排序也可以，不过要计数要扫描一次，输出的时候还要扫描一次
class Solution {
public:
	void sortColors(int A[], int n) {
		const int COLORNUM = 3;
		int counts[COLORNUM] = { 0 }; // 记录每个颜色出现的次数
		for (int i = 0; i < n; i++)
			counts[A[i]]++;
		for (int i = 0, index = 0; i < COLORNUM; i++)
			for (int j = 0; j < counts[i]; j++)
				A[index++] = i;
	}
};

3. 双指针
左边的指针red跟踪red，右边的指针blue跟踪blue
用cur指针从左边向右边扫描，如果碰到red就换到左边，如果碰到blue就换到右边
如果即不是red也不是blue，cur就往后移动
class Solution {
public:
    void sortColors(int A[], int n) {
        int red =0, blue = n-1, cur = 0;        
        while(cur<=blue){
            if(A[cur] == 0)
				swap(A[cur++],A[red++]); 
            else if(A[cur] == 2){
                swap(A[cur], A[blue--]);
            }
            else cur++;
        }
    }
};

4.用patition函数 equal_to函数和bind1st or bind2nd
class Solution {
public:
    void sortColors(int A[], int n) {
        partition(partition(A, A + n, bind1st(equal_to<int>(), 0)), A + n,
                    bind1st(equal_to<int>(), 1));
    }
};

or

class Solution {
public:
    void sortColors(int A[], int n) {
        partition(partition(A, A + n, bind2nd(equal_to<int>(), 0)), A + n,
                    bind2nd(equal_to<int>(), 1));
    }
};

5. 重新实现partition(), 这里C++11的patition使用的是前向迭代器, 而C++98使用的是双向迭代器
ForwardIterator是前向迭代器模板，pred是函数模板，Unary是指只接受一个参数，predicate是指
这个函数是用来预测的，返回bool类型，可以看出，patition的作用是凡是pred返回true的元素一律
交换到容器前半部分，返回的位置是后半部分的第一个元素，而不是前半部分的最后一个元素
class Solution {
public:
	void sortColors(int A[], int n) {
		partition(partition(A, A + n, bind1st(equal_to<int>(), 0)), A + n,
		bind1st(equal_to<int>(), 1));
	}
	private:
	template<typename ForwardIterator, typename UnaryPredicate>
	ForwardIterator partition(ForwardIterator first, ForwardIterator last,UnaryPredicate pred){
		auto pos = first;
		for (; first != last; ++first)
			if (pred(*first))
				swap(*first, *pos++);
		return pos;
	}
};
--------------end--------------

------------Sort List.cpp------------115
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/*
思路：DFS+归并
DFS复杂度是O(log n)
归并是O(n)
*/
class Solution {
public:
    ListNode *sortList(ListNode *head) {
        int size = 0;
        ListNode *ptr = head;
        //get the size of this list
        while(ptr) {
            size++;
            ptr = ptr->next;
        }
        
        //if the list contains only 0 or 1 node, then return the list
        if(size <= 1) {
            return head;
        }
        //分拆链表
        int half_size = size>>1;
        ListNode *ptr1 = head, *ptr2;
        for(int i=0; i<half_size; i++) {
			ptr2 = ptr1->next;
			if(i < half_size-1) ptr1 = ptr1->next;
        }
        ptr1->next = NULL;
        ptr1 = head;
        
		//对左右两个子链表排序
        ptr1 = sortList(ptr1);
        ptr2 = sortList(ptr2);
        
		//归并两个已经排好序的链表
        ptr = NULL;
        while(ptr1 && ptr2) {
            if(ptr1->val < ptr2->val){
                if(!ptr) {
                    head = ptr = ptr1;
                    ptr1 = ptr1->next;
                }
                else {
                    ptr->next = ptr1;
                    ptr = ptr->next;
                    ptr1 = ptr1->next;
                }
            }
            else {
                if(!ptr){
                    head = ptr = ptr2;
                    ptr2 = ptr2->next;
                }
                else{
                    ptr->next = ptr2;
                    ptr = ptr->next;
                    ptr2 = ptr2->next;
                }
            }
        }
        
        if(!ptr1){
            ptr->next = ptr2;
        }
        if(!ptr2){
            ptr->next = ptr1;
        }
        
        return head;
    }
};
--------------end--------------

------------Spiral Matrix II.cpp------------116
/*
用dir代表方向，0是往右，1是往下，2是往左，3是往上
*/
class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        int nSquare = n*n, num = 0, dir = 0;
        int pos_x = 0, pos_y = 0;
        vector<vector<int> > v_ret(n,vector<int>(n));
        while(num++ < nSquare){
            v_ret[pos_x][pos_y] = num;
			if(dir == 0) {
				pos_y++;
                if(pos_y >= n-1 || v_ret[pos_x][pos_y+1]) dir++;
			}
			else if(dir == 1) {
				pos_x++;
                if(pos_x >= n-1 || v_ret[pos_x+1][pos_y]) dir++;
			}
			else if(dir == 2) {
				pos_y--;
                if(pos_y <= 0 || v_ret[pos_x][pos_y-1]) dir++;
			}
			else if(dir == 3) {
				pos_x--;
                if(pos_x <= 0 || v_ret[pos_x-1][pos_y]) dir = 0;
			}
		}
        return v_ret;
    }
};
--------------end--------------

------------Spiral Matrix.cpp------------117
//把打印分为四部分：从左到右 从上到下 从右到左 从下到上
//设置上下左右的边界，每次更新边界，并判断是否终止打印
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        vector<int> res;
        if(matrix.empty()) {
            return res;
        }
        int beginY = 0, endY = matrix.size()-1;
        int beginX = 0, endX = matrix[0].size()-1;
        while(true) {
            //from left to right
            for(int i=beginX; i<=endX; ++i) res.push_back(matrix[beginY][i]);
            if(++beginY > endY) break;
            //from up to down
            for(int i=beginY; i<=endY; ++i) res.push_back(matrix[i][endX]);
            if(--endX < beginX) break;
            //from right to left
            for(int i=endX; i>=beginX; --i) res.push_back(matrix[endY][i]);
            if(--endY < beginY) break;
            //from down to up
            for(int i=endY; i>=beginY; --i) res.push_back(matrix[i][beginX]);
            if(++beginX > endX) break;
        }
        return res;
    }
};
--------------end--------------

------------Sqrt(x).cpp------------118
//算法思想为二分法查找
//最后那步稍微修正下, 比如2的根号，应该是1
class Solution {
public:
    int sqrt(int x) {
        if(x < 2) return x;
        int smaller=0, biger=x; 
        int root;
        while(biger >= smaller){
            root = ((biger+smaller)>>1);
            if(root > x/root) biger = root-1;
            else if(root < x/root) smaller = root+1;
            else return root;
        }
        return root*root>x? root-1:root;
    }
};
--------------end--------------

------------String to Integer.cpp------------119
//纯细节题
class Solution {
public:
    int atoi(const char *str) {
        int len = strlen(str), i = 0;
        long long value = 0;
        bool b_negative = false;
		//先把前导空格都去掉
        while(str[i] == ' ') i++;
		//再判断第一个字符是不是符号
        if(str[i] == '-' || str[i] == '+'){
            if(str[i] == '-') {
                b_negative = true;
            }
            i++;
        }
		//把前导0都去掉
        while(str[i] == '0') i++;
		//对每个字符循环，遇到非数字就结束
        for(; i<len; i++){
            if(str[i] < '0' || str[i] > '9'){
                break;
            }
            value = value*10+str[i]-'0';
			//判断是否溢出
            if(value > INT_MAX){
                return b_negative? INT_MIN : INT_MAX;
            }
        }
		//如果是负2147483648则返回-2147483648
        if(b_negative && (value == 2147483648)) return INT_MIN;
		//否则根据符号返回
        return b_negative? 0-value:value;
    }
};
--------------end--------------

------------Subsets II.cpp------------120
/*
用STL的prev_permutation的解法
*/
class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        int len = S.size();
        int cur;
		vector<int> v_judge(len, 0);
        vector<int> v;
        vector<vector<int> > v_res;
		//先push一个空集合，因为即使S是空集合，那么v_res也至少应该包含一个空集合
        v_res.push_back(v);  
        sort(S.begin(), S.end()); //对S排序，保证结果有序
        for(int i=1; i<=len; i++){
			fill_n(v_judge.begin(), i, 1); //初始化v_judge
            do{
                for(int j=0; j<len; j++){
                    if(v_judge[j]){
                        v.push_back(S[j]);
                    }
                }
				v_res.push_back(v);
				v.clear();  
            } while(prev_permutation(v_judge.begin(), v_judge.end()));
			//prev_permutation如果还有上一个，会返回true
        }
		//下面是去重的代码
        sort( v_res.begin(), v_res.end() ); 
		//unique把重复元素都放到最后，返回分界处的地址
        v_res.erase( unique( v_res.begin(), v_res.end() ), v_res.end() );
        return v_res;
    }
};

/*
用位运算实现的nextPermutation的解法
*/
class Solution {
public:
    int nextPermutation( int n, int cur){
        int b = cur&(-cur);
        int t = cur+b;
        int res = (((t^cur)>>2)/b)|t;
        if(res >= (1<<n)) return 0;
        else return res;
    }
    vector<vector< int> > subsetsWithDup(vector< int> &S) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int len = S.size();
        int cur;
        vector< int> v;
        vector<vector< int> > v_res;
        v_res.push_back(v);  //先push一个空的
        sort(S.begin(), S.end());
        for( int i=1; i<=len; i++){
            cur = (1<<i)-1; //第一个组合
            do{
                for( int j=0; j<len; j++){
                    if(cur&(0x1<<j)){
                        v.push_back(S[j]);
                    }
                }
                v_res.push_back(v);
                v.clear(); 
            } while(cur = nextPermutation(len, cur));
        }
        sort( v_res.begin(), v_res.end() );
        v_res.erase( unique( v_res.begin(), v_res.end() ), v_res.end() );
        return v_res;
    }
};
--------------end--------------

------------Subsets.cpp------------121
/*
用STL的prev_permutation的解法
*/
class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        int len = S.size();
        int cur;
		vector<int> v_judge(len, 0);
        vector<int> v;
        vector<vector<int> > v_res;
		//先push一个空集合，因为即使S是空集合，那么v_res也至少应该包含一个空集合
        v_res.push_back(v);  
        sort(S.begin(), S.end()); //对S排序，保证结果有序
        for(int i=1; i<=len; i++){
			fill_n(v_judge.begin(), i, 1); //初始化v_judge
            do{
                for(int j=0; j<len; j++){
                    if(v_judge[j]){
                        v.push_back(S[j]);
                    }
                }
				v_res.push_back(v);
				v.clear();  
            } while(prev_permutation(v_judge.begin(), v_judge.end()));
			//prev_permutation如果还有上一个，会返回true
        }
        return v_res;
    }
};

/*
用位运算实现的nextPermutation的解法
*/
class Solution {
public:
    int nextPermutation(int n, int cur){
        int b = cur&(-cur);
        int t = cur+b;
        int res = (((t^cur)>>2)/b)|t;
        if(res >= (1<<n)) return 0;
        else return res;
    }
    vector<vector<int> > subsets(vector<int> &S) {
        int len = S.size();
        int cur;
        vector<int> v;
        vector<vector<int> > v_res;
		//先push一个空集合，因为即使S是空集合，那么v_res也至少应该包含一个空集合
        v_res.push_back(v);
        sort(S.begin(), S.end());//对S排序，保证结果有序
        for(int i=1; i<=len; i++){
            cur = (1<<i)-1; //第一个组合
            do{
                for(int j=0; j<len; j++){
                    if(cur&(0x1<<j)){
                        v.push_back(S[j]);
                    }
                }
				v_res.push_back(v);
				v.clear();  
            } while(cur = nextPermutation(len, cur));
        }
        return v_res;
    }
};
--------------end--------------

------------Substring with Concatenation of All Words.cpp------------122
//这题其实不难，题意是S中要出现L中所有单词连在一起的字符串起点（不按顺序）
//所以，这题甚至不需要用DFS或者动规
class Solution {
public:
    vector<int> findSubstring(string S, vector<string> &L) {
        map<string,int> words, cur;  
        vector<int> res; 
        int wordNum = L.size();  
        if(!wordNum) return res;
		int wordLen = L[0].size(); //字典中的单词长度都是一样的
        if(S.size() < wordLen*wordNum) return res; //S长度不够

        for(int i = 0; i < wordNum; i++)  
            words[L[i]]++;  //记录下字典中每个单词出现的个数(因为可能有重)

        for(int i = 0; i <= (int)S.size()-wordLen*wordNum; i++) {  
            cur.clear(); //用来存放当前的查找情况
            int j;  
            for(j = 0; j < wordNum; j++) {  
                string word = S.substr(i+j*wordLen, wordLen);  
                if(words.find(word) == words.end())  //找不到
                    break;  
                cur[word]++;  
                if(cur[word]>words[word]) //某个词出现的次数多了
                    break;  
            }  
            if(j == wordNum)  
                res.push_back(i);  
        }  
        return res; 
    }
}; 
--------------end--------------

------------Sudoku Solver.cpp------------123
class Solution {
private:
    bool isValid(vector<vector<char> > &board, int x, int y){
        char c = board[x][y];
		//判断一列
        for(int i=0; i<9; i++){
            if(x!=i && board[i][y] == c){
                return false;
            }
        }
		//判断一行
        for(int j=0; j<9; j++){
            if(y!=j && board[x][j] == c){
                return false;
            }
        }
		//判断一个小块
        for(int i=(x/3)*3; i<(x/3+1)*3; i++){
            for(int j=(y/3)*3; j<(y/3+1)*3; j++){
                if((i!=x && j!=y) && board[i][j] == board[x][y]){
                    return false;
                }
            }
        }
        return true;
    }
public:
    bool solveSudoku(vector<vector<char> > &board) {
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                if(board[i][j] == '.'){
                    for(int k=1; k<=9; k++){
                        board[i][j] = '0' + k;
                        if(isValid(board, i, j) && solveSudoku(board)){
                            return true;
                        }
                        board[i][j] = '.'; //一定要记得还原现场
                    }
                    return false;
                }
            }
        }
        return true;
    }
};
--------------end--------------

------------Sum Root to Leaf Numbers.cpp------------124
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
采用DFS，递归的时候，传下去当前节点的值
*/
class Solution {
public:
    int sumNumbers(TreeNode *tree, int number){
        int sum = number*10, left=0, right=0;
        sum += tree->val; //得到当前节点的值
        if(tree->left) { //如果左边不为空，递归求解左子树
            left = sumNumbers(tree->left, sum);
        }
        if(tree->right) {//如果右边不为空，递归求解右子树
            right = sumNumbers(tree->right, sum);
        }
        if(!left && !right) { //如果左右都为空，返回当前节点的值
            return sum;
        }
        else {
            return left+right; //否则，返回两边的和
        }
    }
    int sumNumbers(TreeNode *root) {
        if(root == NULL) return 0;
        return sumNumbers(root, 0);
    }
};
--------------end--------------

------------Surrounded Regions.cpp------------125
/*
这题就是把所有被X围住的O换成X，O没有被X全围住的情况就是那一组O连接了边界，
只要把连接了边界的O全部先换成*（或其他字符），然后把剩余的O全部换成*，
最后再把*换回O即可
在把连接了边界的O全部先换成*这一步，用BFS宽搜
*/
class Solution {
public:
    void solve(vector<vector<char>> &board) {
        int height = board.size(), width;
        if(height == 0) return;
        width = board[0].size();
		//以两个竖边上的O为起点进行宽搜替换
        for(int i=0; i<height; i++){
            if(board[i][0] == 'O'){
                bfs(i, 0, board);
            } 
            if(board[i][width-1] == 'O'){
                bfs(i, width-1, board);
            }
        }
        //以上下两个横边上的O为起点进行宽搜替换
        for(int j=1; j<width-1; j++){
            if(board[0][j] == 'O'){
                bfs(0, j, board);
            }
            if(board[height-1][j] == 'O'){
                bfs(height-1, j, board);
            }
        }
        //把O换成X，*换成O
        for(int i=0; i<height; i++){
            for(int j=0; j<width; j++){
                if(board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
                else if(board[i][j] == '*'){
                    board[i][j] = 'O';
                }
            }
        }
    }
private:
    struct position{
        int x;
        int y;
    };
    
    void bfs(int x, int y, vector<vector<char>> &board){
        queue<position> q;
        visit(x, y, board, q); //访问处于边界上的点(起点)
        while(!q.empty()) {
            //从队列取出一个点，并且访问其上下左右四个点
            position cur = q.front(); 
            q.pop();
            visit(cur.x-1, cur.y, board, q);
            visit(cur.x, cur.y-1, board, q);
            visit(cur.x+1, cur.y, board, q);
            visit(cur.x, cur.y+1, board, q);
        }
    }
    //访问坐标为(x,y)的节点，如果是O，则替换成*，并放入队列
    void visit(int x, int y, vector<vector<char>> &board, queue<position> &q){
        if(x<0 || y<0 || x>=board.size() || y>=board[0].size() || board[x][y] == 'X'){
            return;
        }
        if(board[x][y] == 'O'){
            position p;
            p.x = x;
            p.y = y;
            board[x][y] = '*';
            q.push(p);
        }
    }
};
--------------end--------------

------------Swap Nodes in Pairs.cpp------------126
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public :
    ListNode * swap(ListNode *left, ListNode *mid, ListNode *right){
        if(!right) return mid;
        mid->next = right->next;
        right->next = mid;
        if(left) left->next = right;
        if(mid->next){
            swap(mid, mid->next, mid->next->next);
        }
        return right;
    }
	
    ListNode *swapPairs(ListNode *head) {
        ListNode *left, *right;
        if(! head || ! head->next) return head;
        return swap( NULL, head, head->next);
    }
};
--------------end--------------

------------Symmetric Tree.cpp------------127
First Try:
递归版
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
   bool isSymmetric(TreeNode *left, TreeNode *right){
       if(left == NULL && right == NULL){   // empty trees are symmetric 
           return true;
       }
       else if(left == NULL || right == NULL){  // empty and non-empty trees are non-symmetric 
           return false;
       }
	   //judge whether left->left right->right, left->right, right->left are symmetric
       return (left->val == right->val)&&isSymmetric(left->left, right->right)&&isSymmetric(left->right, right->left);
   }
   bool isSymmetric(TreeNode *root) {
       // Note: The Solution object is instantiated only once and is reused by each test case.
       if(root == NULL){    // empty tree is symmetric
           return true;
       }
       return isSymmetric(root->left, root->right);  // whether left and right sub-tree are symmetric
   }
};

Second Try:
迭代版
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
    bool isSymmetric(TreeNode *root) {
        if(root == nullptr) return true;
        stack<TreeNode *> s;
        s.push(root->right); 
        s.push(root->left);
        while(!s.empty()) {
            TreeNode *p = s.top(); s.pop();
            TreeNode *q = s.top(); s.pop();
            if(p == nullptr && q == nullptr) continue;
            if(p == nullptr || q == nullptr) return false;
            if(p->val != q->val) return false;
            s.push(p->left);
            s.push(q->right);
            s.push(p->right);
            s.push(q->left);
        }
        return true;
    }
};
--------------end--------------

------------Text Justification.cpp------------128
class Solution {
public:
	vector<string> fullJustify(vector<string> &words, int L) {
		vector<string> result;
		const int n = words.size();
		int begin = 0, len = 0; // 当前行的起点，当前长度
		for (int i = 0; i < n; ++i) {
			if (len + words[i].size() + (i - begin) > L) {
				result.push_back(connect(words, begin, i - 1, len, L, false));
				begin = i;
				len = 0;
			}
			len += words[i].size();
		}
		// 最后一行不足L
		result.push_back(connect(words, begin, n - 1, len, L, true));
		return result;
	}

	/**
	* @brief 将words[begin, end] 连成一行
	* @param[in] words 单词列表
	* @param[in] begin 开始
	* @param[in] end 结束
	* @param[in] len words[begin, end] 所有单词加起来的长度
	* @param[in] L 题目规定的一行长度
	* @param[in] is_last 是否是最后一行
	* @return 对齐后的当前行
	*/
	string connect(vector<string> &words, int begin, int end, int len, int L, bool is_last) {
		string s;
		int n = end - begin + 1; //待连接的单词个数
		for (int i = 0; i < n; ++i) {
			s += words[begin + i];
			addSpaces(s, i, n - 1, L - len, is_last); //i是间隔索引，n-1是间隔总数
		}
		if (s.size() < L) s.append(L - s.size(), ' ');
		return s;
	}

	/**
	* @brief 添加空格，将L长度的空格尽量均匀的分配到n个间隙当中
	* @param[inout]s 一行
	* @param[in] i 当前空隙的序号
	* @param[in] n 空隙总数
	* @param[in] L 总共需要添加的空额数
	* @param[in] is_last 是否是最后一行
	* @return 无
	*/
	void addSpaces(string &s, int i, int n, int L, bool is_last) {
		if (n < 1 || i > n - 1) return;
		//i < (L % n) ? 1 : 0 这个太巧妙了
		int spaces = is_last ? 1 : (L / n + (i < (L % n) ? 1 : 0));
		s.append(spaces, ' ');
	}
};
--------------end--------------

------------Trapping Rain Water.cpp------------129
/*
两种解法：
对于每个柱子，找到其左右两边最高的柱子，该柱子能容纳的水就是
min(max_left,max_right) - height。所以，
1. 从左往右扫描一遍，对于每个柱子，求取左边最大值；
2. 从右往左扫描一遍，对于每个柱子，求最大右值；
3. 再扫描一遍，把每个柱子能容纳的水累加起来就行了
也可以，
1. 扫描一遍，找到最高的柱子，这个柱子将数组分为两半；
2. 处理左边一半；
3. 处理右边一半。
*/
class Solution {
public:
    int trap(int A[], int n) {
        int maxIdx=0, max=A[0], max_bar, rain = 0;
        //获取最长板的位置
        for(int i=1; i<n; i++){
            if(A[i] > max){
                max = A[i];
                maxIdx = i;
            }
        }
        //左侧逼近
        max_bar = A[0];
        for(int i=1; i<maxIdx; i++){
            if(A[i] < max_bar){
                rain += (max_bar - A[i]);
            } 
            else{
                max_bar = A[i];
            }
        }
        //右侧逼近
        max_bar = A[n-1];
        for(int i=n-2; i>maxIdx; i--){
            if(A[i] < max_bar){
                rain += (max_bar - A[i]);
            } 
            else{
                max_bar = A[i];
            }
        }
        return rain;
    }
};
--------------end--------------

------------Triangle.cpp------------130
/*
这个题都做烂了，就是逐层递推，不知道这样的算不算动态规划
*/
class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        int n = triangle.size();
        vector<int> v(n), v_lastrow(n);
		if(n == 0) return 0;
        v[0] = v_lastrow[0] = triangle[0][0];
        for(int i=1; i<n; i++){
            v[0] = triangle[i][0] + v_lastrow[0]; //边上的没得选
            for(int j=1; j<i; j++){
				//选当前节点头顶上的两个节点当中那个小的
                v[j] = triangle[i][j] + min(v_lastrow[j-1],v_lastrow[j]);
            }
            v[i] = triangle[i][i] + v_lastrow[i-1]; //边上的节点
            v_lastrow = v;
        }
		//min_element是stl中的，求一个容器中最小的值，*跟解析指针的用法差不多
        return *min_element(v.begin(), v.end());
    }
};
--------------end--------------

------------Two Sum.cpp------------131
/*两头逼近的方法*/
class Solution {
public:
	int getIndex(vector<int> numbers, int num){
		for(int i=0; i<numbers.size(); i++){
			if(numbers[i] == num)
				return i+1;
		}
	}

	int getIndexRev(vector<int> numbers, int num){
		for(int i=numbers.size()-1; i>=0; i--){
			if(numbers[i] == num)
				return i+1;
		}
	}

    vector<int> twoSum(vector<int> &numbers, int target) {
        int head = 0, tail = numbers.size() - 1;
        int sum;
        vector<int> v;
		vector<int> number_sorted = numbers;
        sort(number_sorted.begin(), number_sorted.end());
        while(head<tail){
            sum = number_sorted[head] + number_sorted[tail];
            if(target == sum){
				head = getIndex(numbers, number_sorted[head]);
				tail = getIndexRev(numbers, number_sorted[tail]);
                v.push_back(head>tail?tail:head);
                v.push_back(head>tail?head:tail);
                return v;
            }
            if(sum < target) head++;
            else tail--;
        }
        return v;
    }
};
--------------end--------------

------------Unique Binary Search Trees II.cpp------------132
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
--------------end--------------

------------Unique Binary Search Trees.cpp------------133
//动态规划
//左右子树数相乘
class Solution {
public :
    int numTrees( int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        vector<int> v(n+1,0);
        if(!n) return 0;
        v[0] = 1;
        for(int i=1; i<=n; i++){
			//左子树节点个数从0到i-1
            for(int j=0; j<i; j++){
                v[i] += v[j]*v[i-j-1];
            }
        }
        return v[n];
    }
};

--------------end--------------

------------Unique Paths II.cpp------------134
//动态规划
//如果一行出现了障碍物，要把障碍物处置为0，后面的位置计算方法类似
//对第一行第一列单独处理了
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        int height = obstacleGrid.size();
        if(!height){
            return 0;
        }
        int width = obstacleGrid[0].size(), valid = 1;
        vector<int> pathNum;
        if(obstacleGrid[0][0] || obstacleGrid[height-1][width-1]) return 0;
        for(int i=0; i<width; i++){ //处理第一行,只要出现障碍物后面全为0
            if(obstacleGrid[0][i]){
                valid = 0;
            }
            pathNum.push_back(valid);
        }
        valid = 1;
        for(int i=1; i<height; i++){
            if(obstacleGrid[i][0]) valid = 0;
            pathNum[0] = valid;
            for(int j=1; j<width; j++){
                if(obstacleGrid[i][j]) pathNum[j] = 0;
                else pathNum[j] = pathNum[j] + pathNum[j-1];
            }
        }
        return pathNum[width-1];
    }
};
--------------end--------------

------------Unique Paths.cpp------------135
My solution:
//动态规划+滚动数组
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> v(n, 1);
        for(int i=1; i<m; i++){
            for(int j=1; j<n; j++){
                v[j] = v[j] + v[j-1];
            }
        }
        return v[n-1];
    }
};

//DFS
//思路就是，m n这个方格可能是从m-1 n过来的，也可能是从m n-1过来的
class Solution {
public:
	int uniquePaths(int m, int n) {
		if (m < 1 || n < 1) return 0; // 终止条件
		if (m == 1 && n == 1) return 1; // 收敛条件
		return uniquePaths(m - 1, n) + uniquePaths(m, n - 1);
	}
};

//所谓的备忘录法，其实这个方法以前也用过，只是不知道叫这个名字
class Solution {
public:
	int uniquePaths(int m, int n) {
		// 0 行和0 列未使用
		this->f = vector<vector<int> >(m + 1, vector<int>(n + 1, 0));
		return dfs(m, n);
	}
private:
	vector<vector<int> > f; // 缓存
	int dfs(int x, int y) {
		if (x < 1 || y < 1) return 0; // 数据非法，终止条件
		if (x == 1 && y == 1) return 1; // 回到起点，收敛条件
		return getOrUpdate(x - 1, y) + getOrUpdate(x, y - 1);
	}
	//这个函数的作用就是看能不能查表得到，查表没有的才递归
	int getOrUpdate(int x, int y) {
		if (f[x][y] > 0) return f[x][y];
		else return f[x][y] = dfs(x, y);
	}
};
--------------end--------------

------------Valid Number.cpp------------136
//细节题，主要是一些特殊情况 像.和e的位置摆放
class Solution {
public:
    bool isNumber(const char *s) {
        int len, i;
        bool NoPoint = true;
        bool NoE = true;
        bool numeric = false;
        while(s && s[0] == ' ') s++; //去掉前面的空格
        if(s && (s[0] == '+' || s[0] == '-')) s++; //如果有符号位则去掉
        i = len = strlen(s);
        while(s[--i] == ' ') len--; //去掉后面的空格
        if(len <= 0 || s[0] == 'E' || s[0] == 'e') return false; //这些情况统统返回false
        if(len == 1 && s[0] == '.') return false; //数里面包含点是可以的,但是不能只有一个点
        for(i=0; i<len; i++){
            if(s[i] == '.'){ //发现了点要确保出现一个点
                if(NoPoint) {
                    NoPoint = false;
                    continue;
                }
                else return false;
            }
            if((s[i] == 'E' || s[i] == 'e')) {
                if(NoE && numeric) {
                    NoE = false;
                    NoPoint = false; //出现e之后就不能再出现.了
                    if(s[i+1] == '+' || s[i+1] == '-') i++;
                    if(i+1 >= len) return false;
                    continue;
                }
                return false;
            }
            if(s[i] < 48 || s[i] > 57) return false;
            else numeric = true;
        }
        return true;
    }
};

//偷懒的做法
class Solution {
public:
	bool isNumber (char const* s) {
		char* endptr;
		strtod (s, &endptr);
		if (endptr == s) return false; //"  "
		for (; *endptr; ++endptr)
			if (!isspace (*endptr)) return false;
		return true;
	}
};
--------------end--------------

------------Valid Palindrome.cpp------------137
My solution:
双指针的思想真是无处不在啊，两头往中间遍历貌似可以ko掉很多题
不过这一题比USACO上的类似的一道题简单
class Solution {
public:
    bool isPalindrome(string s) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int len = s.length();
        bool isPalin = true;
        int head = 0, tail = len-1;
        if(!len){
            return true;
        }
        while(head<tail){
            if(!(isalpha(s[head]) || isdigit(s[head]))){
                head++;
                continue;
            }
            if(!(isalpha(s[tail]) || isdigit(s[tail]))){
                tail--;
                continue;
            }
            if(s[head] != s[tail] && abs(s[head]-s[tail]) != 32){
                return false;
            }
            head++;
            tail--;
        }
        return isPalin;
    }
};

纯STL实现方法
isalnum用来判断是否字母和数字，prev返回迭代器前的位置，tolower转换小写字母
class Solution {
public:
	bool isPalindrome(string s) {
		transform(s.begin(), s.end(), s.begin(), ::tolower);
		auto left = s.begin(), right = prev(s.end());
		while (left < right) {
			if (!::isalnum(*left)) ++left;
			else if (!::isalnum(*right)) --right;
			else if (*left++ != *right--) return false;
		}
		return true;
	}
};
--------------end--------------

------------Valid Parentheses.cpp------------138
/*
弄一个栈（vector模拟），把遇到的左括号入栈，
遇到右括号就把对应的左括号出栈，最后看栈为不为空即可
*/
class Solution {
public:
    bool isValid(string s) {
        vector<char> v;
        int len = s.length();
        if(len == 0) return true;
        for(int i=0; i<s.length(); i++) {
            int diff = 0; 
            if(v.size()) {
                diff = s[i] - v[v.size()-1];
            }
			//因为左右括号之间的差不大于3（看ASCII码表）
            if(diff > 0 && diff < 3) {
                v.pop_back(); //如果是对应的右括号，左括号出栈
            }
            else {
                v.push_back(s[i]); //否则，入栈
            }
        }
		return v.size() == 0;
    }
};
--------------end--------------

------------Valid Sudoku.cpp------------139
/*
第一种解法：
对每个放置的元素检查横竖框
*/
class Solution {
public:
    bool isValid(vector<vector<char> > &board, int x, int y, int len){
        char c = board[x][y];
        if(c == '.'){
            return true;
        }
        for(int i=0; i<len; i++){
            if(x!=i && board[i][y] == c){
                return false;
            }
        }
        for(int j=0; j<len; j++){
            if(y!=j && board[x][j] == c){
                return false;
            }
        }
        for(int i=(x/3)*3; i<(x/3+1)*3; i++){
            for(int j=(y/3)*3; j<(y/3+1)*3; j++){
                if((i!=x && j!=y) && board[i][j] == board[x][y]){
                    return false;
                }
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char> > &board) {
        int len = board.size();
        for(int i=0; i<len; i++){
            for(int j=0; j<len; j++){
                if(!isValid(board, i, j, len)){
                    return false;
                }
            }
        }
        return true;
    }
};

/*
第二种解法：
对每个横竖框检查里面的元素，显然这种方法效率高
*/
class Solution {
public:
	bool isValidSudoku(vector<vector<char>>& board) {
		bool used[9];
		for (int i = 0; i < 9; ++i) {
		fill(used, used + 9, false); 
		for (int j = 0; j < 9; ++j) // 检查行
			if (!check(board[i][j], used))
				return false;
		fill(used, used + 9, false);
		for (int j = 0; j < 9; ++j) // 检查列
			if (!check(board[j][i], used))
				return false;
		}
		for (int r = 0; r < 3; ++r) // 检查9 个子格子
		for (int c = 0; c < 3; ++c) {
			fill(used, used + 9, false);
			for (int i = r * 3; i < r * 3 + 3; ++i)
			for (int j = c * 3; j < c * 3 + 3; ++j)
			if (!check(board[i][j], used))
			return false;
		}
		return true;
	}
	
	//检查横竖或框中的一个位置，顺便把已经出现过的数字标记下
	bool check(char ch, bool used[9]) {
		if (ch == '.') return true;
		if (used[ch - '1']) return false;
		used[ch - '1'] = true;
		return true;
	}
};
--------------end--------------

------------Validate Binary Search Tree.cpp------------140
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
第一种解法，对Tree进行中序遍历，结果放到vector，然后判断vector是不是升序
*/
class Solution {
private:
    vector<int> v;
public:
	//中序遍历
    void help(TreeNode *root){
        if(root->left){
            help(root->left);
        }
        v.push_back(root->val);
        if(root->right){
            help(root->right);
        }
    }
    bool isValidBST(TreeNode *root) {
        if(!root){
            return true;
        }
        v.clear();
        help(root);
        int len = v.size();
        for(int i=0; i<len-1; i++){
            if(v[i]>=v[i+1]){
                return false;
            }
        }
        return true;
    }
};

/*
更好一些的方法：注意递归的参数，lower和upper的设置异常巧妙
根节点的值作为lower传下去，会被当做右子树每个节点比较的对象
而根节点的值作为upper传下去，会当做左子树每个节点比较的对象
我之前犯的错误就是子节点跟其直接父节点比较，那就不满足BST的定义了
*/
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return isValidBST(root, INT_MIN, INT_MAX);
    }
    bool isValidBST(TreeNode* root, int lower, int upper) {
        if (root == nullptr) return true;
        return root->val > lower && root->val < upper
                && isValidBST(root->left, lower, root->val)
                && isValidBST(root->right, root->val, upper);
    }
};
--------------end--------------

------------Wildcard Matching.cpp------------141
//迭代版
/*迭代版比较有技巧，
整个框架是个对s的大循环，一直循环到s的结尾，循环中
首先，最简单情况是如果*p为？，则s和p都往后移动一个字符，这是确定的
然后，如果p等于*，先去掉重复的*，p指向*后的位置，用一个指针记住*的位置，
	  另一个指针指向当前s的位置
最后，如果p不等于*，若*p等于*s，则同时往后移动一个字符，
	  否则，若之前出现过*，就让*多匹配掉一个字符，否则返回false
	  在这里，刚才记录的指针就要用上了，p仍然指向*后的位置，s往后移动一个字符
*/

class Solution {
public:
    bool isMatch(const char *s, const char *p) {  
        bool star = false;  
        const char* starPtr = NULL;  
        const char* starDelPtr = NULL;  
        while(*s != '\0') {  
            if(*p == '?') s++, p++;
			else if(*p == '*') {
				star = true;    //说明出现了*
                while(*p == '*') p++;  //去掉重复的*,p指向*后的位置
                starPtr = p-1;  //指向p最后一个*
                starDelPtr = s; //指向被*抵消掉n(0,1..)个字符后的位置
            }  
			else  {
                if(*s == *p) s++, p++;  
                else if(star == true){  
                    //如果字符不相等,而且p之前出现了*
                    //则让p的*多抵消掉一个字符再进行后续匹配
                    //p指向上个*的位置之后,s指向多抵消一个字符之后的位置
                    s = ++starDelPtr, p = starPtr+1;
                }
                else return false;  //如果没有出现*  
            }  
        }  
        while(*p == '*') p++; //去掉拖尾的所有*
        return *p == '\0';  
    }  
};

//递归版 会超时
/*
递归版的思路比迭代版清晰：
首先，若p或s为\0，则p和s必须都为\0才能匹配，否则失配
其次，若p不为*，则要么*p等于*s，要么*p等于?，否则当前字符就失配，
	  若当前字符匹配，其结果就依赖于后面字符串是否匹配
最后，若p等于*，则先排除多余的连续*，因为连续的*跟一个*是等价的，
      然后看*之后是否还有其他字符，若没有了，则一定匹配，
	  因为*可以代替任意的字符串。
	  若*之后，还存在其他字符，则看s的当前字符是否为\0，若不为\0，
	  则是否匹配依赖于s剩余的字符串与p出现*之后的字符串是否匹配，由于*可以匹配
	  0个到多个字符，所以需要对s循环检测是否匹配p出现*之后的字符串
*/
	  
class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        if(*p == '\0' || *s == '\0') return *p == *s;
		else if(*p == *s || *p == '?') {
            return isMatch(++s, ++p);
        }
		else if(*p == '*') {
            while(*p == '*') ++p;
            if(*p == '\0') return true;
            while(*s++ != '\0') {
                if(isMatch(s, p)) 
                    return true;
            }
        }
        return false;
    }
};
--------------end--------------

------------Word Break II.cpp------------142
class Solution {
public:
	//跟word break区别：用prev记录下哪些位置可以分词出来
	vector<string> wordBreak(string s, unordered_set<string> &dict) {
		// 长度为n 的字符串有n+1 个隔板
		vector<bool> f(s.length() + 1, false);
		// prev[i][j] 为true，表示s[j, i) 是一个合法单词，可以从j 处切开
		// 第一行未用
		vector<vector<bool> > prev(s.length() + 1, vector<bool>(s.length()));
		/*DP, 设状态为f(i)，表示字符串s从第0个到第i个字符之前那个位置是否可以分词，
		状态转移方程为：
		f(i) = any_of(f(j)&&s[j, i) 在 dict 中); 0 <= j < i
		*/
		f[0] = true; // 空字符串
		for (size_t i = 1; i <= s.length(); ++i) { //从第一个分隔到尾后元素
			for (int j = i - 1; j >= 0; --j) {
				if (f[j] && dict.find(s.substr(j, i - j)) != dict.end()) {
					f[i] = true; //发现第i个位置前能分词仍然要试探其他的位置
					prev[i][j] = true; //从j到i前的位置是一个dict中的单词
				}
			}
		}
		vector<string> result;
		vector<string> path;
		gen_path(s, prev, s.length(), path, result);
		return result;
	}
private:
	// DFS 遍历树，生成路径
	void gen_path(const string &s, const vector<vector<bool> > &prev,
		int cur, vector<string> &path, vector<string> &result) {
		if (cur == 0) {
			string tmp;
			//push的时候是逆序的，现在再逆过来
			for (auto iter = path.crbegin(); iter != path.crend(); ++iter){
				tmp += *iter + " ";
			}
			tmp.erase(tmp.end() - 1);
			result.push_back(tmp);
		}
		for (size_t i = 0; i < s.size(); ++i) {
			if (prev[i][cur]) { //如果从s[cur, i)是一个dict中的单词
				path.push_back(s.substr(i, cur - i)); //把该单词入栈
				gen_path(s, prev, i, path, result); //对字符串剩余部分递归
				path.pop_back(); //还原现场
			}
		}
	}
};
--------------end--------------

------------Word Break.cpp------------143
//DFS解法+备忘录
class Solution {
private:
    map<int, bool> m;
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        int len = s.length();
		//看看s本身在不在dict里面
        if(dict.find(s) != dict.end()) return true;
        
		//对每个位置尝试进行分割
        for(int i=1; i<len; i++) {
            if(dict.find(s.substr(0,i)) != dict.end()) { //如果某位置之前的子串在dict中，则判断剩余的是否能划分 
                if(!m[i] && wordBreak(s.substr(i,len-i), dict)) {
                    return true;
                }
                else {
                    m[i] = true; //用备忘录记录下，这个位置就不必重复检验了
                }
            }
        }
        return false;
    }
};

//DP解法
/*设状态为f(i)，表示s[0,i] 是否可以分词，则状态转移方程为
f(i) = any_of(f(j)&&s[j + 1, i] 在 dict 中); 0 <= j < i
*/
class Solution {
public:
	bool wordBreak(string s, unordered_set<string> &dict) {
		// 长度为n 的字符串有n+1 个隔板
		vector<bool> f(s.size() + 1, false);
		f[0] = true; // 空字符串
		for (int i = 1; i <= s.size(); ++i) {
			for (int j = i - 1; j >= 0; --j) {
				if (f[j] && dict.find(s.substr(j, i - j)) != dict.end()) {
					f[i] = true; 
					break; //发现第i个位置前能分词就可以不用搜索其他的j了
				}
			}
		}
		return f[s.size()];
	}
};
--------------end--------------

------------word ladder II.cpp------------144
/*
这一题跟work ladder的区别是需要用一个map记录ladder的路径
这个map设置的很巧妙，key是string代表当前节点，
value是一个vector<string>用来记录从哪些节点可以到当前节点

*/
class Solution {
	public:
	vector<vector<string> > findLadders(string start, string end,
		const unordered_set<string> &dict) {
		unordered_set<string> visited; // 判重
		unordered_map<string, vector<string> > father; // 树
		unordered_set<string> current, next; // 当前层，下一层，用集合是为了去重
		bool found = false;
		current.insert(start);
		while (!current.empty() && !found) {
			// 先将本层全部置为已访问，防止同层之间互相指向
			for (auto word : current)
				visited.insert(word); 
			for (auto word : current) { //对当前层每个单词遍历
				for (size_t i = 0; i < word.size(); ++i) {
					string new_word = word;
					//替换字符，构造新字符串，判断是否在dict中
					for (char c = 'a'; c <= 'z'; ++c) {
						if (c == new_word[i]) continue;
						swap(c, new_word[i]);
						if (new_word == end) {
							found = true; //找到了, 不需要放到next队列了
							father[new_word].push_back(word);
							break;
						}
						if (visited.count(new_word) == 0
						&& (dict.count(new_word) > 0 || new_word == end)) {
							next.insert(new_word);
							father[new_word].push_back(word);
						}
						swap(c, new_word[i]); // restore
					}
				}
			}
			current.clear();
			swap(current, next);
		}
		vector<vector<string> > result;
		if (found) {
			vector<string> path;
			buildPath(father, path, start, end, result);
		}
		return result;
	}
	private:
	//用father构建路径
	//param: father保存每个节点的父节点队列，path是
	//result用来保存最终结果(从start到end的路径)，
	void buildPath(unordered_map<string, vector<string> > &father, vector<string> &path,
			 const string &start, const string &word, vector<vector<string> > &result )
	{
		path.push_back(word);
		if (word == start) {
			result.push_back(path); //结果放到result最后
			//结果是反的，所以要逆序
			reverse(result.back().begin(), result.back().end());
		} 
		else {
			for (auto f : father[word]) { //把节点的每个father推入队列
				buildPath(father, path, start, f, result);
			}
		}
		path.pop_back();
	}
};
--------------end--------------

------------word ladder.cpp------------145
/*
不要去对每个单词查词典里是否有距离为1的单词
而是要去查与该单词距离为1的单词是否在词典中

经典BFS，current是当前层队列，next是下一层队列
稍微修改了写法，感觉比戴方勤版的好理解一点点
*/
class Solution {
public:
int ladderLength(string start, string end,
	const unordered_set<string> &dict) {
		if (start.size() != end.size()) return 0;
		if (start.empty() || end.empty()) return 0;
		queue<string> current, next; // 当前层，下一层
		unordered_set<string> visited; // 判重
		int level = 0; // 层次
		bool found = false;
		current.push(start);
		while (true) { //不断对每层遍历
			++level;
			while (!current.empty() && !found) { //对当前队列的所有单词遍历
				const string str(current.front()); //取出队列头
				current.pop();
				for (size_t i = 0; i < str.size(); ++i) {
					string new_word(str);
					//通过改变一个字符，得到一个新的字符串
					for (char c = 'a'; c <= 'z'; c++) {
						if (c == new_word[i]) continue;
						swap(c, new_word[i]); //交换一个不同的字符
						if (new_word == end) {
							found = true; //找到了
							break;
						}
						if (dict.count(new_word) > 0 //如果字典里有这个单词
							&& !visited.count(new_word)) { //而且这个单词之前没访问过
							next.push(new_word); //把该单词push到next队列
							visited.insert(new_word); //标记为访问过
						}
						swap(c, new_word[i]); // 恢复该单词
					}
				}
			}
			if(!next.empty() && !found)
				swap(next, current); //!!! 交换两个队列
			else break;
		}
		if (found) return level+1;
		else return 0;
	}
};

--------------end--------------

------------Word Search.cpp------------146
//思路：不知道搜索起点？以每个点为起点搜索，反正很快会剪枝的
//这里用的其实就是备忘录法，用了一个visited来记录是否已经访问过
class Solution {
private:
    int height;
    int width;
public:
    bool exist(vector<vector<char> > &board, string word) {
        height = board.size();
        if(!height) return false;
        width = board[0].size();
        vector<vector<bool>> visited(height, vector<bool>(width, false));
        for(int i=0; i<height; i++){
            for(int j=0; j<width; j++){
                if(search(board, i, j, word, 0, visited)) {
                    return true;
                }
            }
        }
        return false;
    }
    
    bool search(vector<vector<char> > &board, int x, int y, string &word, int index, vector<vector<bool>> &visited){
        if(index == word.length()) return true;

        if(x<0 || y<0 || x>=height || 
           y>=width || visited[x][y] ||
           board[x][y] != word[index] ) return false;  
		
        visited[x][y] = true;
        if(search(board, x+1, y, word, index+1, visited) ||
           search(board, x-1, y, word, index+1, visited) ||
           search(board, x, y+1, word, index+1, visited) ||
           search(board, x, y-1, word, index+1, visited) ) return true;
		
        visited[x][y] = false;
        return false;
    }
};
--------------end--------------

------------ZigZag Conversion.cpp------------147
class Solution {
public:
    string convert(string s, int nRows) {
        vector<string> rows(nRows);
        string solution = "";
        int size = s.size(), cur = 0, dir = 0;
		//快速终止条件
        if(nRows == 1 || nRows > size) {
            return s;
        }
        for(int i=0; i<size; i++) {
            rows[cur]+=s[i];
            if(dir == 0){ //0代表向下，1代表向上
                cur++;
                if(cur == nRows-1) {
                    dir = 1; //反转
                }
            }
            else{
                cur--;
                if(cur == 0){
                    dir = 0; //反转
                }
            }
        }
        for(int j=0; j<nRows; j++) {
            solution += rows[j];
        }
        return solution;
    }
};
--------------end--------------
