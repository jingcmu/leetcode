class Solution {
public:
    string alienOrder(vector<string>& words) {
        if (words.size() == 1) return words.front();
        unordered_map<char, unordered_set<char>> g;
        for (int i = 1; i < words.size(); i++) {
            string k1 = words[i - 1];
            string k2 = words[i];           
            bool found = false;
            // 建图，这一步不要去管入度，对每个遇到的字符，先建立空表
            for (int j = 0; j < max(k1.length(), k2.length()); j++) {
                if (j < k1.length() && g.count(k1[j]) == 0)
                    g.insert(make_pair(k1[j], unordered_set<char>()));
                if (j < k2.length() && g.count(k2[j]) == 0)
                    g.insert(make_pair(k2[j], unordered_set<char>()));
                if (j < k1.length() && j < k2.length() && k1[j] != k2[j] && !found) {
                    g[k1[j]].insert(k2[j]);
                    // 已经找到就停止插入图，但是图中还是要建立空节点
                    found = true;
                }
            }
        }
        // 拓扑排序
        return topsort(g);
    }

    string topsort(unordered_map<char, unordered_set<char>>& g) {
        unordered_set<char> visited;
        unordered_set<char> visiting;
        string order;
        for (auto iter = g.begin(); iter != g.end(); ++iter) {
            // 从每个节点开始访问，看看有没有环
            if (dfs(g, visited, visiting, order, iter->first) == false)
                return "";
        }
        // DAG的后序遍历的逆是一个拓扑排序
        reverse(order.begin(), order.end());
        return order;
    }
    
     bool dfs(unordered_map<char, unordered_set<char>>& g, unordered_set<char>& visited,
             unordered_set<char>& visiting, string& order, char c) {
        if (visiting.count(c)) return false; // 之前的访问还没结束
        if (visited.count(c)) return true;
        visited.insert(c);
        visiting.insert(c);
        // 从当前节点出发访问后序所有节点
        for (auto iter = g[c].begin(); iter != g[c].end(); ++iter)
            if (dfs(g, visited, visiting, order, *iter) == false)
                return false;
    
        visiting.erase(c);
        // 后序遍历
        order += c;
        return true;
    }

};
