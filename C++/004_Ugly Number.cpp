class Solution {
public:
    /*
     * @param k: The number k.
     * @return: The kth prime number as description.
     */
    Solution() {
        q3.push(3);
        q5.push(5);
        q7.push(7);
        int num = 0;
        while (num < N) {
            long long f3 = q3.front();
            long long f5 = q5.front();
            long long f7 = q7.front();
            if (f3 < f5 && f3 < f7) {
                ugly[num++] = f3;
                q3.pop();
                q3.push(f3 * 3);
                q5.push(f3 * 5);
                q7.push(f3 * 7);
            } else if (f5 < f7) {
                ugly[num++] = f5;
                q5.pop();
                q5.push(f5 * 5);
                q7.push(f5 * 7);
            } else {
                ugly[num++] = f7;
                q7.pop();
                q7.push(f7 * 7);
            }
        }
    }

    long long kthPrimeNumber(int k) {
        return ugly[k - 1];
    }

private:
    static const int N = 5000;
    long long ugly[N];
    queue<long long> q3, q5, q7;
};