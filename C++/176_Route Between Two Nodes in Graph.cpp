class Solution {
public:
    /**
     * @param graph: A list of Directed graph node
     * @param s: the starting Directed graph node
     * @param t: the terminal Directed graph node
     * @return: a boolean value
     */
    bool hasRoute(vector<DirectedGraphNode*> graph,
                  DirectedGraphNode* s, DirectedGraphNode* t) {
        mp.clear();
        for (int i = 0; i < graph.size(); i++)
            mp[graph[i]] = false;
        this->s = s, this->t = t;
        return dfs(s);
    }

private:
    DirectedGraphNode *s, *t;
    map<DirectedGraphNode*, bool> mp;
    bool dfs(DirectedGraphNode *&p) {
        if (p == t)
            return true;
        if (mp.find(p) == mp.end())
            return false;
        mp[p] = true;
        for (int i = 0; i < p->neighbors.size(); i++) {
            if (!mp[p->neighbors[i]] && dfs(p->neighbors[i]))
                return true;
        }
        return false;
    }
};