class Solution {
public:
    /**
     * @param A: Given an integers array A
     * @return: A long long array B and B[i]= A[0] * ... * A[i-1] * A[i+1] * ... * A[n-1]
     */
    vector<long long> productExcludeItself(vector<int> &nums) {
        if (nums.size() <= 0)
            return vector<long long>();
        vector<long long> res;
        long long prod = 1;
        res.push_back(prod);
        for (int i = 0; i < nums.size() - 1; i++) {
            prod *= nums[i];
            res.push_back(prod);
        }
        prod = 1;
        for (int i = static_cast<int>(nums.size()) - 1; i >= 0; i--) {
            res[i] *= prod;
            prod *= nums[i];
        }
        return res;
    }
};