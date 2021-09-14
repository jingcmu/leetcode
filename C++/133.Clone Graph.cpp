/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
/*
����ֻ�ܿ�¡��ͨͼ����Ȼ��
��������һ���㿪ʼ��¡��Ȼ��ʼneighbor�Ŀ�¡����һ��map��¼visited�������ظ�����
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

//a little improvement
/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if(node == NULL) {
            return NULL;
        }
        UndirectedGraphNode *new_node = new UndirectedGraphNode(node->label);
        m[node] = new_node;
        for(auto v: node->neighbors) {
            if(m.find(v) != m.end()) new_node->neighbors.push_back(m[v]);
            else new_node->neighbors.push_back(cloneGraph(v));
        }
        return new_node;
    }
private:
    unordered_map<UndirectedGraphNode *, UndirectedGraphNode *> m;
};


//use label as key to revise
/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if(node == NULL) return NULL;
        UndirectedGraphNode *new_node = new UndirectedGraphNode(node->label);
        m[node->label] = new_node;
        for(auto v: node->neighbors) {
            if(m.find(v->label) != m.end()) {
                new_node->neighbors.push_back(m[v->label]);
                continue;
            }
            new_node->neighbors.push_back(cloneGraph(v));
        }
        return new_node;
    }
private:
    unordered_map<int, UndirectedGraphNode*> m;
};
