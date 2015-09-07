class Solution {
public:
    /**
     * @param node: A undirected graph node
     * @return: A undirected graph node
     */
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (node == NULL)
            return NULL;
        mp.clear();
        return dfs(node);
    }

private:
    map<UndirectedGraphNode*, UndirectedGraphNode*> mp;

    UndirectedGraphNode *dfs(UndirectedGraphNode *node) {
        mp[node] = new UndirectedGraphNode(node->label);
        for (int i = 0; i < node->neighbors.size(); i++) {
            if (node->neighbors[i] == NULL) {
                mp[node]->neighbors.push_back(NULL);
                continue;
            }
            if (mp.find(node->neighbors[i]) == mp.end())
                mp[node]->neighbors.push_back(dfs(node->neighbors[i]));
            else
                mp[node]->neighbors.push_back(mp[node->neighbors[i]]);
        }
        return mp[node];
    }
};