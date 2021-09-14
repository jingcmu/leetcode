My solution:
//��̬�滮+��������
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
//˼·���ǣ�m n�����������Ǵ�m-1 n�����ģ�Ҳ�����Ǵ�m n-1������
class Solution {
public:
	int uniquePaths(int m, int n) {
		if (m < 1 || n < 1) return 0; // ��ֹ����
		if (m == 1 && n == 1) return 1; // ��������
		return uniquePaths(m - 1, n) + uniquePaths(m, n - 1);
	}
};

//��ν�ı���¼������ʵ���������ǰҲ�ù���ֻ�ǲ�֪�����������
class Solution {
public:
	int uniquePaths(int m, int n) {
		// 0 �к�0 ��δʹ��
		this->f = vector<vector<int> >(m + 1, vector<int>(n + 1, 0));
		return dfs(m, n);
	}
private:
	vector<vector<int> > f; // ����
	int dfs(int x, int y) {
		if (x < 1 || y < 1) return 0; // ���ݷǷ�����ֹ����
		if (x == 1 && y == 1) return 1; // �ص���㣬��������
		return getOrUpdate(x - 1, y) + getOrUpdate(x, y - 1);
	}
	//������������þ��ǿ��ܲ��ܲ��õ������û�еĲŵݹ�
	int getOrUpdate(int x, int y) {
		if (f[x][y] > 0) return f[x][y];
		else return f[x][y] = dfs(x, y);
	}
};

//my DFS
class Solution {
public:
    int uniquePaths(int m, int n) {
        w = m;
        h = n;
        f.resize(h+1);
        for(int i=0; i<=h; i++) {
            f[i].resize(w+1);
        }
        return dfs(1, 1);
    }
private:
    int dfs(int x, int y) {
        if(x > w || y > h) return 0;
        if(x == w && y == h) {
            return 1;
        }
        if(f[y][x]) return f[y][x];
        else {
            f[y][x] = dfs(x+1, y) + dfs(x, y+1);
            return f[y][x];
        }
    }
    int w, h;
    vector<vector<int>> f;
};