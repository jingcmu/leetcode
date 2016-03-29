class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        // 邻接图
        vector<vector<int>> graph(numCourses, vector<int>(0));
        // 入度
        vector<int> in(numCourses, 0), res;
        // 建立邻接图并获取所有节点入度
        for (auto p : prerequisites) {
            graph[p.second].push_back(p.first);
            ++in[p.first];
        }
        // 保存入度为0的节点
        queue<int> q;
        // 所有入度为0的节点入队列
        for (int i = 0; i < numCourses; ++i)
            if (in[i] == 0)
                q.push(i);
        // 循环删除入度为0的节点
        while (!q.empty()) {
            int x = q.front(); q.pop();
            res.push_back(x);
            for (auto i : graph[x]) {
                --in[i];
                if (in[i] == 0)
                    q.push(i);
            }
        }
        // 如果最后仍有入度不为0的节点，则排序失败
        if (res.size() != numCourses)
            res.clear();
        return res;
    }
};
