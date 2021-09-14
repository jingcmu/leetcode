// BFS拓扑排序解法
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

// DFS解法
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<vector<int> > graph(numCourses, vector<int>(0));
        vector<int> visit(numCourses, 0), res;
        for (auto a : prerequisites) {
            graph[a.second].push_back(a.first);
        }
        // 对每个节点进行DFS看看有没有环
        for (int i = 0; i < numCourses; ++i) {
            if (!canFinishDFS(graph, visit, i, res)) return vector<int>();
        }
        // 根据算法第4版P582：DAG的后序遍历的reverse是一个拓扑排序
        reverse(res.begin(), res.end());
        return res;
    }
    // 仔细看下面的DFS是如何检测有没有环出现的
    bool canFinishDFS(vector<vector<int> > &graph, vector<int> &visit, int i, vector<int> &res) {
        // 巧妙的地方在这：用-1作为开始访问，但是访问还没结束的状态
        // 如果节点i还在访问，又被访问了，则有环出现
        if (visit[i] == -1) return false;
        if (visit[i] == 1) return true;
        // 开始访问
        visit[i] = -1;
        for (auto a : graph[i]) {
            if (!canFinishDFS(graph, visit, a, res)) return false;
        }
        // 访问结束
        visit[i] = 1;
        res.push_back(i);
        //res.insert(res.begin(), i);
        return true;
    }
};
