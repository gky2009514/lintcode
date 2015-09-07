class Solution {
public:
    /**
     * @param path the original path
     * @return the simplified path
     */
    string simplifyPath(string& path) {
        deque<char> simp;
        for (int i = 0; i < path.length(); ) {
            int j = i;
            while (j < path.length() && path[j] == '/')
                j++;
            simp.push_back('/');
            if (j >= path.length())
                break;
            int k = j + 1;
            while (k < path.length() && path[k] != '/')
                k++;
            if (k - j == 1 && path[j] == '.') {
                simp.pop_back();
            } else if (k - j == 2 && path[j] == '.' && path[j + 1] == '.') {
                simp.pop_back();
                while (!simp.empty() && simp.back() != '/')
                    simp.pop_back();
                if (!simp.empty())
                    simp.pop_back();
            } else {
                for (int l = j; l < k; l++)
                    simp.push_back(path[l]);
            }
            i = k;
        }
        if (!simp.empty() && simp.back() == '/')
            simp.pop_back();
        if (simp.empty())
            simp.push_back('/');
        string res = "";
        while (!simp.empty()) {
            res += string(1, simp.front());
            simp.pop_front();
        }
        return res;
    }
};