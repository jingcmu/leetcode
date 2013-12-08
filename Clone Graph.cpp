/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
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