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