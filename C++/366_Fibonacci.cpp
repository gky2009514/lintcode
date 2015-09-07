class Solution{
public:
    /**
     * @param n: an integer
     * @return an integer f(n)
     */
    int fibonacci(int n) {
        if (n <= 2)
            return n - 1;
        int a = 0, b = 1;
        for (int i = 3; i <= n; i++) {
            int c = a + b;
            a = b, b = c;
        }
        return b;
    }
};