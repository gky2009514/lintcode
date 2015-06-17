class Solution {
public:
    /**
     *@param num: A list of non negative integers
     *@return: A string
     */
    string largestNumber(vector<int> &num) {
        sort(num.begin(), num.end(), cmp);
        int up = static_cast<int>(num.size() - 1);
        while (up >= 0 && num[up] == 0)
            up--;
        if (up < 0)
            return "0";
        stringstream ss;
        for (int i = 0; i < num.size(); i++)
            ss << num[i];
        string res;
        ss >> res;
        return res;
    }

private:
    static bool cmp(const int &a, const int &b) {
        long long ta = a, ba = 1;
        do {
            ba *= 10;
            ta /= 10;
        } while (ta);
        long long tb = b, bb = 1;
        do {
            bb *= 10;
            tb /= 10;
        } while (tb);
        return (long long)a * bb + b > (long long)b * ba + a;
    }
};