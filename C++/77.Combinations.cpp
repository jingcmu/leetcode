/*
��һ�ַ�������STL�е�next_permutation����
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
		} while(prev_permutation(v.begin(), v.end())) ; //prev_permutation��ԭ�ز���
		return v_res;
	}
};

/*
�ڶ��ַ�����
λ���㣬��tricky��ʵҲ�첻�˶��٣�û��Ҫ����
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
�����ַ�����
�ݹ飬DFS����ʵ���Ʊ�������ѡ�Ͳ�ѡ����ѡ��
���������ѡ����k��Ԫ��
��ֹ��������
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
	// start����ʼ����, cur���Ѿ�ѡ�����Ŀ
	static void dfs(int n, int k, int start, int cur, vector<int> &path, vector<vector<int> > &result) {
		if (cur == k) {	//�������
			result.push_back(path);
		}
		for (int i = start; i <= n; ++i) { //��ʣ�µ�����Ԫ�ؽ���ѡ�Ͳ�ѡ�ĳ���
			path.push_back(i);
			dfs(n, k, i + 1, cur + 1, path, result);
			path.pop_back();
		}
	}
};