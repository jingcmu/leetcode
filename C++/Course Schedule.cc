class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        // 邻接表图
        vector<vector<int>> graph(numCourses, vector<int>(0));
        vector<int> in(numCourses, 0); // 记录每个节点的入度
        // 建立关系图并记录各个节点的入度
        for (auto p : prerequisites) {
            graph[p.second].push_back(p.first);
            in[p.first]++;
        }
        queue<int> q; // 保存入度为0的节点
        for (int i = 0; i < numCourses; ++i) {
            if (in[i] == 0)
                q.push(i);
        }
        // 删除所有入度为0的节点，并把新的入度为0的节点放入队列，循环直到队列为空
        while (!q.empty()) {
            int i = q.front(); q.pop();
            for (auto g : graph[i]) {
                in[g]--;
                if (in[g] == 0)
                    q.push(g);
            }
        }
        // 如果满足拓扑排序，当前应该所有节点入度都为0，否则，排序失败
        for (auto i : in) {
            if (i) return false;
        }
        return true;
    }
};
