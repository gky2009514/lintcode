class Solution {
public:
    /**
    * @param A an integer array
    * @return  A list of integers includes the index of
    *          the first number and the index of the last number
    */
    vector<int> continuousSubarraySum(vector<int>& A) {
        int sum = 0, ma = INT_MIN;
        int index = 0, st, ed;
        for (int i = 0; i < A.size(); i++) {
            sum += A[i];
            if (sum > ma) {
                ma = sum;
                st = index, ed = i;
            }
            if (sum < 0) {
                sum = 0;
                index = i + 1;
            }
        }
        vector<int> res;
        res.push_back(st), res.push_back(ed);
        return res;
    }
};