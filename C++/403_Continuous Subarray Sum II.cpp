class Solution {
public:
    /**
    * @param A an integer array
    * @return  A list of integers includes the index of
    *          the first number and the index of the last number
    */
    vector<int> continuousSubarraySumII(vector<int>& A) {
        int sum = 0, ma = INT_MIN;
        int index = 0, ast, aed;
        for (int i = 0; i < A.size(); i++) {
            sum += A[i];
            if (sum > ma) {
                ma = sum;
                ast = index, aed = i;
            }
            if (sum < 0) {
                sum = 0;
                index = i + 1;
            }
        }
        int mi = INT_MAX, ist, ied;
        sum = index = 0;
        for (int i = 0; i < A.size(); i++) {
            sum += A[i];
            if (sum < mi) {
                mi = sum;
                ist = index, ied = i;
            }
            if (sum > 0) {
                sum = 0;
                index = i + 1;
            }
        }
        vector<int> res;
        long long total = 0;
        int n = static_cast<int>(A.size());
        for (int i = 0; i < n; i++)
            total += A[i];
        if (total == mi || total - mi <= ma) {
            res.push_back(ast);
            res.push_back(aed);
        } else {
            res.push_back((ied + 1) % n);
            res.push_back((ist - 1 + n) % n);
        }
        return res;
    }
};