class Solution {
public:
    /**
     * This method will be invoked first, you should design your own algorithm
     * to serialize a binary tree which denote by a root node to a string which
     * can be easily deserialized by your own "deserialize" method later.
     */
    string serialize(TreeNode *root) {
        queue<TreeNode*> q;
        q.push(root);
        stringstream ss("");
        while (!q.empty()) {
            TreeNode *t = q.front();
            q.pop();
            if (t == NULL) {
                ss << "#,";
            } else {
                ss << t->val << ",";
                q.push(t->left);
                q.push(t->right);
            }
        }
        string res;
        ss >> res;
        int end = static_cast<int>(res.length()) - 1;
        while (end >= 1 && res[end] == ',' && res[end - 1] == '#')
            end -= 2;
        return res.substr(0, end + 1);
    }
    
    /**
     * This method will be invoked second, the argument data is what exactly
     * you serialized at method "serialize", that means the data is not given by
     * system, it's given by your own serialize method. So the format of data is
     * designed by yourself, and deserialize it here as you serialize it in
     * "serialize" method.
     */
    TreeNode *deserialize(string data) {
        if (data.length() == 0)
            return NULL;
        queue<TreeNode*> q;
        int pos = static_cast<int>(data.find(',', 0));
        TreeNode *root = new TreeNode(atoi(data.substr(0, pos).c_str()));
        q.push(root);
        int pre = pos + 1;
        bool lflag = false;
        while (pre < data.length()) {
            pos = static_cast<int>(data.find(',', pre));
            TreeNode *now;
            if (data[pre] == '#')
                now = NULL;
            else
                now = new TreeNode(atoi(data.substr(pre, pos - pre).c_str()));
            TreeNode *t = q.front();
            while (t == NULL) {
                q.pop();
                t = q.front();
            }
            if (!lflag) {
                t->left = now;
                lflag = true;
            } else {
                t->right = now;
                lflag = false;
                q.pop();
            }
            q.push(now);
            pre = pos + 1;
        }        return root;
    }
};