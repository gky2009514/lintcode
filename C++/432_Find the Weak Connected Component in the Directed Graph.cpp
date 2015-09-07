class Solution {
public:
    /**
    * @param nodes a array of directed graph node
    * @return a connected set of a directed graph
    */
    vector<vector<int>> connectedSet2(vector<DirectedGraphNode*>& nodes) {
        if (nodes.size() == 0)
            return vector<vector<int> >();
        for (int i = 0; i < nodes.size(); i++) {
            for (int j = 0; j < nodes[i]->neighbors.size(); j++) {
                if (nodes[i]->neighbors[j] == nodes[i])
                    continue;
                nodes[i]->neighbors[j]->neighbors.push_back(nodes[i]);
            }
        }
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
    map<DirectedGraphNode*, bool> mp;
    vector<vector<int> > res;

    void dfs(DirectedGraphNode** node, vector<int> &nset) {
        nset.push_back((*node)->label);
        mp[*node] = true;
        for (int i = 0; i < (*node)->neighbors.size(); i++) {
            if (mp.find((*node)->neighbors[i]) == mp.end())
                dfs(&((*node)->neighbors[i]), nset);
        }
    }
};