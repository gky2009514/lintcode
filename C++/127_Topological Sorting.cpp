class Solution {
public:
    /**
     * @param graph: A list of Directed graph node
     * @return: Any topological order for the given graph.
     */
    vector<DirectedGraphNode*> topSort(vector<DirectedGraphNode*> graph) {
        mp.clear();
        for (int i = 0; i < graph.size(); i++)
            mp[graph[i]] = false;
        while (!stk.empty())
            stk.pop();
        for (int i = 0; i < graph.size(); i++) {
            if (!mp[graph[i]])
                dfs(graph[i]);
        }
        vector<DirectedGraphNode*> topo;
        while (!stk.empty()) {
            topo.push_back(stk.top());
            stk.pop();
        }
        return topo;
    }

private:
    map<DirectedGraphNode*, bool> mp;
    stack<DirectedGraphNode*> stk;

    void dfs(DirectedGraphNode *node) {
        for (int i = 0; i < node->neighbors.size(); i++) {
            if (!mp[node->neighbors[i]])
                dfs(node->neighbors[i]);
        }
        mp[node] = true;
        stk.push(node);
    }
};