/**
拓扑排序的做法:
记录每个点的入度。
将入度为0的顶点加入队列。
依次对入度为0的点进行删边操作，同时将新得到的入度为零的点加入队列。
重复上述操作，直至队列为空。
*/
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

// DFS的做法：DFS+memorize 检测有没有环出现
class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<vector<int> > graph(numCourses, vector<int>(0));
        vector<int> visit(numCourses, 0);
        for (auto a : prerequisites) {
            graph[a.second].push_back(a.first);
        }
        // 对每个节点进行DFS看看有没有环
        for (int i = 0; i < numCourses; ++i) {
            if (visit[i]) continue;
            if (!canFinishDFS(graph, visit, i)) return false;
        }
        return true;
    }
    // 仔细看下面的DFS是如何检测有没有环出现的
    bool canFinishDFS(vector<vector<int> > &graph, vector<int> &visit, int i) {
        // 巧妙的地方在这：用-1作为开始访问，但是访问还没结束的状态
        // 如果节点i还在访问，又被访问了，则有环出现
        if (visit[i] == -1) return false;
        if (visit[i] == 1) return true;
        // 开始访问
        visit[i] = -1;
        for (auto a : graph[i]) {
            if (!canFinishDFS(graph, visit, a)) return false;
        }
        // 访问结束
        visit[i] = 1;
        return true;
    }
};
