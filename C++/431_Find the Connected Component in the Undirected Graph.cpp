class Solution {
public:
    /**
    * @param nodes a array of Undirected graph node
    * @return a connected set of a Undirected graph
    */
    vector<vector<int>> connectedSet(vector<UndirectedGraphNode*>& nodes) {
        mp.clear();
        res.clear();
        vector<int> nset;
        for (int i = 0; i < nodes.size(); i++) {
            if (mp.find(nodes[i]) == mp.end()) {
                nset.clear();
                dfs(&nodes[i], nset);
                res.push_back(nset);
            }
        }
        for (int i = 0; i < res.size(); i++)
            sort(res[i].begin(), res[i].end());
        return res;
    }

private:
    map<UndirectedGraphNode*, bool> mp;
    vector<vector<int> > res;

    void dfs(UndirectedGraphNode** node, vector<int> &nset) {
        nset.push_back((*node)->label);
        mp[*node] = true;
        for (int i = 0; i < (*node)->neighbors.size(); i++) {
            if (mp.find((*node)->neighbors[i]) == mp.end())
                dfs(&(*node)->neighbors[i], nset);
        }
    }
};